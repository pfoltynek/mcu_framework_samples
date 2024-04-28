#ifndef MCU_FW_ESP32_DISPLAYVIEW_H
#define MCU_FW_ESP32_DISPLAYVIEW_H

#ifdef DEVICE

#include "modules/DisplayModule/sensors/DisplayView/IDisplayView.h"
#include <U8g2lib.h>

class DisplayView : public IDisplayView {
public:
    DisplayView();
    void showWelcomeText(const char* text) override;
    void showSensorData(float temperatureData, float humidityData) override;
    ~DisplayView() override;
private:
    ILoggerService* loggerService;
    U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2 = U8G2_SSD1306_128X64_NONAME_1_HW_I2C(U8G2_R0, U8X8_PIN_NONE);

    //header
    String headerText = "";
    bool headerTextChanged = false;
    void updateHeaderPart(const char* newText);

    //data
    float temperature = -1000;
    float humidity = -1000;
    bool sensorDataChanged = false;
    void updateSensorDataPart(float temperatureNew, float humidityNew);

    //decimal precision
    int decimalPrecision = 1;

    //refresh
    void refresh();
};

#endif


#endif //MCU_FW_ESP32_DISPLAYVIEW_H
