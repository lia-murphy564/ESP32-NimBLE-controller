/*
 * File: main.c
 * File Created: Tuesday, 11th January 2022 11:29 pm
 * Author: Lia Murphy (wxm219@miami.edu)
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include <vector>
#include <bitset>

#include "blehandler.h"
#include "parameter.h"


// #include "driver/uart.h"
// #include "soc/uart_periph.h"
// #include "esp_rom_gpio.h"
// #include "driver/gpio.h"
// #include "hal/gpio_hal.h"
// #include "sdkconfig.h"
// #include "esp_console.h"
// #include "linenoise/linenoise.h"

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')




extern "C" void app_main(void) {

   vTaskDelay(1000 / portTICK_RATE_MS);
    
   Parameter* p = new Parameter();

   ble_init();

   parameter_config param_conf = {
      .type = pot,
      .idx = pot3
   };

   p->configure(&param_conf);

   unsigned int value;
   unsigned int data;


   while(true) {

      for (int i = 0; i < 256; i++) {
         p->setValue(i);
         value = p->getValue();
         data = p->getBitField();
         const char* datab = std::bitset<32>(data).to_string().c_str(); //to binary
         printf("%u -- %s\n", value, datab);
         vTaskDelay(100 / portTICK_RATE_MS);
      }
      // int test = 696969;
      // uart_write_bytes(uart_num, (char*)test, sizeof(test));
   }
}

   // const uart_port_t uart_num = UART_NUM_2;
   //  uart_config_t uart_config = {
   //      .baud_rate = 9600,
   //      .data_bits = UART_DATA_8_BITS,
   //      .parity    = UART_PARITY_DISABLE,
   //      .stop_bits = UART_STOP_BITS_1,
   //      .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
   //      .source_clk = UART_SCLK_APB,
   //  };

   // ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));   
   // // Set UART pins(TX: IO4, RX: IO5, RTS: IO18, CTS: IO19)
   // ESP_ERROR_CHECK(uart_set_pin(UART_NUM_2, 4, 5, 18, 19));

   // // Setup UART buffered IO with event queue
   // const int uart_buffer_size = (1024 * 2);
   // QueueHandle_t uart_queue;

   // // Install UART driver using an event queue here
   // ESP_ERROR_CHECK(uart_driver_install(UART_NUM_2, uart_buffer_size, uart_buffer_size, 10, &uart_queue, 0));

   // Write data to UART.

