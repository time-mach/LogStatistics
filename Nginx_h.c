#include <stdio.h>
#include <string.h>
#include "Nginx_h.h"
#include "Common.h"
#define HH_LEN 9

void Nginx_h(char *pLog)
{
	printf("Nginx_h, ��־·���� %s\n", pLog);
	char HH[HH_LEN] = {'\0'};
	char temp[HH_LEN] = {'\0'};
	
	int ret = 0;
	SIZE count = 0;
	
	FILE * pFile = NULL;
	if ( NULL == (pFile = fopen(pLog, "r")) ) {
		printf("��־�ļ� %s ��ʧ��!\n", pLog);
		return ;
	}
    //192.168.10.51 �C �C [23/Mar/2015:17:27:28 +0800] ��GET /finance/index.action?0.8436781843192875 HTTP/1.0�� 200 2 0.011
	ret = fscanf(pFile, "%*30c%s%*[^\n]", HH);
	memset(HH + 2, 0, 7);
	printf("=====��ȡ�����ĸ����� %d, ��ȡ��ʱ����: %s\n", ret, HH);
	count++;
	ret = 0;
	strcpy(temp, HH);
	memset(HH, 0, HH_LEN);
	
	//���ܵ�ǰ�������һ�У�������һ���뵱ǰ��һ����������һ�����뵱ǰ�в�һ�� 

	while( !feof(pFile) )
	{
		ret = fscanf(pFile, "%*31c%s%*[^\n]", HH);
		memset(HH + 2, 0, 7);
		printf("=====��ȡ�����ĸ����� %d, ��ȡ��ʱ����: %s\n", ret, HH);
		if(0 == strcmp(temp, HH))
		{
			count++;
			printf("���� %s �ĸ����� %u\n", temp, count);
			ret = 0;
			memset(HH, 0, HH_LEN);
			continue;
		}
		//���ܵ�ǰ�������һ�У�������һ���뵱ǰ�в�һ����������һ���뵱ǰ��һ�� 
		//��ȡ�����µ�ʱ��
		//1 д����һʱ��ĸ���
		printf("��һ������ %s �ĸ����� %u\n", temp, count);
		UpdateFile(temp, count); 
		//2 count = 1
		
		//3 ����temp
		memset(temp, 0, HH_LEN);
		strcpy(temp, HH);
		printf("���������� %s\n", temp);
		
		//4 ����HH 
		count = 1;
		ret = 0;
		memset(HH, 0, HH_LEN);
		//���ܵ�ǰ�������һ�У�������һ���뵱ǰ�в�һ����������һ���뵱ǰ��һ�� 
	}
	UpdateFile(temp, count); 
	
	fclose(pFile);
	
	return ;
}