/*
 * display.c
 *
 * Waveshare ESP32-S3 Touch LCD 1.85C
 * ST77916 QSPI
 * ESP-IDF 5.5.4
 */

#include "display.h"
#include "hardware_config.h"
#include "st77916_init.h"

#include <string.h>
#include <assert.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_err.h"
#include "esp_check.h"
#include "esp_heap_caps.h"
#include "esp_timer.h"

#include "driver/spi_master.h"
#include "driver/gpio.h"

#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"

#include "lvgl.h"

static const char *TAG = "DISPLAY";

/*----------------------------------------------------------
 * Handles
 *---------------------------------------------------------*/

static esp_lcd_panel_io_handle_t lcd_io = NULL;

static lv_display_t *lv_display = NULL;

static void *buf1 = NULL;
static void *buf2 = NULL;

/*----------------------------------------------------------
 * Private Prototypes
 *---------------------------------------------------------*/

static esp_err_t lcd_bus_init(void);
static esp_err_t lcd_io_init(void);
static esp_err_t st77916_panel_init(void);

static void backlight_init(void);

static void lvgl_init(void);
static void lvgl_tick_init(void);

static void lcd_draw_bitmap(
    int xs,
    int ys,
    int xe,
    int ye,
    const void *data);

static void lvgl_flush_cb(
    lv_display_t *disp,
    const lv_area_t *area,
    uint8_t *px_map);

/*----------------------------------------------------------
 * Initialize QSPI Bus
 *---------------------------------------------------------*/

static esp_err_t lcd_bus_init(void)
{
    spi_bus_config_t buscfg = {
        .sclk_io_num = LCD_PIN_SCLK,

        .data0_io_num = LCD_PIN_DATA0,
        .data1_io_num = LCD_PIN_DATA1,
        .data2_io_num = LCD_PIN_DATA2,
        .data3_io_num = LCD_PIN_DATA3,

        .mosi_io_num = -1,
        .miso_io_num = -1,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,

        .max_transfer_sz =
            LCD_H_RES *
            LVGL_BUFFER_LINES *
            sizeof(uint16_t),
    };

    ESP_RETURN_ON_ERROR(
        spi_bus_initialize(
            LCD_SPI_HOST,
            &buscfg,
            SPI_DMA_CH_AUTO),
        TAG,
        "Failed to initialize SPI bus");

    ESP_LOGI(TAG, "QSPI bus initialized");

    return ESP_OK;
}
