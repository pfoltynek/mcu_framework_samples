#ifndef ESP32_FW_SAMPLE1_DISPLAYVIEWNATIVE_H
#define ESP32_FW_SAMPLE1_DISPLAYVIEWNATIVE_H

#ifdef NATIVE
#include "modules/DisplayModule/sensors/DisplayView/IDisplayView.h"
#include <iostream>

class DisplayView : public IDisplayView {
    public:
        void showWelcomeText(const char* text) override{
            std::cout << "DisplayViewNative::showWelcomeText: (" << text << ")"<< std::endl;
        };
        void showSensorData(float temperature, float humidity){
            std::cout << "DisplayViewNative::showSensorData: (" << temperature << ", " << humidity << ")"<< std::endl;
        };
};

#endif

#endif //ESP32_FW_SAMPLE1_DISPLAYVIEWNATIVE_H
