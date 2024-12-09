#ifndef SAMPLES_2_IREALTIMECLOCKVIEW_H
#define SAMPLES_2_IREALTIMECLOCKVIEW_H

#include <framework.h>

struct Time {
    uint16_t hour = 0;
    uint16_t min = 0;
    uint16_t sec = 0;
};

struct Date {
    uint16_t year = 0;
    uint16_t month = 0;
    uint16_t day = 0;
};

class IRealTimeClockView :public ISensorName<IRealTimeClockView>{
    public:
        virtual Time getTime() = 0;
        virtual Date getDate() = 0;
        ~IRealTimeClockView() override = default;

        static const char* getSensorName() {
            return "IRealTimeClockView";
        }
};

#endif //SAMPLES_2_IREALTIMECLOCKVIEW_H
