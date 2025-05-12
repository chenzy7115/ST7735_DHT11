# 使用ST7735芯片LCD+DHT11温度传感器

# 显示UI和温度采集在不同的文件夹中，可以灵活使用

组件的调用使用freeRTOS task
UI将显示部分分为init和flush两个部分
UI initiate 的部分有delay阻塞，避免看门狗启动
task一定要有delay阻塞避免看门狗启动

# 目录结构

display folder 中的包括显示初始化和UI
DH11 folde 中包括DH11驱动和数据采集