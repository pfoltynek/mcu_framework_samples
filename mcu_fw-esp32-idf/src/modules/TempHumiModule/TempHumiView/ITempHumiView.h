#ifndef ESP32_FW_SAMPLE1_ITEMPHUMIVIEW_H
#define ESP32_FW_SAMPLE1_ITEMPHUMIVIEW_H

#include "framework.h"

struct DHTData {
    float humidity;
    float temperature;
};

class ITempHumiView :public ISensorName<ITempHumiView>{
public:
    virtual DHTData getData() = 0;
    ~ITempHumiView() override = default;

    static const char* getSensorName() {
        return "ITempHumiView";
    }
};

#endif //ESP32_FW_SAMPLE1_ITEMPHUMIVIEW_H
