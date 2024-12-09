#ifndef ESP32_FW_SAMPLE1_SERVICES_H
#define ESP32_FW_SAMPLE1_SERVICES_H

#ifdef DEVICE
    #include "services/LoggerService/device/LoggerService.h"
    #include "services/ThingSpeakService/device/TeamSpeakService.h"
#elif NATIVE
    #include "services/LoggerService/native/LoggerService.h"
#endif

#endif //ESP32_FW_SAMPLE1_SERVICES_H
