#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

typedef struct s_pins {
  uint8_t TX;   //GPIO1
  uint8_t RX;   //GPIO3
  uint8_t D1;   //GPIO5
  uint8_t D2;   //GPIO4
  uint8_t D3;   //GPIO0
  uint8_t D4;   //GPIO2
  uint8_t GND;  //GND
  uint8_t V5;   //-
  uint8_t RST;  //RST
  uint8_t A0;   //A0
  uint8_t D0;   //GPIO16
  uint8_t D5;   //GPIO14
  uint8_t D6;   //GPIO12
  uint8_t D7;   //GPIO13
  uint8_t D8;   //GPIO15
  uint8_t V3;   //3v
}              t_pins;

static void  led_loop(const t_pins pins) {
  while (1) {
     int input_state = gpio_get_level(pins.D4);
     if (input_state) {
       gpio_set_level(pins.TX, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.RX, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.D1, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.D2, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.D3, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.D5, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.D7, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.D6, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
     } else {
       gpio_set_level(pins.D6, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.D7, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.D5, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.D3, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.D2, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.D1, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.RX, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
       gpio_set_level(pins.TX, 1);
       vTaskDelay(200 / portTICK_PERIOD_MS);
     }
     gpio_set_level(pins.TX, 0);
     gpio_set_level(pins.RX, 0);
     gpio_set_level(pins.D1, 0);
     gpio_set_level(pins.D2, 0);
     gpio_set_level(pins.D3, 0);
     gpio_set_level(pins.D7, 0);
     gpio_set_level(pins.D5, 0);
     gpio_set_level(pins.D6, 0);
  }
}

static int init_ouput_pints(const t_pins pins) {
    gpio_config_t io_conf_output;
    gpio_config_t io_conf_input;

    io_conf_output.intr_type = GPIO_INTR_DISABLE;
    io_conf_output.mode = GPIO_MODE_OUTPUT;
    io_conf_output.pin_bit_mask = ((1ULL << pins.TX) | (1ULL << pins.RX) | (1ULL << pins.D1) | (1ULL << pins.D2) | (1ULL << pins.D3) | (1ULL << pins.D5) | (1ULL << pins.D6) | (1ULL << pins.D7) | (1ULL << pins.D7));
    io_conf_output.pull_down_en = 0;
    io_conf_output.pull_up_en = 0;

    io_conf_input.intr_type = GPIO_INTR_DISABLE;
    io_conf_input.mode = GPIO_MODE_INPUT;
    io_conf_input.pin_bit_mask = (1ULL << pins.D4);
    io_conf_input.pull_down_en = 0;
    io_conf_input.pull_up_en = 1;

    if (gpio_config(&io_conf_output) == ESP_ERR_INVALID_ARG || gpio_config(&io_conf_input) == ESP_ERR_INVALID_ARG ) {
      return ESP_ERR_INVALID_ARG;
    }
    return ESP_OK;
}

void app_main() {
    const t_pins pins = {1, 3, 5, 4, 0, 2, -1, -1, -1, -1, 16, 14, 12, 13 ,15, -1};

    if (init_ouput_pints(pins) == ESP_ERR_INVALID_ARG) {
      return ;
    }
    led_loop(pins);
}
