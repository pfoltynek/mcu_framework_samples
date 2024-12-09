#ifndef SAMPLES_2_ISDC41VIEW_H
#define SAMPLES_2_ISDC41VIEW_H

#include <framework.h>

struct SCD41Data {
    uint16_t co2 = 0;
    float temperature = -1000;
    float humidity = -1000;
};

class ISCD41View :public ISensorName<ISCD41View>{
    public:
        virtual SCD41Data getData() = 0;
        ~ISCD41View() override = default;

        static const char* getSensorName() {
            return "ISCD41View";
        }
};

#endif //SAMPLES_2_ISDC41VIEW_H
