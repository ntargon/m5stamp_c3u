#include <iostream>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern "C" void app_main(void) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    std::cout << "hello world" << std::endl;
}