#include "DisplayModule.h"

DisplayModule::DisplayModule() {
    loggerService = (ILoggerService*) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logDebug("DisplayModule::DisplayModule()");
}

void DisplayModule::setup() {
    Module::setup();

    loggerService->logDebug("DisplayModule::setup()");

    EventService& event = EventService::getInstance();
    timeEventsId = event.subscribe(TimeEvent::getName(), [this](IEvent* event){
        loggerService->logInfo("DisplayModule::TimeEvent()");
        this->handle_TimeEvent(event);
    });

    dataEventsId = event.subscribe(DataEvent::getName(), [this](IEvent* event){
        loggerService->logInfo("DisplayModule::DataEvent()");
        this->handle_DataEvent(event);
    });

    wifiConnectEventsId = event.subscribe(WifiOnConnect::getName(), [this](IEvent* event){
        loggerService->logInfo("DisplayModule::WifiOnConnect()");
        this->handle_WifiOnConnect(event);
    });

    wifiDisconnectEventsId = event.subscribe(WifiOnDisconnect::getName(), [this](IEvent* event){
        loggerService->logInfo("DisplayModule::WifiOnDisconnect()");
        this->handle_WifiOnDisconnect(event);
    });

    loggerService->logDebug("DisplayModule::setup() - DisplayView.showWelcomeText()");
    IDisplayView* display = (IDisplayView*) getSensor(IDisplayView::getName());
    display->showWelcomeText("Welcome");
}

void DisplayModule::loop() {
    Module::loop();
}

DisplayModule::~DisplayModule() {
    loggerService->logDebug("DisplayModule::~DisplayModule()");
    delete loggerService;
}

void DisplayModule::registerModuleSensors() {
    registerSensor(IDisplayView::getName(), new DisplayView());
}

void DisplayModule::handle_TimeEvent(IEvent* event) {
    if (auto *time = (TimeEvent*) event) {
        loggerService->logDebug("DisplayModule::handle_TimeEvent()");
        IDisplayView* display = (IDisplayView*) getSensor(IDisplayView::getName());

        char timeStr[9];
        sprintf(timeStr, "%02d:%02d:%02d", time->getHour(), time->getMinute(), time->getSecond());
        display->showTimeText(String(timeStr).c_str());
    }
};

void DisplayModule::handle_DataEvent(IEvent* event) {
    if (auto *data = (DataEvent*) event) {
        loggerService->logDebug("DisplayModule::handle_DataEvent()");
        IDisplayView* display = (IDisplayView*) getSensor(IDisplayView::getName());

        Data dataParam = {data->getTemperature(), data->getHumidity(), data->getPressure(), data->getCo2()};
        display->showDataText(dataParam);
    }
};

void DisplayModule::handle_WifiOnConnect(IEvent* event) {
    if (auto *data = (DataEvent*) event) {
        loggerService->logDebug("DisplayModule::handle_WifiOnConnect()");
        IDisplayView* display = (IDisplayView*) getSensor(IDisplayView::getName());
        display->showWifiStatusText(true);
    }
};

void DisplayModule::handle_WifiOnDisconnect(IEvent* event) {
    if (auto *data = (DataEvent*) event) {
        loggerService->logDebug("DisplayModule::handle_WifiOnDisconnect()");
        IDisplayView* display = (IDisplayView*) getSensor(IDisplayView::getName());
        display->showWifiStatusText(false);
    }
};