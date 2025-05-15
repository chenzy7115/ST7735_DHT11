#include <stdio.h>
#include "display_init.h"
#include "lvgl_ui.h"
#include "dht11.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include <nvs_flash.h>
#include "esp_task_wdt.h"

// 共享传感器数据
// 定义消息结构体（用于队列传递）
typedef struct {
    int temp;
    int hum;
} SensorData_t;

// 全局消息队列（替代原有的互斥锁和共享变量）
static QueueHandle_t sensor_queue = NULL;

/*-------------------------------------
 * 传感器采集任务
 *-----------------------------------*/
void dht11_get_valu_task(void *pt)
{
    DHT11_Init(DHT11_GPIO);
    SensorData_t data;

    while (1) {
        if (DHT11_StartGet(&data.temp, &data.hum)) {
            // 通过队列发送数据（阻塞式，直到队列有空位）
            if (xQueueSend(sensor_queue, &data, portMAX_DELAY) != pdTRUE) {
                ESP_LOGE("DHT11", "Failed to send data to queue!");
            }
            ESP_LOGI("DHT11", "Temp: %d.%d°C, Hum: %d%%",
                     data.temp / 10, data.temp % 10, data.hum);
        }
        vTaskDelay(pdMS_TO_TICKS(2000)); // 2秒采集周期
    }
}

/*-------------------------------------
 * 显示刷新任务
 *-----------------------------------*/
void display_task(void *pt)
{
    SensorData_t received_data;
    // 注册看门狗（初始化完成后启动监控）
    // esp_task_wdt_add(NULL);
    // 主循环
    while (1)
    {
        // esp_task_wdt_reset(); // 必须在每次循环喂狗
        lv_task_handler(); // LVGL 主任务处理

        // 数据更新逻辑
        // 从队列接收数据（非阻塞，最多等待 10ms）
        if (xQueueReceive(sensor_queue, &received_data, pdMS_TO_TICKS(10))) {
            update_display_values(received_data.temp, received_data.hum);
        }
        // ESP_LOGI("Display", "Free stack: %d", uxTaskGetStackHighWaterMark(NULL));//查看使用了多少内存
        // 测试循环耗时
        // static uint32_t last_tick = 0;
        // uint32_t now = xTaskGetTickCount();
        // ESP_LOGI("Display", "Cycle time: %ldms", now - last_tick);
        // last_tick = now;

        vTaskDelay(pdMS_TO_TICKS(10)); // 调整延迟避免频繁抢占
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

    // 创建消息队列（最多缓存 8 条 SensorData_t 数据）
    sensor_queue = xQueueCreate(8, sizeof(SensorData_t));
    assert(sensor_queue != NULL);

    // 创建传感器采集任务（优先级低于显示）
    xTaskCreate(dht11_get_valu_task, "DHT11", 2048, NULL, 2, NULL);

    // 创建显示任务（更高优先级确保流畅）
    xTaskCreate(display_task, "Display", 4096, NULL, 3, NULL);

    // 主函数无需其他操作（FreeRTOS接管调度）
}
