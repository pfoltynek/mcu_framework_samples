#include "RealTimeClockView.h"

#if DEVICE

RealTimeClockView::RealTimeClockView() {
    loggerService = (ILoggerService *) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logDebug("RealTimeClockView::RealTimeClockView()");

    if (! rtc.begin()) {
        loggerService->logError("Couldn't find RTC");
        while (1) delay(10);
    }

    if (rtc.lostPower()) {
        loggerService->logInfo("RTC lost power, lets set the time!");
        // When time needs to be set on a new device, or after a power loss, the
        // following line sets the RTC to the date & time this sketch was compiled
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        // This line sets the RTC with an explicit date & time, for example to set
        // January 21, 2014 at 3am you would call:
        // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    }
}

RealTimeClockView::~RealTimeClockView() {
    loggerService->logDebug("RealTimeClockView::~RealTimeClockView()");
    delete loggerService;
}

Time RealTimeClockView::getTime() {
    loggerService->logDebug("RealTimeClockView::getTime()");

    Time time{};

    DateTime now = rtc.now();
    time.hour = now.hour();
    time.min = now.minute();
    time.sec = now.second();

    return time;
}

Date RealTimeClockView::getDate() {
    loggerService->logDebug("RealTimeClockView::getDate()");

    Date date{};

    DateTime now = rtc.now();
    date.year = now.year();
    date.month = now.month();
    date.day = now.day();

    return date;
}

#endif