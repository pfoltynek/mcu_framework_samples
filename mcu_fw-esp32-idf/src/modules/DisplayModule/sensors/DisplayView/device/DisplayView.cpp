#include "DisplayView.h"

#if DEVICE

DisplayView::DisplayView() {
    loggerService = (ILoggerService *) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logInfo("DisplayView::DisplayView()");

    i2c_master_init(&display, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);
    ssd1306_init(&display, 128, 64);
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

    // Vytvoření řetězců pro teplotu a vlhkost
    char* text = new char[headerText.length() + 1];
    std::strcpy(text, headerText.c_str());

    char temperatureStr[15];
    char humidityStr[15];

    // Formátování teploty a vlhkosti
    if(decimalPrecision == 0) {
        sprintf(temperatureStr, "%dC", (int)temperature);
        sprintf(humidityStr, "%d%%", (int)humidity);
    } else {
        sprintf(temperatureStr, "%.*fC", decimalPrecision, temperature);
        sprintf(humidityStr, " %.*f%%", decimalPrecision, humidity);
    }

    // Vytvoření zprávy pro zobrazení
    char message1[50];
    char message2[50];
    sprintf(message1, "Temp: %s", temperatureStr);
    sprintf(message2, "Hum: %s", humidityStr);

    // Zobrazení zprávy na displeji
    ssd1306_clear_screen(&display, false);
    ssd1306_display_text(&display, 0, text, strlen(text), false);
    ssd1306_display_text(&display, 3, message1, strlen(message1), false);
    ssd1306_display_text(&display, 5, message2, strlen(message2), false);

    // Nezapomeňte uvolnit paměť po použití
    delete[] text;
}

#endif