#include "shell/App.h"

App app = App();

#ifdef DEVICE
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

extern "C" [[noreturn]] void app_main()
{
    app.setup();
    ESP_LOGI("app", "setup");

    while (true) {
        app.loop();
        ESP_LOGI("app", "loop");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
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