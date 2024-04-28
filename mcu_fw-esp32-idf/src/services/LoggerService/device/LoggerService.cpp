#include "services/LoggerService/device/LoggerService.h"

#ifdef DEVICE

static const char *TAG = "app";

void LoggerService::log(const char *message) {
    ESP_LOGV(TAG, "%s", message);
}

void LoggerService::logInfo(const char *message) {
    ESP_LOGI(TAG, "%s", message);
}

void LoggerService::logDebug(const char *message) {
    ESP_LOGD(TAG, "%s", message);
}

void LoggerService::logError(const char *message) {
    ESP_LOGE(TAG, "%s", message);
}

void LoggerService::logWarning(const char *message) {
    ESP_LOGW(TAG, "%s", message);
}

#endif

