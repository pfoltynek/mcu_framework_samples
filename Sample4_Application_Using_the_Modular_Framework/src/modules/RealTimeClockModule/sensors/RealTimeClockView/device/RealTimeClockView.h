#ifndef SAMPLES_2_REALTIMECLOCKVIEW_H
#define SAMPLES_2_REALTIMECLOCKVIEW_H

#ifdef DEVICE

#include "modules/RealTimeClockModule/sensors/RealTimeClockView/IRealTimeClockView.h"
#include <RTClib.h>

class RealTimeClockView : public IRealTimeClockView {
    public:
        explicit RealTimeClockView();
        Time getTime() override;
        Date getDate() override;
        ~RealTimeClockView() override;
    private:
        ILoggerService *loggerService;
        RTC_DS3231 rtc = RTC_DS3231();
};

#endif

#endif //SAMPLES_2_REALTIMECLOCKVIEW_H
