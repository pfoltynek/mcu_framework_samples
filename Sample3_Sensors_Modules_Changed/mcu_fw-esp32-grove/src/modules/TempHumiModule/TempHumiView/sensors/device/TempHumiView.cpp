#include "TempHumiView.h"

#if DEVICE
#include <string>

TempHumiView::TempHumiView() {
    loggerService = (ILoggerService*)ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logInfo("TempHumiView::TempHumiView()");

    if(!bme280.init()){
        loggerService->logError("Device error!");
    }
    else{
        loggerService->logInfo("Device initialized!");
    }
}

DHTData TempHumiView::getData() {

    loggerService->logInfo("TempHumiView::getData()");

    DHTData data{};
    data.temperature = bme280.getTemperature();
    data.humidity = (float)bme280.getHumidity();
    return data;
}

TempHumiView::~TempHumiView() {
    loggerService->logInfo("TempHumiView::~TempHumiView()");
    delete loggerService;
}

#endif