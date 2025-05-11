#include "lvgl_ui.h"
#include "display_init.h"

void app_main_display(void)
{
    lv_obj_t *scr = lv_scr_act();

    /* Task lock */
    lvgl_port_lock(0);

    /* Label */
    lv_obj_t *label = lv_label_create(scr);
    lv_obj_set_width(label, EXAMPLE_LCD_H_RES);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);

    lv_label_set_text(label, " Indoor Env ");

    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 5);

    lvgl_port_unlock();
}
