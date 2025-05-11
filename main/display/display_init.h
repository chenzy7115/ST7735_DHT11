#ifndef DISP_INIT_H
#define DISP_INIT_H
#include "esp_lcd_st7735.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_check.h"
#include "driver/i2c.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lvgl_port.h"

/* LCD size */
#define EXAMPLE_LCD_H_RES (128)
#define EXAMPLE_LCD_V_RES (128)

/* LCD settings */
#define EXAMPLE_LCD_SPI_NUM (SPI3_HOST)
#define EXAMPLE_LCD_PIXEL_CLK_HZ (40 * 1000 * 1000)
#define EXAMPLE_LCD_CMD_BITS (8)
#define EXAMPLE_LCD_PARAM_BITS (8)
#define EXAMPLE_LCD_COLOR_SPACE (ESP_LCD_COLOR_SPACE_BGR)
#define EXAMPLE_LCD_BITS_PER_PIXEL (16)
#define EXAMPLE_LCD_DRAW_BUFF_DOUBLE (1)
#define EXAMPLE_LCD_DRAW_BUFF_HEIGHT (50)
#define EXAMPLE_LCD_BL_ON_LEVEL (1)

/* LCD pins */
#define EXAMPLE_LCD_GPIO_SCLK (GPIO_NUM_19)
#define EXAMPLE_LCD_GPIO_MOSI (GPIO_NUM_23)
#define EXAMPLE_LCD_GPIO_RST (GPIO_NUM_18)
#define EXAMPLE_LCD_GPIO_DC (GPIO_NUM_21)
#define EXAMPLE_LCD_GPIO_CS (GPIO_NUM_22)
#define EXAMPLE_LCD_GPIO_BL (GPIO_NUM_5)

static const char *TAG = "LCD";

/* LCD IO and panel */
static esp_lcd_panel_io_handle_t lcd_io = NULL;
static esp_lcd_panel_handle_t lcd_panel = NULL;

/* LVGL display and touch */
static lv_display_t *lvgl_disp = NULL;

extern esp_err_t app_lcd_init(void);
extern esp_err_t app_lvgl_init(void);





#endif