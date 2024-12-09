#ifndef SAMPLES_2_IBME280VIEW_H
#define SAMPLES_2_IBME280VIEW_H

#include <framework.h>

struct BME280Data {
    float pressure = -1000;
    float temperature = -1000;
    float humidity = -1000;
};

class IBME280View :public ISensorName<IBME280View> {
public:
    virtual BME280Data getData() = 0;
    ~IBME280View() override = default;

    static const char *getSensorName() {
        return "IBME280View";
    }
};

#endif //SAMPLES_2_IBME280VIEW_H
