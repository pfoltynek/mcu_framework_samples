#include "DisplayView.h"

#if DEVICE

DisplayView::DisplayView() {
    loggerService = (ILoggerService *) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logInfo("DisplayView::DisplayView()");

    lcd.begin(16, 2);
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
    if (headerTextChanged || sensorDataChanged) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(headerText);
        lcd.setCursor(0, 1);
        lcd.print("T:");
        lcd.print(temperature, decimalPrecision);
        lcd.print("C");
        lcd.print(" H:");
        lcd.print(humidity, decimalPrecision);
        lcd.print("%");
        headerTextChanged = false;
        sensorDataChanged = false;
    }
}

#endif