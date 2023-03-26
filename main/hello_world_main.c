#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define NUM_LEDS 4
const uint8_t LED_GPIO_PINS[NUM_LEDS] = {5, 4, 0, 2}; // OUTPUT LEDS
//14, 12, 13, 15, 3, 1

//D1 == GPIO5
//D2 == GPIO4
//D3 == GPIO0
//D4 == GPIO2

void  led_loop() {
  int button_pres = 0;
  int i = 0;
  int direction = 1;

  while (1) {
      gpio_set_level(LED_GPIO_PINS[i], 1);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      gpio_set_level(LED_GPIO_PINS[i], 0);
      button_pres++;
      if (direction > 0) {
          i++;
          if (i == 4)
            i = 0;
      } else {
          i--;
          if (i == -1)
            i = 3;
      }
      if (button_pres % 15 == 0) {
        direction = -direction;
      }
  }
}

void app_main() {
    for (int i = 0; i < NUM_LEDS; i++) {
        gpio_set_direction(LED_GPIO_PINS[i], GPIO_MODE_OUTPUT);
    }
    led_loop();
}
