idf_component_register(
    SRCS 
        "main.c"
        "display/display_init.c"
        "display/lvgl_ui.c"
        "display/al_hei_16.c"
        "display/al_hei_50.c"
        "DHT11/dht11.c"

    INCLUDE_DIRS 
        "."
        "display"
        "DHT11"
       
       
 )

