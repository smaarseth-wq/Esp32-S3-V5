#pragma once

#include "driver/gpio.h"
#include "driver/spi_master.h"

/*----------------------------------------------------------
 * Display
 *---------------------------------------------------------*/

#define LCD_H_RES                  360
#define LCD_V_RES                  360

#define LCD_COLOR_BITS             16

/*----------------------------------------------------------
 * SPI
 *---------------------------------------------------------*/

#define LCD_SPI_HOST               SPI2_HOST

#define LCD_PIXEL_CLOCK_HZ         (80 * 1000 * 1000)

#define LCD_TRANS_QUEUE_DEPTH      10

#define LCD_CMD_BITS               32
#define LCD_PARAM_BITS             8

/*----------------------------------------------------------
 * QSPI Pins
 *---------------------------------------------------------*/

#define LCD_PIN_CS                 GPIO_NUM_21

#define LCD_PIN_SCLK               GPIO_NUM_40

#define LCD_PIN_DATA0              GPIO_NUM_46
#define LCD_PIN_DATA1              GPIO_NUM_45
#define LCD_PIN_DATA2              GPIO_NUM_42
#define LCD_PIN_DATA3              GPIO_NUM_41

/*----------------------------------------------------------
 * Control Pins
 *---------------------------------------------------------*/

#define LCD_PIN_RESET              GPIO_NUM_NC

#define LCD_PIN_BACKLIGHT          GPIO_NUM_5

/*----------------------------------------------------------
 * LVGL
 *---------------------------------------------------------*/

#define LVGL_BUFFER_LINES          40

#define LVGL_TICK_PERIOD_MS        2