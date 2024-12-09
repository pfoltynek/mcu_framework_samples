#include "DataModule.h"

DataModule::DataModule() {
    loggerService = (ILoggerService *) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logDebug("DataModule::DataModule()");
}

void DataModule::setup() {
    Module::setup();

    loggerService->logDebug("DataModule::setup()");

    delay(5000);
}

void DataModule::loop() {
    Module::loop();

    loggerService->logDebug("DataModule::loop()");

    unsigned long currentMillis = millis();
    if (currentMillis - lastLoopProcessingTime >= 5000) {   // pokud uplynuly 5 sekundy
        loopProcessing();                                   // spustíme loopProcessing
        lastLoopProcessingTime = currentMillis;             // a aktualizujeme čas posledního spuštění
    }
}

DataModule::~DataModule() {
    loggerService->logDebug("DataModule::~DataModule()");
    delete loggerService;
}

void DataModule::registerModuleSensors() {
    registerSensor(IBME280View::getName(), new BME280View());
    registerSensor(ISCD41View::getName(), new SCD41View());
}

void DataModule::loopProcessing() {
    loggerService->logDebug("DataModule::loopProcessing()");
    ISCD41View *scd41Sensor = (ISCD41View *) getSensor(ISCD41View::getName());
    SCD41Data data = scd41Sensor->getData();

    loggerService->logInfo(("DataModule::loop() - CO2: " + String(data.co2) +"ppm").c_str());
    loggerService->logInfo(("DataModule::loop() - Temperature: " + String(data.temperature) + "C").c_str());
    loggerService->logInfo(("DataModule::loop() - Humidity: " + String(data.humidity) + "%").c_str());

    IBME280View *bme280Sensor = (IBME280View *) getSensor(IBME280View::getName());
    BME280Data data2 = bme280Sensor->getData();

    loggerService->logInfo(("DataModule::loop() - Temperature: " + String(data2.temperature) + "C").c_str());
    loggerService->logInfo(("DataModule::loop() - Pressure: " + String(data2.pressure) + "hPa").c_str());
    loggerService->logInfo(("DataModule::loop() - Humidity: " + String(data2.humidity) + "%").c_str());

    loggerService->logDebug("DataModule::loop() - Publishing DataEvent");
    EventService::getInstance().publish(DataEvent::getName(), new DataEvent(data2.temperature,data2.humidity, data2.pressure, data.co2));
}
