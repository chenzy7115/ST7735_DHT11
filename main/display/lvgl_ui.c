#include "lvgl_ui.h"
#include "display_init.h"
#include "dht11.h"

// 静态 UI 对象声明
// static lv_obj_t *label = NULL;
static lv_obj_t *label_tem = NULL;
static lv_obj_t *label_hum = NULL;

// 初始化 UI 布局（仅需调用一次）
void app_main_display_init(void)
{
    lv_obj_t *scr = lv_scr_act();

    // 创建标签对象
    // label = lv_label_create(scr);
    label_tem = lv_label_create(scr);
    label_hum = lv_label_create(scr);
    vTaskDelay(1);

    // 配置标签样式
    // lv_obj_set_width(label, EXAMPLE_LCD_H_RES);
    // lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);

    lv_obj_set_width(label_tem, EXAMPLE_LCD_H_RES);
    lv_obj_set_style_text_align(label_tem, LV_TEXT_ALIGN_RIGHT, 0);

    lv_obj_set_width(label_hum, EXAMPLE_LCD_H_RES);
    lv_obj_set_style_text_align(label_hum, LV_TEXT_ALIGN_RIGHT, 0);
    vTaskDelay(1);

    // 定位标签位置
    // lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 5);
    lv_obj_align(label_tem, LV_ALIGN_RIGHT_MID, -20, -20);
    lv_obj_align(label_hum, LV_ALIGN_RIGHT_MID, -20, 20);
    vTaskDelay(1);

    // 设置初始文本
    // lv_label_set_text(label, "   ");
    lv_label_set_text(label_tem, " -- °C "); // 默认值
    lv_label_set_text(label_hum, " --  % ");
    vTaskDelay(1);
}

// 更新显示数据（周期性调用）
void update_display_values(int temp_val, int hum_val)
{

    lv_label_set_text_fmt(label_tem, " %d.%d °C ", temp_val / 10, temp_val % 10);
    lv_label_set_text_fmt(label_hum, " %d   %% ", hum_val);
}
