#include "LoggerService.h"

#ifdef NATIVE

#include <iostream>

LoggerService::LoggerService() {

}

void LoggerService::log(const char *message) {
    std::cout << _log("LOG", message) << std::endl;
}

void LoggerService::logInfo(const char *message) {
    std::cout << _log("INFO", message) << std::endl;
}

void LoggerService::logDebug(const char *message) {
    std::cout << _log("DEBUG", message) << std::endl;
}

void LoggerService::logError(const char *message) {
    std::cout << _log("ERROR", message) << std::endl;
}

void LoggerService::logWarning(const char *message) {
    std::cout << _log("WARNING", message) << std::endl;
}

const char* LoggerService::_log(const char *level, const char *message) {
    static std::string result;
    result = std::string(level) + ": " + std::string(message);
    return result.c_str();
}

#endif