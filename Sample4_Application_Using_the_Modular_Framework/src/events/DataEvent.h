#ifndef SAMPLES_2_DATAEVENT_H
#define SAMPLES_2_DATAEVENT_H

#include <framework.h>

class DataEvent : public IEventName<DataEvent> {
public:
    DataEvent(float temperature, float humidity, float pressure, uint16_t co2){
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        this->co2 = co2;
    }
    float getTemperature() const {
        return temperature;
    }
    float getHumidity() const {
        return humidity;
    }
    float getPressure() const {
        return pressure;
    }
    uint16_t getCo2() const {
        return co2;
    }
    static const char* getEventName() {
        return "DataEvent";
    }

private:
    float pressure = -1000;
    float temperature = -1000;
    float humidity = -1000;
    uint16_t co2 = 0;
};

#endif //SAMPLES_2_DATAEVENT_H