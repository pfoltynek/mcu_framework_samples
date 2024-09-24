#include "shell/App.h"

App app = App();

#ifdef DEVICE

#include <Arduino.h>
#include <Wire.h>

void setup() {
    Serial.begin(115200);
    while(!Serial);    // time to get serial running
    Wire.begin();

    app.setup();
}

void loop() {
    app.loop();
    delay(1000);
}

#elif NATIVE
#include <thread>
#include <iostream>

void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {

    app.setup();

    int i = 0;
    while (i < 10) {
        app.loop();
        i++;
        delay(1000);
        std::cout << "loop = " << i << std::endl;
    }

    return 0;
}
#endif