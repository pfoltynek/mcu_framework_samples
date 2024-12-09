#include "RealTimeClockModule.h"

RealTimeClockModule::RealTimeClockModule() {
    loggerService = (ILoggerService *) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logDebug("RealTimeClockModule::RealTimeClockModule()");
}

void RealTimeClockModule::setup() {
    Module::setup();

    loggerService->logDebug("RealTimeClockModule::setup()");
}

void RealTimeClockModule::loop() {
    Module::loop();

    loggerService->logDebug("RealTimeClockModule::loop()");

    unsigned long currentMillis = millis();
    if (currentMillis - lastLoopProcessingTime >= 500) {    // pokud uplynuly 3 sekundy
        loopProcessing();                                   // spustíme loopProcessing
        lastLoopProcessingTime = currentMillis;             // a aktualizujeme čas posledního spuštění
    }
}

RealTimeClockModule::~RealTimeClockModule() {
    loggerService->logDebug("RealTimeClockModule::~RealTimeClockModule()");
    delete loggerService;
}

void RealTimeClockModule::registerModuleSensors() {
    registerSensor(IRealTimeClockView::getName(), new RealTimeClockView());
}

void RealTimeClockModule::loopProcessing() {
    loggerService->logDebug("RealTimeClockModule::loopProcessing()");
    IRealTimeClockView *realTimeClockSensor = (IRealTimeClockView *) getSensor(IRealTimeClockView::getName());
    Time time = realTimeClockSensor->getTime();

    char timeStr[9];
    sprintf(timeStr, "%02d:%02d:%02d", time.hour, time.min, time.sec);
    loggerService->logInfo(("RealTimeClockModule::loop() - Time: " + String(timeStr)).c_str());

    loggerService->logDebug("RealTimeClockModule::loop() - Publishing TimeEvent");
    EventService::getInstance().publish(TimeEvent::getName(), new TimeEvent(time.hour, time.min, time.sec));
}