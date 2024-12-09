#ifndef SAMPLES_2_TIMEEVENT_H
#define SAMPLES_2_TIMEEVENT_H

#include <framework.h>

class TimeEvent : public IEventName<TimeEvent> {
public:
    TimeEvent(uint8_t hour, uint8_t minute, uint8_t second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    uint8_t getHour() const {
        return hour;
    }
    uint8_t getMinute() const {
        return minute;
    }
    uint8_t getSecond() const {
        return second;
    }
    static const char* getEventName() {
        return "TimeEvent";
    }
private:
    uint8_t hour = 0;
    uint8_t minute = 0;
    uint8_t second = 0;
};

#endif //SAMPLES_2_TIMEEVENT_H
