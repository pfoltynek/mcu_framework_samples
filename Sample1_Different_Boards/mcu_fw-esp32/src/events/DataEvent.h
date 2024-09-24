#ifndef MCU_FW_ESP32_DATAEVENT_H
#define MCU_FW_ESP32_DATAEVENT_H

#include <framework.h>
#include <cfloat>

class DHTDataEvent : public IEventName<DHTDataEvent> {
public:
    DHTDataEvent(float t, float h) {
        temperature = t;
        humidity = h;
    }
    float getTemperature() const {
        return temperature;
    }
    float getHumidity() const {
        return humidity;
    }
    static const char* getEventName() {
        return "DHTDataEvent";
    }

private:
    float temperature = -FLT_MAX;
    float humidity = -FLT_MAX;
};

#endif //MCU_FW_ESP32_DATAEVENT_H
