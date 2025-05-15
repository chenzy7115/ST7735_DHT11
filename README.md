# 使用ST7735芯片LCD+DHT11温度传感器

# 显示UI和温度采集在不同的文件夹中，可以灵活使用

组件的调用使用freeRTOS task
#
UI将显示部分分为init和flush两个部分
#
task一定要有delay阻塞避免看门狗启动

# 通过消息队列queue，来传递DHT11采集来的数据，避免使用互斥锁产生的竞争延迟

# 目录结构

display folder 中的包括显示初始化和UI
#
DH11 folde 中包括DH11驱动和数据采集

# ESP-IDF的espressif_esp_lvgl_port接口已经将LVGL移植所需要重要部分都已经封装
对于使用者来说只需要考虑显示屏的驱动既可，不需要过多的考虑其他问题