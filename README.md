# 使用ST7735芯片LCD+DHT11温度传感器

# 使用的驱动通过ESP-IDF的组件来增加ST7735的驱动

组件的使用情况，在main folder下的idf_conponent.yml中进行查看

# 目录结构

├── main/
│   ├── CMakeLists.txt    
│   ├── main.c
│   └── display/          
│       ├── display_init.c
│       └── display_init.h
│       ├── lvgl_ui.c
│       └── lvgl_ui.h