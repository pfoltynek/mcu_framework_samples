#ifndef ESP32_FW_SAMPLE1_TEMPHUMIMODULE_H
#define ESP32_FW_SAMPLE1_TEMPHUMIMODULE_H

#include <framework.h>
#include "events/events.h"
#include "services/services.h"

#if DEVICE
#include "TempHumiView/sensors/device/TempHumiView.h"
#elif NATIVE
#include "TempHumiView/sensors/native/TempHumiView.h"
#endif

class TempHumiModule : public Module{
public:
    explicit TempHumiModule();
    void setup() override;
    void loop() override;
    ~TempHumiModule() override;
protected:
    void registerModuleSensors() override;
    ILoggerService *loggerService;
};


#endif //ESP32_FW_SAMPLE1_TEMPHUMIMODULE_H
