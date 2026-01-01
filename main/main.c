#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"

#include "esp_system.h"

#include "Hmqtt.h"
#include "Hwifi.h"

void app_main(void)
{
    printf("Hello world!\n");
    
    BaseType_t xReturned;
    xReturned = xTaskCreate(TaskHwifi, "task_wifi", 2048, NULL, 1, NULL);
    if (xReturned != pdPASS) {
        printf("task_wifi creation failed!\n");
    } else {
        printf("task_wifi created successfully.\n");
    }

    xReturned = xTaskCreate(TaskHMqtt, "task_mqtt", 2048, NULL, 2, NULL);
    if (xReturned != pdPASS) {
        printf("task_mqtt creation failed!\n");
    } else {
        printf("task_mqtt created successfully.\n");
    }
}