#include "BME280View.h"

#ifdef DEVICE

BME280View::BME280View() {
    loggerService = (ILoggerService *) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logDebug("BME280View::BME280View()");

    if (! bme.begin(BME280_ADDRESS)) {
        loggerService->logInfo("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        loggerService->logInfo(String("SensorID was: 0x" + String(bme.sensorID(), 16)).c_str());
        loggerService->logInfo("ID of 0xFF probably means a bad address, a BMP 180 or BMP 085");
        loggerService->logInfo("ID of 0x56-0x58 represents a BMP 280,");
        loggerService->logInfo("ID of 0x60 represents a BME 280.");
        loggerService->logInfo("ID of 0x61 represents a BME 680.");
        while (1) delay(10);
    }

    loggerService->logInfo("-- Weather Station Scenario --");
    loggerService->logInfo("forced mode, 1x temperature / 1x humidity / 1x pressure oversampling,");
    loggerService->logInfo("filter off");

    bme.setSampling(Adafruit_BME280::MODE_NORMAL,     //Operating Mode
                    Adafruit_BME280::SAMPLING_X8, // temperature
                    Adafruit_BME280::SAMPLING_X8, // pressure
                    Adafruit_BME280::SAMPLING_X8, // humidity
                    Adafruit_BME280::FILTER_X4   );

    delay(250);
}

BME280View::~BME280View() {
    loggerService->logDebug("BME280View::~BME280View()");
    delete loggerService;
}

BME280Data BME280View::getData() {
    loggerService->logDebug("BME280View::getData()");

    BME280Data data = BME280Data();

    data.temperature = bme.readTemperature();
    data.pressure = bme.readPressure() / 100.0F;
    data.humidity = bme.readHumidity();

    return data;
}

#endif