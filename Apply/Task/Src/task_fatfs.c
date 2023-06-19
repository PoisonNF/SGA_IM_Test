#include "task_fatfs.h"
#include "config.h"

static uint8_t File_Name[] = "/test/example.txt";
static uint8_t Path_Name[] = "/test";
uint8_t sendBuffer[100] = "abcdefghijklmnopqrtsuvwxyz";
uint8_t receBuffer[100] = {0};
uint32_t sendNum = 0;
uint32_t receNum = 0;
uint32_t Offset = 0;
int8_t ret;

void Task_TATFS_Test(void)
{
    //�����ļ���
	ret = OCD_FATFS_CreateDir(&tFATFS,(char *)Path_Name);
    if(ret == FR_OK)
        printf("�����ļ��гɹ� %s\r\n",Path_Name);
    
    else if(ret == FR_EXIST)
        printf("�ļ����Ѵ��� %s\r\n",Path_Name);

    //ѭ������
    for(int i = 0; i < 3; i++)
    {
        //��ĩβд������
		if(OCD_FATFS_Write_End(&tFATFS, (char *)File_Name, sendBuffer, sizeof("abcdefghijklmnopqrtsuvwxyz") , &sendNum) == FR_OK)
			printf("д��%d���ֽ� ����Ϊ%s\r\n",sendNum,sendBuffer);

		Drv_Delay_Ms(100);

        //���д�����ݳ��Ȳ�Ϊ0
		if(sendNum != 0)
            //��ƫ��������ȡ��ͬ��������
			if(OCD_FATFS_Read_SpecifyIndex(&tFATFS, (char *)File_Name ,receBuffer,sendNum,Offset,&receNum) == FR_OK)
            {
                printf("��ƫ����%d ����%d���ֽ� ����Ϊ%s\r\n",Offset,receNum,receBuffer);
                //ƫ�����ۼ�
                Offset += receNum;
            }
    }
    printf("\r\n");
}

