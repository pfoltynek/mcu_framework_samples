#ifndef SAMPLES_2_BME280VIEW_H
#define SAMPLES_2_BME280VIEW_H

#ifdef DEVICE

#include "modules/DataModule/sensors/BME280View/IBME280View.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME280_ADDRESS (0x77)

class BME280View : public IBME280View {
    public:
        explicit BME280View();
        BME280Data getData() override;
        ~BME280View() override;
    private:
        ILoggerService *loggerService;
        Adafruit_BME280 bme = Adafruit_BME280();
};

#endif

#endif //SAMPLES_2_BME280VIEW_H
