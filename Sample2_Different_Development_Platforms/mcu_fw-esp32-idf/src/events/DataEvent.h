#ifndef MCU_FW_ESP32_DATAEVENT_H
#define MCU_FW_ESP32_DATAEVENT_H

#include <framework.h>

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
    float temperature;
    float humidity;
};

#endif //MCU_FW_ESP32_DATAEVENT_H
