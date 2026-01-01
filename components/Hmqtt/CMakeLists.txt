idf_component_register(SRCS "Hmqtt.c"
                    PRIV_REQUIRES esp-tls esp_wifi esp_event nvs_flash mqtt
                    REQUIRES Hwifi
                    INCLUDE_DIRS "include"
                    EMBED_TXTFILES "mosquitto.org.crt"
                    )
