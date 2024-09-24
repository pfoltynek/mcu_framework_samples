#ifndef MCU_FW_ESP32_DISPLAYMODULE_H
#define MCU_FW_ESP32_DISPLAYMODULE_H

#include <framework.h>
#include "services/services.h"
#include "events/events.h"

#ifdef DEVICE
#include "modules/DisplayModule/sensors/DisplayView/device/DisplayView.h"
#elif NATIVE
#include "modules/DisplayModule/sensors/DisplayView/native/DisplayView.h"
#endif

class DisplayModule : public Module{
    public:
        DisplayModule();
        void setup() override;
        void loop() override;
        ~DisplayModule() override;
    protected:
        void registerModuleSensors() override;
        void handle_DHTDataEvent(IEvent* event);
    private:
        ILoggerService* loggerService;
        unsigned int dhtEventsId = -1;
};


#endif //MCU_FW_ESP32_DISPLAYMODULE_H
