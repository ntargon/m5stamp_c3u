#include <iostream>
#include <stdio.h>
#include <random>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
// #include <M5Unified.h>
#include <rmt_led_strip.hpp>

esp_idf::sk6812 leds(2, 1);

uint32_t get_rand_range(uint32_t min_val, uint32_t max_val) {
    // 乱数生成器
    static std::mt19937 mt32(0);

    // [min_val, max_val] の一様分布整数 (int) の分布生成器
    std::uniform_int_distribution<uint32_t> get_rand_uni_int(min_val, max_val);

    // 乱数を生成
    return get_rand_uni_int(mt32);
}


extern "C" void app_main(void) {
    // setup
    leds.initialize();

    vTaskDelay(1000 / portTICK_PERIOD_MS);
    std::cout << "hello world" << std::endl;
    while (true) {
        int r = get_rand_range(0, 255);
        int g = get_rand_range(0, 255);
        int b = get_rand_range(0, 255);
        leds.color(0, r, g, b);
        leds.update();
        printf("(r, g, b) = (%d, %d, %d)\n", r, g, b);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}