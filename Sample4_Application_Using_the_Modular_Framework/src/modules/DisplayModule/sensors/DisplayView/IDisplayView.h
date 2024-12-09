#ifndef ESP32_FW_SAMPLE2_IDISPLAYVIEW_H
#define ESP32_FW_SAMPLE2_IDISPLAYVIEW_H

#include <framework.h>
#include "events/events.h"

struct Data {
    float temperature = -1000;
    float humidity = -1000;
    float pressure = -1000;
    uint16_t co2 = 0;
};

class IDisplayView :public ISensorName<IDisplayView>{
    public:
        virtual void showWelcomeText(const char* text) = 0;
        virtual void showTimeText(const char* text) = 0;
        virtual void showDataText(Data data) = 0;
        virtual void showWifiStatusText(bool status) = 0;
        ~IDisplayView() override = default;

        static const char* getSensorName() {
            return "IDisplayView";
        }
};

#endif //ESP32_FW_SAMPLE2_IDISPLAYVIEW_H
