#include "task_conf.h"
#include "config.h"

void Task_UserInit(void)
{
    Drv_Uart_DMAInit(&Uart1);

	Drv_GPIO_Init(LED, 3);
    Task_LED_AllOff();

    OCD_DS3231_Init(&tDS3231);

    OCD_FATFS_Init(&tFATFS);

    OCD_AT24CXX_Init(&tAT24CXX);

    OCD_JY901_DMAInit(&JY901S);

}
