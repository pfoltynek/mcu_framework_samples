#ifndef ESP32_FW_SAMPLE1_TEMPHUMIVIEW_H
#define ESP32_FW_SAMPLE1_TEMPHUMIVIEW_H

#if DEVICE

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11
//#define DHTPIN 4 - updated from build flags

#include "../../ITempHumiView.h"

class TempHumiView : public ITempHumiView{
    public:
        explicit TempHumiView();
        DHTData getData() override;
        ~TempHumiView() override;
    private:
        ILoggerService *loggerService;
        DHT_Unified dht = DHT_Unified(DHTPIN, DHTTYPE);
};

#endif

#endif //ESP32_FW_SAMPLE1_TEMPHUMIVIEW_H
