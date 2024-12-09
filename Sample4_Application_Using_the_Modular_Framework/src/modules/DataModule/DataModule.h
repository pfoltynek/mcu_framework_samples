#ifndef SAMPLES_2_DATAMODULE_H
#define SAMPLES_2_DATAMODULE_H

#include <framework.h>
#include "services/services.h"
#include "events/events.h"

#ifdef DEVICE
#include "modules/DataModule/sensors/BME280View/device/BME280View.h"
#include "modules/DataModule/sensors/SCD41View/device/SCD41View.h"
#elif NATIVE

#endif

class DataModule : public Module{
    public:
        DataModule();
        void setup() override;
        void loop() override;
        ~DataModule() override;
    protected:
        void registerModuleSensors() override;
    private:
        ILoggerService* loggerService;
        void loopProcessing();
        unsigned long lastLoopProcessingTime = 0;
};


#endif //SAMPLES_2_DATAMODULE_H
