#ifndef ESP32_FW_SAMPLE1_TEMPHUMIVIEW_H
#define ESP32_FW_SAMPLE1_TEMPHUMIVIEW_H

#if DEVICE

#include <Seeed_BME280.h>
#include "../../ITempHumiView.h"

class TempHumiView : public ITempHumiView{
    public:
        explicit TempHumiView();
        DHTData getData() override;
        ~TempHumiView() override;
    private:
        ILoggerService *loggerService;
        BME280 bme280 = BME280();
};

#endif

#endif //ESP32_FW_SAMPLE1_TEMPHUMIVIEW_H
