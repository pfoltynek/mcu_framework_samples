#ifndef MCU_FW_STM_NUCLEO_TEMPHUMIVIEW_H
#define MCU_FW_STM_NUCLEO_TEMPHUMIVIEW_H

#if NATIVE

#include "../../ITempHumiView.h"

class TempHumiView : public ITempHumiView{
public:
    explicit TempHumiView();
    DHTData getData() override;
    ~TempHumiView() override;
private:
    ILoggerService *loggerService;
};

#endif

#endif //MCU_FW_STM_NUCLEO_TEMPHUMIVIEW_H
