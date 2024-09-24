#include "DisplayView.h"

#if DEVICE

DisplayView::DisplayView() {
    loggerService = (ILoggerService *) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logInfo("DisplayView::DisplayView()");

    u8g2.begin();
}

void DisplayView::showWelcomeText(const char *text) {
    loggerService->logInfo("DisplayView::showWelcomeText()");

    updateHeaderPart(text);
    refresh();
}

DisplayView::~DisplayView() {
    loggerService->logInfo("DisplayView::~DisplayView()");
    delete loggerService;
}

void DisplayView::showSensorData(float temperatureData, float humidityData) {
    loggerService->logInfo("DisplayView::showSensorData()");
    updateSensorDataPart(temperatureData, humidityData);
    refresh();
}

void DisplayView::updateHeaderPart(const char *newText) {
    if (headerText != newText) {
        headerText = newText;
        headerTextChanged = true;
    }
}

void DisplayView::updateSensorDataPart(float temperatureNew, float humidityNew) {
    if (temperature != temperatureNew || humidity != humidityNew) {
        temperature = temperatureNew;
        humidity = humidityNew;
        sensorDataChanged = true;
    }
}

void DisplayView::refresh() {
    u8g2.firstPage();
    do {
        u8g2.setFont(u8g2_font_crox1cb_tf); // Change font for header
        u8g2.drawStr(0, 15, headerText.c_str()); // Draw header text

        if(humidity != -1000 && temperature != -1000){
            u8g2.setFont(u8g2_font_ncenB12_tr); // Change font for data

            String temperatureStr = String(temperature, decimalPrecision) + "C";
            u8g2.drawStr(0, 38, "Temp:"); // Draw temperature label
            u8g2.drawStr(60, 38, temperatureStr.c_str()); // Draw temperature value
//
            String humidityStr = String(humidity, decimalPrecision) + "%";
            u8g2.drawStr(0, 60, "Hum :"); // Draw humidity label
            u8g2.drawStr(60, 60, humidityStr.c_str()); // Draw humidity value
        }
    } while (u8g2.nextPage());
}

#endif