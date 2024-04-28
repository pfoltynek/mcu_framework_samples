#ifndef ESP32_FW_SAMPLE1_IDISPLAYVIEW_H
#define ESP32_FW_SAMPLE1_IDISPLAYVIEW_H

#include "framework.h"

class IDisplayView :public ISensorName<IDisplayView>{
    public:
        virtual void showWelcomeText(const char* text) = 0;
        virtual void showSensorData(float temperature, float humidity) = 0;
        ~IDisplayView() override = default;

        static const char* getSensorName() {
            return "IDisplayView";
        }
};

#endif //ESP32_FW_SAMPLE1_IDISPLAYVIEW_H
