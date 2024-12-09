#include "services/LoggerService/device/LoggerService.h"

#ifdef DEVICE

void LoggerService::log(const char *message) {
    Serial.println(_log("LOG", message));
}

void LoggerService::logInfo(const char *message) {
    Serial.println(_log("INFO", message));
}

void LoggerService::logDebug(const char *message) {
    //Serial.println(_log("DEBUG", message));
}

void LoggerService::logError(const char *message) {
    Serial.println(_log("ERROR", message));
}

void LoggerService::logWarning(const char *message) {
    Serial.println(_log("WARNING", message));
}

const char* LoggerService::_log(const char *level, const char *message) {
    static String result;
    result = (String(level) + ": " + String(message)).c_str();
    return result.c_str();
}

#endif