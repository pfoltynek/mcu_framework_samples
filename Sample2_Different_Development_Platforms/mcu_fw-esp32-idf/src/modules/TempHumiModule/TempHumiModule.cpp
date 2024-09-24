#include "TempHumiModule.h"
#include <string>

TempHumiModule::TempHumiModule() {
    loggerService = (ILoggerService*) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logInfo("TempHumiModule::TempHumiModule()");
}

void TempHumiModule::setup() {
    Module::setup();
}

void TempHumiModule::loop() {
    Module::loop();

    loggerService->log("TempHumiModule::loop()");

    ITempHumiView* tempHumiSensor = (ITempHumiView*) getSensor(ITempHumiView::getName());
    DHTData data = tempHumiSensor->getData();

    loggerService->logInfo(("TempHumiModule::loop() - Temperature: " + std::to_string(data.temperature)).c_str());
    loggerService->logInfo(("TempHumiModule::loop() - Humidity: " + std::to_string(data.humidity)).c_str());

    loggerService->logInfo("TempHumiModule::loop() - Publishing DHTDataEvent");
    EventService::getInstance().publish(DHTDataEvent::getName(), new DHTDataEvent(data.temperature, data.humidity));
}

void TempHumiModule::registerModuleSensors() {
    registerSensor(ITempHumiView::getName(), new TempHumiView());
}

TempHumiModule::~TempHumiModule() {
    loggerService->logInfo("TempHumiModule::~TempHumiModule()");
    delete loggerService;
}
