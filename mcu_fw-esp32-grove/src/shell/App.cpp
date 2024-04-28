#include "App.h"

void App::registerAppCoreServices() {
    registerService(ILoggerService::getName(), new LoggerService());
}

void App::registerAppModules() {
    registerModule(new DisplayModule());
    registerModule(new TempHumiModule());
}

void App::setup() {
    Shell::setup();

    ILoggerService* logger = (ILoggerService*)ServiceLocator::getInstance().getService(ILoggerService::getName());
    logger->logInfo("setup()");
}

void App::loop() {
    Shell::loop();

    ILoggerService* logger = (ILoggerService*)ServiceLocator::getInstance().getService(ILoggerService::getName());
    logger->logInfo("loop()");
}