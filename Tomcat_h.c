#include <stdio.h>
#include <string.h>
#include "Tomcat_h.h"
#include "Common.h"
#define HH_LEN 9

void Tomcat_h(char *pLog)
{
	printf("Tomcat_h, 日志路径是 %s\n", pLog);
	char HH[HH_LEN] = {'\0'};
	char temp[HH_LEN] = {'\0'};
	
	int ret = 0;
	SIZE count = 0;
	
	FILE * pFile = NULL;
	if ( NULL == (pFile = fopen(pLog, "r")) ) {
		printf("日志文件 %s 打开失败!\n", pLog);
		return ;
	}

	ret = fscanf(pFile, "%*30c%s%*[^\n]", HH);
	memset(HH + 2, 0, 7);
	printf("=====读取参数的个数是 %d, 读取的时间是: %s\n", ret, HH);
	count++;
	ret = 0;
	strcpy(temp, HH);
	memset(HH, 0, HH_LEN);
	
	//可能当前就是最后一行，可能下一行与当前行一样，可能下一个行与当前行不一样 

	while( !feof(pFile) )
	{
		ret = fscanf(pFile, "%*31c%s%*[^\n]", HH);
		memset(HH + 2, 0, 7);
		printf("=====读取参数的个数是 %d, 读取的时间是: %s\n", ret, HH);
		if(0 == strcmp(temp, HH))
		{
			count++;
			printf("日期 %s 的个数是 %u\n", temp, count);
			ret = 0;
			memset(HH, 0, HH_LEN);
			continue;
		}
		//可能当前就是最后一行，可能下一行与当前行不一样，可能下一行与当前行一样 
		//读取的是新的时间
		//1 写入上一时间的个数
		printf("上一个日期 %s 的个数是 %u\n", temp, count);
		UpdateFile(temp, count); 
		//2 count = 1
		
		//3 更新temp
		memset(temp, 0, HH_LEN);
		strcpy(temp, HH);
		printf("更新日期是 %s\n", temp);
		
		//4 重置HH 
		count = 1;
		ret = 0;
		memset(HH, 0, HH_LEN);
		//可能当前就是最后一行，可能下一行与当前行不一样，可能下一行与当前行一样 
	}
	UpdateFile(temp, count); 
	
	fclose(pFile);
	
	return ;
}
