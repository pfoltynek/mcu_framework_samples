#include "App.h"

void App::registerAppCoreServices() {
    registerService(ILoggerService::getName(), new LoggerService());
    registerService(IThingSpeakService::getName(), new TeamSpeakService());
}

void App::registerAppModules() {
    registerModule(new DisplayModule());
    registerModule(new StoreModule());
    registerModule(new RealTimeClockModule());
    registerModule(new DataModule());
}

void App::setup() {
    Shell::setup();

    ILoggerService* logger = (ILoggerService*)ServiceLocator::getInstance().getService(ILoggerService::getName());
    logger->logDebug("setup()");
}

void App::loop() {
    Shell::loop();

    ILoggerService* logger = (ILoggerService*)ServiceLocator::getInstance().getService(ILoggerService::getName());
    logger->logDebug("loop()");
}