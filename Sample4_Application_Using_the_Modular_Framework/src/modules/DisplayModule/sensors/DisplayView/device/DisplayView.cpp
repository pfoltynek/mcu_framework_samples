#include "DisplayView.h"

#if DEVICE

DisplayView::DisplayView() {
    loggerService = (ILoggerService *) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logDebug("DisplayView::DisplayView()");
    u8g2.begin();
}

void DisplayView::showWelcomeText(const char *text) {
    loggerService->logDebug("DisplayView::showWelcomeText()");
    welcomeText = text;
    refresh();
}

void DisplayView::showTimeText(const char *text) {
    loggerService->logDebug("DisplayView::showTimeText()");

    if(updateTimeText(text)){
        refresh();
    }
}

void DisplayView::showDataText(Data dataEvent) {
    loggerService->logDebug("DisplayView::showDataText()");

    if(updateDataText(dataEvent)){
        refresh();
    }
}

void DisplayView::showWifiStatusText(bool status) {
    loggerService->logDebug("DisplayView::showWifiStatusText()");

    if(updateWifiStatus(status)){
        refresh();
    }
}

DisplayView::~DisplayView() {
    loggerService->logDebug("DisplayView::~DisplayView()");
    delete loggerService;
}

void DisplayView::refresh() {

    if(timeText == ""){
        u8g2.firstPage();
        do {
            u8g2.setFont(u8g2_font_crox1cb_tf);         // Change font for header
            u8g2.drawStr(15, 35, welcomeText.c_str());  // Draw header text

        } while (u8g2.nextPage());
    } else {
        u8g2.firstPage();
        do {
            u8g2.setFont(u8g2_font_crox1cb_tf);          // Change font for header
            u8g2.drawStr(0, 15, timeText.c_str());       // Draw time text
            if(wifiStatus){
                u8g2.drawStr(90, 15, "wifi");
            }

            u8g2.setFont(u8g2_font_6x10_tf);             // Change font for data
            if(!dataDefault){

                String temperatureStr = String(data.temperature, decimalPrecision) + " C";
                u8g2.drawStr(0, 30, "Temp :");
                u8g2.drawStr(45, 30, temperatureStr.c_str());

                String humidityStr = String(data.humidity, decimalPrecision) + " %";
                u8g2.drawStr(0, 40, "Hum  :");
                u8g2.drawStr(45, 40, humidityStr.c_str());

                String humidityPressureStr = String(data.pressure, decimalPrecision) + " hPa";
                u8g2.drawStr(0, 50, "Press:");
                u8g2.drawStr(45, 50, humidityPressureStr.c_str());

                String humidityCo2Str = String(data.co2) + " ppm";
                u8g2.drawStr(0, 60, "CO2  :");
                u8g2.drawStr(45, 60, humidityCo2Str.c_str());
            }

        } while (u8g2.nextPage());
    }
}

bool DisplayView::updateTimeText(const char *text) {
    if (timeText != text) {
        timeText = text;
        return true;
    }

    return false;
}

bool DisplayView::updateDataText(Data dataNew) {
    if (data.temperature != dataNew.temperature ||
        data.humidity != dataNew.humidity ||
        data.pressure != dataNew.pressure ||
        data.co2 != dataNew.co2) {

        data = dataNew;
        dataDefault = false;
        return true;
    }

    return false;
}

bool DisplayView::updateWifiStatus(bool statusNew) {
    if (wifiStatus != statusNew) {
        wifiStatus = statusNew;
        return true;
    }
    return false;
}

#endif