#include "DisplayModule.h"

DisplayModule::DisplayModule() {
    loggerService = (ILoggerService*) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logInfo("DisplayModule::DisplayModule()");
}

void DisplayModule::setup() {
    Module::setup();

    loggerService->logInfo("DisplayModule::setup()");

    EventService& event = EventService::getInstance();
    dhtEventsId = event.subscribe(DHTDataEvent::getName(), [this](IEvent* event){
        loggerService->logInfo("DisplayModule::DHTDataEvent()");
        this->handle_DHTDataEvent(event);
    });

    loggerService->logInfo("DisplayModule::setup() - DisplayView.showWelcomeText()");
    IDisplayView* display = (IDisplayView*) getSensor(IDisplayView::getName());
    display->showWelcomeText("Sensor DHT11!");
}

void DisplayModule::loop() {
    Module::loop();
}

DisplayModule::~DisplayModule() {
    loggerService->logInfo("DisplayModule::~DisplayModule()");
    delete loggerService;
}

void DisplayModule::registerModuleSensors() {
    registerSensor(IDisplayView::getName(), new DisplayView());
}

void DisplayModule::handle_DHTDataEvent(IEvent* event) {
    if (auto *data = (DHTDataEvent*) event) {
        IDisplayView* display = (IDisplayView*) getSensor(IDisplayView::getName());
        display->showSensorData(data->getTemperature(), data->getHumidity());
    }
};
