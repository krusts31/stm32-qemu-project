#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

#define LED_GPIO_PIN 2 // Change this to the GPIO pin number connected to your LED
#define FLASH_DELAY_MS 100 // Time in milliseconds for LED flash duration
#define PAUSE_DELAY_MS 10000 // Time in milliseconds for pause duration
#define FLASH_COUNT 10 // Number of flashes

void app_main()
{
    printf("Hello world!\n");

    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is ESP8266 chip with %d CPU cores, WiFi, ",
            chip_info.cores);

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    // Configure the LED GPIO pin as output
    gpio_set_direction(LED_GPIO_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        // Flash the LED 10 times
        for (int i = 0; i < FLASH_COUNT; i++) {
            gpio_set_level(LED_GPIO_PIN, 1); // LED on
            vTaskDelay(FLASH_DELAY_MS / portTICK_PERIOD_MS);
            gpio_set_level(LED_GPIO_PIN, 0); // LED off
            vTaskDelay(FLASH_DELAY_MS / portTICK_PERIOD_MS);
        }

        // Pause for 10 seconds
        vTaskDelay(PAUSE_DELAY_MS / portTICK_PERIOD_MS);
    }
}
