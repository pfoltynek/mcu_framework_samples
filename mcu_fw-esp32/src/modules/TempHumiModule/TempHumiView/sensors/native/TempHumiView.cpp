#include "TempHumiView.h"

#if NATIVE

TempHumiView::TempHumiView() {
    loggerService = (ILoggerService*)ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logInfo("TempHumiView::TempHumiView()");
}

DHTData TempHumiView::getData() {
    return DHTData();
}

TempHumiView::~TempHumiView() {
    loggerService->logInfo("TempHumiView::~TempHumiView()");
    delete loggerService;
}

#endif