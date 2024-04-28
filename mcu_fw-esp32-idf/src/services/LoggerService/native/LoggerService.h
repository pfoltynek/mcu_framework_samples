#ifndef ESP32_FW_SAMPLE1_LOGGERSERVICENATIVE_H
#define ESP32_FW_SAMPLE1_LOGGERSERVICENATIVE_H

#ifdef NATIVE

#include "framework.h"

class LoggerService : public ILoggerService {
    public:
        explicit LoggerService();
        void log(const char* message) override;
        void logInfo(const char* message) override;
        void logDebug(const char* message) override;
        void logError(const char* message) override;
        void logWarning(const char* message) override;
    private:
        static const char* _log(const char* level, const char* message);
};

#endif

#endif //ESP32_FW_SAMPLE1_LOGGERSERVICENATIVE_H
