#ifndef SAMPLES_2_REALTIMECLOCKMODULE_H
#define SAMPLES_2_REALTIMECLOCKMODULE_H

#include <framework.h>
#include "services/services.h"
#include "events/events.h"

#ifdef DEVICE
#include "modules/RealTimeClockModule/sensors/RealTimeClockView/device/RealTimeClockView.h"
#elif NATIVE
#endif

class RealTimeClockModule : public Module{
    public:
        RealTimeClockModule();
        void setup() override;
        void loop() override;
        ~RealTimeClockModule() override;
    protected:
        void registerModuleSensors() override;
    private:
        ILoggerService* loggerService;
        void loopProcessing();
        unsigned long lastLoopProcessingTime = 0;
};

#endif //SAMPLES_2_REALTIMECLOCKMODULE_H
