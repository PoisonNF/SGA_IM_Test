#include "task_jy901.h"
#include "config.h"

void Task_JY901_Test(void)
{
    //������ݻ�ò��Ҵ������
	if(OCD_JY901_DataProcess(&JY901S))
    {
        OCD_JY901_DataConversion(&JY901S);	//����ת��
        OCD_JY901_Printf(&JY901S); 			//���ݴ�ӡ
        printf("\r\n");
    }
}

