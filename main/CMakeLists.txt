idf_component_register(
    SRCS 
        "main.c"
        "display/display_init.c"
        "display/lvgl_ui.c"
        "DHT11/dht11.c"

    INCLUDE_DIRS 
        "."
        "display"
        "DHT11"
       
       
 )

