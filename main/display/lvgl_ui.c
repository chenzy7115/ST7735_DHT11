#include "lvgl_ui.h"
#include "display_init.h"
#include "dht11.h"

// 静态 UI 对象声明
// static lv_obj_t *label = NULL;
static lv_obj_t *label_tem = NULL;
static lv_obj_t *label_tem_dot = NULL;
static lv_obj_t *label_hum = NULL;
static lv_obj_t *lable_tem_static = NULL;
static lv_style_t style;
static lv_style_t style_font;
static lv_style_t style_tem_font;

// 初始化 UI 布局（仅需调用一次）
void app_main_display_init(void)
{
    LV_FONT_DECLARE(al_hei_16);
    LV_FONT_DECLARE(al_hei_50);
    lv_obj_t *scr = lv_scr_act();

    // 创建标签对象
    // label = lv_label_create(scr);
    label_tem = lv_label_create(scr);
    label_tem_dot = lv_label_create(scr);
    label_hum = lv_label_create(scr);
    lable_tem_static = lv_label_create(scr);

    // 屏幕设置样式
    /*Set a background color */
    lv_style_init(&style);
    lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_DEEP_ORANGE));
    lv_obj_add_style(scr, &style, 0);

    // 字体设置样式,设置为白色
    lv_style_init(&style_font);
    lv_style_set_text_color(&style_font, lv_color_white());
    lv_style_set_text_font(&style_font, &al_hei_16);
    lv_obj_add_style(label_hum, &style_font, 0);
    lv_obj_add_style(lable_tem_static, &style_font, 0);
    lv_obj_add_style(label_tem_dot, &style_font, 0);

    // 温度字体样式
    lv_style_init(&style_tem_font);
    lv_style_set_text_color(&style_tem_font, lv_color_white());
    lv_style_set_text_font(&style_tem_font, &al_hei_50);
    lv_obj_add_style(label_tem, &style_tem_font, 0);

    // 配置标签样式
    // lv_obj_set_width(label, EXAMPLE_LCD_H_RES);
    // lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);

    lv_obj_set_width(label_tem, EXAMPLE_LCD_H_RES);
    lv_obj_set_style_text_align(label_tem, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_width(label_tem_dot, EXAMPLE_LCD_H_RES);
    lv_obj_set_style_text_align(label_tem_dot, LV_TEXT_ALIGN_RIGHT, 0);

    lv_obj_set_width(lable_tem_static, EXAMPLE_LCD_H_RES);
    lv_obj_set_style_text_align(lable_tem_static, LV_TEXT_ALIGN_RIGHT, 0);

    lv_obj_set_width(label_hum, EXAMPLE_LCD_H_RES);
    lv_obj_set_style_text_align(label_hum, LV_TEXT_ALIGN_CENTER, 0);

    // 定位标签位置
    // lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 5);
    lv_obj_align(label_tem, LV_ALIGN_CENTER, -5, -10);
    lv_obj_align(label_tem_dot, LV_ALIGN_RIGHT_MID, -10, 5);
    lv_obj_align(lable_tem_static, LV_ALIGN_TOP_RIGHT, -5, 25);
    lv_obj_align(label_hum, LV_ALIGN_BOTTOM_MID, 0, -10);

    // 设置初始文本
    // lv_label_set_text(label, "   ");
    lv_label_set_text(lable_tem_static, "°C"); // 默认值
    lv_label_set_text(label_tem, "00");        // 默认值
    lv_label_set_text(label_tem_dot, "0");     // 默认值
    lv_label_set_text(label_hum, " 湿度 :  % ");
}

// 更新显示数据（周期性调用）
void update_display_values(int temp_val, int hum_val)
{
    static int last_temp = 0, last_hum = 0;
    lvgl_port_lock(0);
    if (temp_val != last_temp)
    {
        lv_label_set_text_fmt(label_tem, "%d", temp_val / 10);
        lv_label_set_text_fmt(label_tem_dot, "%d", temp_val % 10);
        last_temp = temp_val;
    }
    if (hum_val != last_hum)
    {
        lv_label_set_text_fmt(label_hum, "  湿度 : %d %% ", hum_val);
        last_hum = hum_val;
    }
    lvgl_port_unlock();
}