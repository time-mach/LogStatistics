#include <stdio.h>
#include <string.h>
#include "Tomcat_s.h"
#include "Common.h"
#define HHMMSS_LEN 9

/*
 ������ɽ����������ݷֹ�˾ʯ�������������������Դ�벻�������κ���ҵĿ�ģ��κ�ת����������ߺ���Դ���������ʣ����ʼ���ϵ��kelehaier@126.com
*/

void Tomcat_s(char *pLog)
{
	printf("���뺯��Tomcat_s, ��־·���� %s\n", pLog);
	char HHMMSS[HHMMSS_LEN] = {'\0'};
	char temp[HHMMSS_LEN] = {'\0'};
	
	int ret = 0;
	SIZE count = 0;
	
	FILE * pFile = NULL;
	if ( NULL == (pFile = fopen(pLog, "r")) ) {
		printf("��־�ļ� %s ��ʧ��!\n", pLog);
		return ;
	}

	ret = fscanf(pFile, "%*30c%s%*[^\n]", HHMMSS);
	printf("��ȡ�����ĸ����� %d, ��ȡ��ʱ����: %s\n", ret, HHMMSS);
	count++;
	ret = 0;
	strcpy(temp, HHMMSS);
	memset(HHMMSS, 0, HHMMSS_LEN);
	
	//���ܵ�ǰ�������һ�У�������һ���뵱ǰ��һ����������һ�����뵱ǰ�в�һ�� 

	while( !feof(pFile) )
	{
		ret = fscanf(pFile, "%*31c%s%*[^\n]", HHMMSS);
		printf("��ȡ�����ĸ����� %d, ��ȡ��ʱ����: %s\n", ret, HHMMSS);

		if(0 == strcmp(temp, HHMMSS))
		{
			count++;
			printf("���� %s �ĸ����� %u\n", temp, count);
			ret = 0;
			memset(HHMMSS, 0, HHMMSS_LEN);
			continue;
		}
		//���ܵ�ǰ�������һ�У�������һ���뵱ǰ�в�һ����������һ���뵱ǰ��һ�� 
		//��ȡ�����µ�ʱ��
		//1 д����һʱ��ĸ���
		printf("��һ������ %s �ĸ����� %u\n", temp, count);
		UpdateFile(temp, count); 
		//2 count = 1
		
		//3 ����temp
		memset(temp, 0, HHMMSS_LEN);
		strcpy(temp, HHMMSS);
		printf("���������� %s\n", temp);
		
		//4 ����HH 
		count = 1;
		ret = 0;
		memset(HHMMSS, 0, HHMMSS_LEN);
		//���ܵ�ǰ�������һ�У�������һ���뵱ǰ�в�һ����������һ���뵱ǰ��һ�� 
	}
	UpdateFile(temp, count); 
	
	fclose(pFile);
	
	return ;
}

