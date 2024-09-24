#ifndef MCU_FW_ESP32_DISPLAYVIEW_H
#define MCU_FW_ESP32_DISPLAYVIEW_H

#ifdef DEVICE

#include "modules/DisplayModule/sensors/DisplayView/IDisplayView.h"
#include <string>
#include <cstring>
#include <ssd1306.h>

class DisplayView : public IDisplayView {
public:
    DisplayView();
    void showWelcomeText(const char* text) override;
    void showSensorData(float temperatureData, float humidityData) override;
    ~DisplayView() override;
private:
    ILoggerService* loggerService;
    SSD1306_t display;

    //header
    std::string headerText = "";
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
