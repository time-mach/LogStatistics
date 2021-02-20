#include <stdio.h>
#include <string.h>
#include "Nginx_m.h"
#include "Common.h"
#define HHMM_LEN 9

void Nginx_m(char *pLog)
{
	printf("Nginx_m, ��־·���� %s\n", pLog);
	char HHMM[HHMM_LEN] = {'\0'};
	char temp[HHMM_LEN] = {'\0'};
	
	int ret = 0;
	SIZE count = 0;
	
	FILE * pFile = NULL;
	if ( NULL == (pFile = fopen(pLog, "r")) ) {
		printf("��־�ļ� %s ��ʧ��!\n", pLog);
		return ;
	}

	ret = fscanf(pFile, "%*30c%s%*[^\n]", HHMM);
	memset(HHMM + 5, 0, 4);
	printf("=====��ȡ�����ĸ����� %d, ��ȡ��ʱ����: %s\n", ret, HHMM);
	count++;
	ret = 0;
	strcpy(temp, HHMM);
	memset(HHMM, 0, HHMM_LEN);
	
	//���ܵ�ǰ�������һ�У�������һ���뵱ǰ��һ����������һ�����뵱ǰ�в�һ�� 

	while( !feof(pFile) )
	{
		ret = fscanf(pFile, "%*31c%s%*[^\n]", HHMM);
		memset(HHMM + 5, 0, 4);
		printf("=====��ȡ�����ĸ����� %d, ��ȡ��ʱ����: %s\n", ret, HHMM);
		if(0 == strcmp(temp, HHMM))
		{
			count++;
			printf("���� %s �ĸ����� %u\n", temp, count);
			ret = 0;
			memset(HHMM, 0, HHMM_LEN);
			continue;
		}
		//���ܵ�ǰ�������һ�У�������һ���뵱ǰ�в�һ����������һ���뵱ǰ��һ�� 
		//��ȡ�����µ�ʱ��
		//1 д����һʱ��ĸ���
		printf("��һ������ %s �ĸ����� %u\n", temp, count);
		UpdateFile(temp, count); 
		//2 count = 1
		
		//3 ����temp
		memset(temp, 0, HHMM_LEN);
		strcpy(temp, HHMM);
		printf("���������� %s\n", temp);
		
		//4 ����HH 
		count = 1;
		ret = 0;
		memset(HHMM, 0, HHMM_LEN);
		//���ܵ�ǰ�������һ�У�������һ���뵱ǰ�в�һ����������һ���뵱ǰ��һ�� 
	}
	UpdateFile(temp, count); 
	
	fclose(pFile);
	
	return ;
}
