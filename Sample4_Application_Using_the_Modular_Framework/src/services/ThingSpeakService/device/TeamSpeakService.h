#ifndef SAMPLES_2_TEAMSPEAKSERVICE_H
#define SAMPLES_2_TEAMSPEAKSERVICE_H

#ifdef DEVICE

#include "IThingSpeakService.h"
#include "services/services.h"
#include "events/events.h"
#include <framework.h>
#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>

class TeamSpeakService : public IThingSpeakService {
    public:
        TeamSpeakService();
        void init(const char* ssid, const char* password, const char* channel_id,const char* write_api_key) override;
        ~TeamSpeakService() override;
    private:
        ILoggerService* loggerService;
        void wifiConnectStatus();

        void handle_DataEvent(IEvent* event);
        unsigned long convertToUnsignedLong(const char* str);

        char wifi_ssid[40];
        char wifi_password[40];
        char ts_write_api_key[40];
        unsigned long ts_channel_id;

        WiFiClient  client;

        unsigned int dataEventsId = -1;

        int publicEventCounter = 0;
};

#endif

#endif //SAMPLES_2_TEAMSPEAKSERVICE_H
