#ifndef SAMPLES_2_SCD41VIEW_H
#define SAMPLES_2_SCD41VIEW_H

#ifdef DEVICE

#include "modules/DataModule/sensors/SCD41View/ISCD41View.h"
#include <SensirionI2CScd4x.h>

class SCD41View : public ISCD41View {
    public:
        explicit SCD41View();
        SCD41Data getData() override;
        ~SCD41View() override;
    private:
        ILoggerService *loggerService;
        SensirionI2CScd4x scd4x = SensirionI2CScd4x();

        static String printUint16Hex(uint16_t value);
};

#endif

#endif //SAMPLES_2_SCD41VIEW_H
