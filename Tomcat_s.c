#include <stdio.h>
#include <string.h>
#include "Tomcat_s.h"
#include "Common.h"
#define HHMMSS_LEN 9

/*
 本软件由江苏有线苏州分公司石鑫鹏开发，本软件所有源码不可用于任何商业目的，任何转发请标明作者和来源。若有疑问，可邮件联系：kelehaier@126.com
*/

void Tomcat_s(char *pLog)
{
	printf("进入函数Tomcat_s, 日志路径是 %s\n", pLog);
	char HHMMSS[HHMMSS_LEN] = {'\0'};
	char temp[HHMMSS_LEN] = {'\0'};
	
	int ret = 0;
	SIZE count = 0;
	
	FILE * pFile = NULL;
	if ( NULL == (pFile = fopen(pLog, "r")) ) {
		printf("日志文件 %s 打开失败!\n", pLog);
		return ;
	}

	ret = fscanf(pFile, "%*30c%s%*[^\n]", HHMMSS);
	printf("读取参数的个数是 %d, 读取的时间是: %s\n", ret, HHMMSS);
	count++;
	ret = 0;
	strcpy(temp, HHMMSS);
	memset(HHMMSS, 0, HHMMSS_LEN);
	
	//可能当前就是最后一行，可能下一行与当前行一样，可能下一个行与当前行不一样 

	while( !feof(pFile) )
	{
		ret = fscanf(pFile, "%*31c%s%*[^\n]", HHMMSS);
		printf("读取参数的个数是 %d, 读取的时间是: %s\n", ret, HHMMSS);

		if(0 == strcmp(temp, HHMMSS))
		{
			count++;
			printf("日期 %s 的个数是 %u\n", temp, count);
			ret = 0;
			memset(HHMMSS, 0, HHMMSS_LEN);
			continue;
		}
		//可能当前就是最后一行，可能下一行与当前行不一样，可能下一行与当前行一样 
		//读取的是新的时间
		//1 写入上一时间的个数
		printf("上一个日期 %s 的个数是 %u\n", temp, count);
		UpdateFile(temp, count); 
		//2 count = 1
		
		//3 更新temp
		memset(temp, 0, HHMMSS_LEN);
		strcpy(temp, HHMMSS);
		printf("更新日期是 %s\n", temp);
		
		//4 重置HH 
		count = 1;
		ret = 0;
		memset(HHMMSS, 0, HHMMSS_LEN);
		//可能当前就是最后一行，可能下一行与当前行不一样，可能下一行与当前行一样 
	}
	UpdateFile(temp, count); 
	
	fclose(pFile);
	
	return ;
}

