#include "SCD41View.h"

#ifdef DEVICE

SCD41View::SCD41View() {
    uint16_t error;
    char errorMessage[256];

    loggerService = (ILoggerService *) ServiceLocator::getInstance().getService(ILoggerService::getName());
    loggerService->logDebug("SCD41View::SCD41View()");

    scd4x.begin(Wire);

    // stop potentially previously started measurement
    error = scd4x.stopPeriodicMeasurement();
    if (error) {
        errorToString(error, errorMessage, 256);
        loggerService->logError(errorMessage);
    } else {
        loggerService->logInfo("SCD4x stopped periodic measurement");
    }

    uint16_t serial0;
    uint16_t serial1;
    uint16_t serial2;
    error = scd4x.getSerialNumber(serial0, serial1, serial2);
    if (error) {
        errorToString(error, errorMessage, 256);
        loggerService->logError(errorMessage);
    } else {

        loggerService->logInfo(
                String("SCD4x serial number: " +
                    printUint16Hex(serial0) + ":" +
                    printUint16Hex(serial1) + ":" +
                    printUint16Hex(serial2)
                ).c_str());
    }

    error = scd4x.startPeriodicMeasurement();
    if (error) {
        errorToString(error, errorMessage, 256);
        loggerService->logError(errorMessage);
    }
    else {
        loggerService->logInfo("SCD4x started periodic measurement");
    }

//    error = scd4x.measureSingleShot();
//    if (error) {
//        errorToString(error, errorMessage, 256);
//        loggerService->logError(errorMessage);
//    } else {
//        loggerService->logInfo("SCD4x started single shot measurement");
//    }
}

SCD41Data SCD41View::getData() {

    SCD41Data data = SCD41Data();

    uint16_t error;
    char errorMessage[256];

    uint16_t co2;
    float temperature;
    float humidity;
    error = scd4x.readMeasurement(co2, temperature, humidity);
    if (error) {
        errorToString(error, errorMessage, 256);
        loggerService->logError(errorMessage);
    } else {
        loggerService->logInfo("SCD4x read measurement");
        loggerService->logInfo(("SCD4x CO2: " + String(co2)).c_str());
        loggerService->logInfo(("SCD4x Temperature: " + String(temperature)).c_str());
        loggerService->logInfo(("SCD4x Humidity: " + String(humidity)).c_str());

        data.co2 = co2;
        data.temperature = temperature;
        data.humidity = humidity;
    }

//    error = scd4x.measureSingleShot();
//    if (error) {
//        errorToString(error, errorMessage, 256);
//        loggerService->logError(errorMessage);
//    } else {
//        loggerService->logInfo("Request fresh data (should take 5 seconds)");
//    }

    return data;
}

SCD41View::~SCD41View() {
    loggerService->logInfo("SCD41View::~SCD41View()");
    delete loggerService;
}

String SCD41View::printUint16Hex(uint16_t value) {
    String hexValue = String(value, HEX);
    while (hexValue.length() < 4) {
        hexValue = "0" + hexValue;
    }
    return hexValue;
}

#endif