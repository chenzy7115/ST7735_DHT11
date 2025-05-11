#include <stdio.h>
#include "display_init.h"
#include "lvgl_ui.h"
#include "dht11.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include <nvs_flash.h>
#include "esp_task_wdt.h"

// 全局互斥锁
static SemaphoreHandle_t sensor_mutex = NULL;
// 共享传感器数据
static int temp = 0;
static int hum = 0;

/*-------------------------------------
 * 传感器采集任务
 *-----------------------------------*/
void dht11_get_valu_task(void *pt)
{
    DHT11_Init(DHT11_GPIO);
    while (1)
    {
        int local_temp, local_hum;
        if (DHT11_StartGet(&local_temp, &local_hum))
        {
            // 加锁更新共享数据
            if (xSemaphoreTake(sensor_mutex, portMAX_DELAY) == pdTRUE)
            {
                temp = local_temp;
                hum = local_hum;
                xSemaphoreGive(sensor_mutex);
            }
            ESP_LOGI("DHT11", "Temp: %d.%d°C, Hum: %d%%",
                     temp / 10, temp % 10, hum );
        }
        vTaskDelay(pdMS_TO_TICKS(2000)); // 2秒采集周期
    }
}

/*-------------------------------------
 * 显示刷新任务
 *-----------------------------------*/
void display_task(void *pt)
{

    // 注册看门狗（初始化完成后启动监控）
    // esp_task_wdt_add(NULL);

    // 主循环
    while (1)
    {
        // esp_task_wdt_reset(); // 必须在每次循环喂狗
        // lv_task_handler();    // LVGL 主任务处理

        // 数据更新逻辑
        int current_temp = 0, current_hum = 0;
        if (xSemaphoreTake(sensor_mutex, pdMS_TO_TICKS(10)) == pdTRUE)
        {
            current_temp = temp;
            current_hum = hum;
            xSemaphoreGive(sensor_mutex);
        }
        update_display_values(current_temp, current_hum);
        // ESP_LOGI("Display", "Free stack: %d", uxTaskGetStackHighWaterMark(NULL));//查看使用了多少内存

        vTaskDelay(pdMS_TO_TICKS(100)); // 调整延迟避免频繁抢占
    }
}

/*-------------------------------------
 * 主函数
 *-----------------------------------*/
void app_main()
{
    // 初始化NVS（部分硬件依赖）
    ESP_ERROR_CHECK(nvs_flash_init());
    // 初始化阶段（一次性执行）
    // 初始化内容避免放入task中，task可以运行的代码不能过大
    ESP_ERROR_CHECK(app_lcd_init());
    ESP_ERROR_CHECK(app_lvgl_init());
    app_main_display_init(); // UI 初始化

    // 创建互斥锁
    sensor_mutex = xSemaphoreCreateMutex();
    assert(sensor_mutex != NULL);

    // 创建传感器采集任务（优先级低于显示）
    xTaskCreate(dht11_get_valu_task, "DHT11", 2048, NULL, 2, NULL);

    // 创建显示任务（更高优先级确保流畅）
    xTaskCreate(display_task, "Display", 4096, NULL, 3, NULL);

    // 主函数无需其他操作（FreeRTOS接管调度）
}

