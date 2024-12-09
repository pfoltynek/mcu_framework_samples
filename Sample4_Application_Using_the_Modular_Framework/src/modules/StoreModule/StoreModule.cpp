#include "StoreModule.h"

StoreModule::StoreModule() {
    loggerService = (ILoggerService*)ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logDebug("StoreModule::StoreModule()");
}

void StoreModule::setup() {
    Module::setup();
    loggerService->logDebug("StoreModule::setup()");

    ICardView* cardView = (ICardView*) getSensor(ICardView::getName());
    AppSettings settings = cardView->getSettings();

    loggerService->logInfo(String("setting.wifi.wifi_ssid: " + String(settings.wifi.ssid)).c_str());
    loggerService->logInfo(String("setting.wifi.wifi_password: " + String(settings.wifi.password)).c_str());
    loggerService->logInfo(String("setting.thingSpeak.ts_channel_id: " + String(settings.thingSpeak.channel_id)).c_str());
    loggerService->logInfo(String("setting.thingSpeak.ts_write_api_key: " + String(settings.thingSpeak.write_api_key)).c_str());
    loggerService->logInfo(String("setting.initFromFile: " + String(settings.initFromFile)).c_str());

    if(settings.initFromFile) {
        loggerService->logDebug("setting.initFromFile is true");
        IThingSpeakService* teamSpeakService = (IThingSpeakService*)ServiceLocator::getInstance().getService(IThingSpeakService::getName());
        teamSpeakService->init(settings.wifi.ssid,
                               settings.wifi.password,
                               settings.thingSpeak.channel_id,
                               settings.thingSpeak.write_api_key);
    }
}

void StoreModule::loop() {
    Module::loop();

    loggerService->logDebug("StoreModule::loop()");
}

StoreModule::~StoreModule() {
    loggerService->logDebug("StoreModule::~StoreModule()");
    delete loggerService;
}

void StoreModule::registerModuleSensors() {
    registerSensor(ICardView::getName(), new CardView());
}