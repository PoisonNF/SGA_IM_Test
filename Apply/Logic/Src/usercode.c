#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_IM_Test!\r\n");
	printf("Enter @ + num to start!\r\n");
	printf("0:All 1:LED 2:DS1337 3:TATFS 4:AT24CXX 5:JY901\r\n");
	
	while(1)
	{
		//����PC������
		Task_PCUartListen();
	}
}
