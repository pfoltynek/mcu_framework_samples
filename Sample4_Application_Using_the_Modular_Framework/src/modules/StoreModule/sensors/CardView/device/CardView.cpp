#include "CardView.h"

#if DEVICE

CardView::CardView() {
    loggerService = (ILoggerService*)ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logDebug("CardView::CardView()");

    if (!SD.begin(PIN_SPI_CS)) {
        loggerService->logError("SD CARD FAILED, OR NOT PRESENT!");
        while (1); // stop the program
    } else {
        loggerService->logInfo("SD CARD OK!");
    }
}

CardView::~CardView() {
    loggerService->logDebug("CardView::~CardView()");
    delete loggerService;
}

AppSettings CardView::getSettings() {
    const size_t bufferLen = 80;
    char buffer[bufferLen];

    loggerService->logDebug("CardView::getSetting()");

    AppSettings settings = AppSettings();

    IniFile ini(settingFile);
    if (!ini.open()) {
        loggerService->logError(String("Ini file " + String(settingFile) + " does not exist").c_str());
        settings.initFromFile = false;
        return settings;
    }

    if (!ini.validate(buffer, bufferLen)){
        loggerService->logError(String("Ini file " + String(settingFile) + " not valid: " + getErrorMessageFromInitFile(ini.getError())).c_str());
        settings.initFromFile = false;
        return settings;
    }

    //wifi_ssid
    if (ini.getValue("Wifi", "ssid", buffer, bufferLen)) {
        loggerService->logDebug(String("section 'Wifi' has an entry 'ssid' with value '" + String(buffer) + "'").c_str());
        strcpy(settings.wifi.ssid, buffer);
    }
    else {
        loggerService->logError(String("Could not read 'ssid' from section 'Wifi', error was " + getErrorMessageFromInitFile(ini.getError())).c_str());
    }

    //wifi_password
    if (ini.getValue("Wifi", "password", buffer, bufferLen)) {
        loggerService->logDebug(String("section 'Wifi' has an entry 'password' with value '" + String(buffer) + "'").c_str());
        strcpy(settings.wifi.password, buffer);
    }
    else {
        loggerService->logError(String("Could not read 'password' from section 'Wifi', error was " + getErrorMessageFromInitFile(ini.getError())).c_str());
    }


    if (ini.getValue("ThingSpeak", "channel_id", buffer, bufferLen)) {
        loggerService->logDebug(String("section 'ThingSpeak' has an entry 'channel_id' with value '" + String(buffer) + "'").c_str());
        strcpy(settings.thingSpeak.channel_id, buffer);
    }
    else {
        loggerService->logError(String("Could not read 'channel_id' from section 'ThingSpeak', error was " + getErrorMessageFromInitFile(ini.getError())).c_str());
    }


    if (ini.getValue("ThingSpeak", "write_api_key", buffer, bufferLen)) {
        loggerService->logDebug(String("section 'ThingSpeak' has an entry 'write_api_key' with value '" + String(buffer) + "'").c_str());
        strcpy(settings.thingSpeak.write_api_key, buffer);
    }
    else {
        loggerService->logError(String("Could not read 'write_api_key' from section 'ThingSpeak', error was " + getErrorMessageFromInitFile(ini.getError())).c_str());
    }

    settings.initFromFile = true;

    return settings;
}

String CardView::getErrorMessageFromInitFile(uint8_t e, bool eol) {
    switch (e) {
        case IniFile::errorNoError:
            return "no error";
        case IniFile::errorFileNotFound:
            return "file not found";
        case IniFile::errorFileNotOpen:
            return "file not open";
        case IniFile::errorBufferTooSmall:
            return "buffer too small";
        case IniFile::errorSeekError:
            return "seek error";
        case IniFile::errorSectionNotFound:
            return "section not found";
        case IniFile::errorKeyNotFound:
            return "key not found";
        case IniFile::errorEndOfFile:
            return "end of file";
        case IniFile::errorUnknownError:
            return "unknown error";
        default:
            return "unknown error value";
    }
    if (eol)
        return "";
}

#endif