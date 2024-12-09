#ifndef ESP32_FW_SAMPLE2_DISPLAYVIEW_H
#define ESP32_FW_SAMPLE2_DISPLAYVIEW_H

#ifdef DEVICE

#include "modules/DisplayModule/sensors/DisplayView/IDisplayView.h"
#include <arduino.h>
#include <U8g2lib.h>

class DisplayView : public IDisplayView {
public:
    DisplayView();
    void showWelcomeText(const char* text) override;
    void showTimeText(const char* text) override;
    void showDataText(Data dataEvent) override;
    void showWifiStatusText(bool status) override;
    ~DisplayView() override;

private:
    ILoggerService* loggerService;
    U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2 = U8G2_SH1106_128X64_NONAME_1_HW_I2C(U8G2_R0, U8X8_PIN_NONE);

    //decimal precision
    int decimalPrecision = 1;

    String welcomeText = "";
    String timeText = "";
    Data data = {-1000, -1000, -1000, 0};
    bool dataDefault = true;
    bool wifiStatus = false;

    //refresh
    void refresh();
    bool updateTimeText(const char *text);
    bool updateDataText(Data dataNew);
    bool updateWifiStatus(bool statusNew);
};

#endif

#endif //ESP32_FW_SAMPLE2_DISPLAYVIEW_H
