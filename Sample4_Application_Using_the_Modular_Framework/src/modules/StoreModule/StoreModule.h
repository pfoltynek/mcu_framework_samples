#ifndef SAMPLES_2_STOREMODULE_H
#define SAMPLES_2_STOREMODULE_H

#include <framework.h>
#include "services/services.h"
#include "events/events.h"

#ifdef DEVICE
#include "modules/StoreModule/sensors/CardView/device/CardView.h"
#elif NATIVE
#endif

class StoreModule : public Module{
    public:
        StoreModule();
        void setup() override;
        void loop() override;
        ~StoreModule() override;
    protected:
        void registerModuleSensors() override;
    private:
        ILoggerService* loggerService;
};

#endif //SAMPLES_2_STOREMODULE_H
