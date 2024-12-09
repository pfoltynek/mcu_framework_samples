#ifndef SAMPLES_2_CARDVIEW_H
#define SAMPLES_2_CARDVIEW_H

#ifdef DEVICE

#include "modules/StoreModule/sensors/CardView/ICardView.h"
#include <SD.h>
#include <IniFile.h>

//#define PIN_SPI_CS 5

class CardView : public ICardView {
    public:
        explicit CardView();
        AppSettings getSettings() override;
        ~CardView() override;
    private:
        ILoggerService *loggerService;
        const char* settingFile = "/setting.ini";
        static String getErrorMessageFromInitFile(uint8_t e, bool eol = true);
};

#endif

#endif //SAMPLES_2_CARDVIEW_H
