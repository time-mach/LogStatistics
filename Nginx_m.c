#include <stdio.h>
#include <string.h>
#include "Nginx_m.h"
#include "Common.h"
#define HHMM_LEN 9

void Nginx_m(char *pLog)
{
	printf("Nginx_m, 日志路径是 %s\n", pLog);
	char HHMM[HHMM_LEN] = {'\0'};
	char temp[HHMM_LEN] = {'\0'};
	
	int ret = 0;
	SIZE count = 0;
	
	FILE * pFile = NULL;
	if ( NULL == (pFile = fopen(pLog, "r")) ) {
		printf("日志文件 %s 打开失败!\n", pLog);
		return ;
	}

	ret = fscanf(pFile, "%*30c%s%*[^\n]", HHMM);
	memset(HHMM + 5, 0, 4);
	printf("=====读取参数的个数是 %d, 读取的时间是: %s\n", ret, HHMM);
	count++;
	ret = 0;
	strcpy(temp, HHMM);
	memset(HHMM, 0, HHMM_LEN);
	
	//可能当前就是最后一行，可能下一行与当前行一样，可能下一个行与当前行不一样 

	while( !feof(pFile) )
	{
		ret = fscanf(pFile, "%*31c%s%*[^\n]", HHMM);
		memset(HHMM + 5, 0, 4);
		printf("=====读取参数的个数是 %d, 读取的时间是: %s\n", ret, HHMM);
		if(0 == strcmp(temp, HHMM))
		{
			count++;
			printf("日期 %s 的个数是 %u\n", temp, count);
			ret = 0;
			memset(HHMM, 0, HHMM_LEN);
			continue;
		}
		//可能当前就是最后一行，可能下一行与当前行不一样，可能下一行与当前行一样 
		//读取的是新的时间
		//1 写入上一时间的个数
		printf("上一个日期 %s 的个数是 %u\n", temp, count);
		UpdateFile(temp, count); 
		//2 count = 1
		
		//3 更新temp
		memset(temp, 0, HHMM_LEN);
		strcpy(temp, HHMM);
		printf("更新日期是 %s\n", temp);
		
		//4 重置HH 
		count = 1;
		ret = 0;
		memset(HHMM, 0, HHMM_LEN);
		//可能当前就是最后一行，可能下一行与当前行不一样，可能下一行与当前行一样 
	}
	UpdateFile(temp, count); 
	
	fclose(pFile);
	
	return ;
}
