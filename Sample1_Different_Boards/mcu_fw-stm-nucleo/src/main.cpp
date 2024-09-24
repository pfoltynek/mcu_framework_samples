#include "shell/App.h"

App app = App();

#ifdef DEVICE
#include <Arduino.h>
#include <Wire.h>

void setup() {

    Serial.begin(115200);
    while(!Serial);
    Wire.begin();

    pinMode(LED_BUILTIN, OUTPUT);

    app.setup();
}

void loop() {

    Serial.println("On Led");
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)

    app.loop();
    delay(1000);

    Serial.println("Off Led");
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(500);
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