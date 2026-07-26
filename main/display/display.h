#pragma once

#include "esp_err.h"
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Initialize LCD and LVGL */
esp_err_t display_init(void);

/* Call periodically from main loop */
void display_task(void);

/* Backlight */
void display_set_backlight(uint8_t percent);

/* Screen operations */
void display_clear(uint16_t color);

uint16_t display_width(void);
uint16_t display_height(void);

#ifdef __cplusplus
}
#endif