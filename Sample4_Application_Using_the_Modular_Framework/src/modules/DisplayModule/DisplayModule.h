#ifndef ESP32_FW_SAMPLE2_DISPLAYMODULE_H
#define ESP32_FW_SAMPLE2_DISPLAYMODULE_H

#include <framework.h>
#include "services/services.h"
#include "events/events.h"

#ifdef DEVICE
#include "modules/DisplayModule/sensors/DisplayView/device/DisplayView.h"
#elif NATIVE

#endif

class DisplayModule : public Module{
    public:
        DisplayModule();
        void setup() override;
        void loop() override;
        ~DisplayModule() override;
    protected:
        void registerModuleSensors() override;
        void handle_TimeEvent(IEvent* event);
        void handle_DataEvent(IEvent* event);
        void handle_WifiOnConnect(IEvent* event);
        void handle_WifiOnDisconnect(IEvent* event);
    private:
        ILoggerService* loggerService;
        unsigned int dataEventsId = -1;
        unsigned int timeEventsId = -1;
        unsigned int wifiConnectEventsId = -1;
        unsigned int wifiDisconnectEventsId = -1;
};


#endif //ESP32_FW_SAMPLE2_DISPLAYMODULE_H
