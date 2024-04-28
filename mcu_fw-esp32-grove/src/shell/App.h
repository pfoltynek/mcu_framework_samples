#ifndef ESP32_FW_SAMPLE1_APP_H
#define ESP32_FW_SAMPLE1_APP_H

#include <framework.h>
#include "services/services.h"
#include "modules/modules.h"

class App : public Shell{
public:
    void setup() override;
    void loop() override;
    ~App() = default;
protected:
    void registerAppModules() override;
    void registerAppCoreServices() override;
};


#endif //ESP32_FW_SAMPLE1_APP_H
