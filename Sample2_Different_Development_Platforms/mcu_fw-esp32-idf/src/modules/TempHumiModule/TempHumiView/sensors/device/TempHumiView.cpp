#include "TempHumiView.h"

#if DEVICE
#include <string>

//#ifdef CONFIG_EXAMPLE_INTERNAL_PULLUP
//    gpio_set_pull_mode(dht_gpio, GPIO_PULLUP_ONLY);
//#endif

TempHumiView::TempHumiView() {
    loggerService = (ILoggerService*)ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logInfo("TempHumiView::TempHumiView()");
}

DHTData TempHumiView::getData() {

    DHTData data{};
    float temperature, humidity;

    if (dht_read_float_data(DHT_TYPE_DHT11, gpio_num_t(DHTPIN) , &humidity, &temperature) == ESP_OK)
    {
        data.temperature = temperature;
        data.humidity = humidity;

        std::string logMessage = "Humidity: " + std::to_string(humidity) + "% Temp: " + std::to_string(temperature) + "C";
        loggerService->logInfo(logMessage.c_str());
    }
    else
        loggerService->logError("Could not read data from sensor\n");

    return data;
}

TempHumiView::~TempHumiView() {
    loggerService->logInfo("TempHumiView::~TempHumiView()");
    delete loggerService;
}

#endif