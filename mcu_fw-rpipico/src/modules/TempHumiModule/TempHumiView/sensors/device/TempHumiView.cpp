#include "TempHumiView.h"

#if DEVICE
#include <string>

TempHumiView::TempHumiView() {
    loggerService = (ILoggerService*)ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logInfo("TempHumiView::TempHumiView()");

    dht.begin();

    loggerService->logInfo("DHTxx Unified Sensor Example");

    // Print temperature sensor details.
    sensor_t sensor;
    dht.temperature().getSensor(&sensor);
    loggerService->logInfo("------------------------------------");
    loggerService->logInfo("Temperature Sensor");
    loggerService->logInfo(("Sensor Type: " + String(sensor.name)).c_str());
    loggerService->logInfo(("Driver Ver:  " + String(sensor.version)).c_str());
    loggerService->logInfo(("Unique ID:   " + String(sensor.sensor_id)).c_str());
    loggerService->logInfo(("Max Value:   " + String(sensor.max_value) + "°C").c_str());
    loggerService->logInfo(("Min Value:   " + String(sensor.min_value) + "°C").c_str());
    loggerService->logInfo(("Resolution:  " + String(sensor.resolution) + "°C").c_str());
    loggerService->logInfo("------------------------------------");

    // Print humidity sensor details.
    dht.humidity().getSensor(&sensor);

    loggerService->logInfo("Humidity Sensor");
    loggerService->logInfo(("Sensor Type: " + String(sensor.name)).c_str());
    loggerService->logInfo(("Driver Ver:  " + String(sensor.version)).c_str());
    loggerService->logInfo(("Unique ID:   " + String(sensor.sensor_id)).c_str());
    loggerService->logInfo(("Max Value:   " + String(sensor.max_value) + "%").c_str());
    loggerService->logInfo(("Min Value:   " + String(sensor.min_value) + "%").c_str());
    loggerService->logInfo(("Resolution:  " + String(sensor.resolution) + "%").c_str());
    loggerService->logInfo("------------------------------------");
}

DHTData TempHumiView::getData() {

    loggerService->logInfo("TempHumiView::getData()");

    DHTData data{};
    sensors_event_t event;

    // Get temperature event and print its value.
    dht.temperature().getEvent(&event);
    if (isnan(event.temperature)) {
        loggerService->logError("Error reading temperature!");
    }
    else {
        data.temperature = event.temperature;
    }

    // Get humidity event and print its value.
    dht.humidity().getEvent(&event);
    if (isnan(event.relative_humidity)) {
        loggerService->logError("Error reading humidity!");
    }
    else {
        data.humidity = event.relative_humidity;
    }

    return data;
}

TempHumiView::~TempHumiView() {
    loggerService->logInfo("TempHumiView::~TempHumiView()");
    delete loggerService;
}

#endif