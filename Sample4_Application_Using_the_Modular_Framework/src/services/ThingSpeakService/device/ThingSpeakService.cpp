#include "TeamSpeakService.h"

#ifdef DEVICE

TeamSpeakService::TeamSpeakService() {
    loggerService = (ILoggerService*)ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logDebug("TeamSpeakService::TeamSpeakService()");

    EventService& event = EventService::getInstance();
    dataEventsId = event.subscribe(DataEvent::getName(), [this](IEvent* event){
        loggerService->logInfo("TeamSpeakService::DataEvent()");
        this->handle_DataEvent(event);
    });

    WiFi.mode(WIFI_STA);
    ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void TeamSpeakService::init(const char* ssid, const char* password, const char* channel_id, const char* write_api_key) {
    loggerService->logInfo(String("TeamSpeakService::init() - ssid = " + String(ssid) + " password = " + String(password) + " channel_id = " + String(channel_id) + " write_api_key = " + String(write_api_key)).c_str());

    strcpy(wifi_ssid, ssid);
    strcpy(wifi_password, password);
    strcpy(ts_write_api_key, write_api_key);
    ts_channel_id = convertToUnsignedLong(channel_id);

    loggerService->logInfo(("wifi_ssid: " + String(wifi_ssid)).c_str());
    loggerService->logInfo(("wifi_password: " + String(wifi_password)).c_str());
    loggerService->logInfo(("ts_write_api_key: " + String(ts_write_api_key)).c_str());
    loggerService->logInfo(("ts_channel_id: " + String(ts_channel_id)).c_str());

    wifiConnectStatus();
}

TeamSpeakService::~TeamSpeakService() {
    loggerService->logDebug("TeamSpeakService::~TeamSpeakService()");
    delete loggerService;
}

void TeamSpeakService::wifiConnectStatus() {
    loggerService->logDebug("TeamSpeakService::wifiConnectStatus()");
    EventService& event = EventService::getInstance();

    if(WiFi.status() == WL_CONNECTED) {
        loggerService->logInfo("TeamSpeakService::wifiConnectStatus() - WiFi is already connected");
        return;
    }

    WiFi.begin(wifi_ssid, wifi_password);
    bool disconnectPublished = false;
    while (WiFi.status() != WL_CONNECTED) {
        if (!disconnectPublished) {
            event.publish(WifiOnDisconnect::getName(), new WifiOnDisconnect());
            disconnectPublished = true;
        }
        delay(500);
        loggerService->logInfo("TeamSpeakService::wifiConnectStatus() - Connecting to WiFi..");
    }
    loggerService->logInfo("TeamSpeakService::wifiConnectStatus() - Connected to the WiFi network");
    event.publish(WifiOnConnect::getName(), new WifiOnConnect());
}

unsigned long TeamSpeakService::convertToUnsignedLong(const char* str) {
    char* end;
    unsigned long num = strtoul(str, &end, 10);
    if (*end) {
        loggerService->logError(String("TeamSpeakService::convertToUnsignedLong() - Error converting string to unsigned long, value '" + String(str) + "'").c_str());
    }
    return num;
}

void TeamSpeakService::handle_DataEvent(IEvent* event) {
    loggerService->logDebug("TeamSpeakService::handle_DataEvent()");

    publicEventCounter++;
    if(publicEventCounter < 6) {
        loggerService->logInfo(String("TeamSpeakService::handle_DataEvent() - publicEventCounter = " + String(publicEventCounter)).c_str());
        return;
    }

    if (auto *data = (DataEvent*) event) {
        loggerService->logInfo(String("TeamSpeakService::handle_DataEvent() - publicEventCounter = " + String(publicEventCounter)).c_str());
        wifiConnectStatus();

        ThingSpeak.setField(1, data->getTemperature());
        ThingSpeak.setField(2, data->getHumidity());
        ThingSpeak.setField(3, data->getPressure());
        ThingSpeak.setField(4, data->getCo2());

        loggerService->logInfo(("write_api_key: " + String(ts_write_api_key)).c_str());
        loggerService->logInfo(("channel_id: " + String(ts_channel_id)).c_str());

        int result = ThingSpeak.writeFields(ts_channel_id, ts_write_api_key);
        if(result == 200){
            loggerService->logInfo("TeamSpeakService::handle_DataEvent() - Channel update successful.");
        }
        else{
            loggerService->logError(String("TeamSpeakService::handle_DataEvent() - Problem updating channel. HTTP error code " + String(result)).c_str());
        }

        publicEventCounter = 0;
    }
};

#endif


