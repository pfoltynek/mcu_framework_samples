#ifndef ESP32_FW_SAMPLE1_TEMPHUMIVIEW_H
#define ESP32_FW_SAMPLE1_TEMPHUMIVIEW_H

#if DEVICE

#include "../../ITempHumiView.h"
#include <freertos/FreeRTOS.h>
#include <dht.h>

//#define DHTPIN 4 - updated from build flags

class TempHumiView : public ITempHumiView{
    public:
        explicit TempHumiView();
        DHTData getData() override;
        ~TempHumiView() override;
    private:
        ILoggerService *loggerService;
};

#endif

#endif //ESP32_FW_SAMPLE1_TEMPHUMIVIEW_H