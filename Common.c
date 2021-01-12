#include <stdio.h>
#include "Common.h"

void Help() {
	printf("====================================\n");
	printf("欢迎使用 平台访问数统计软件\n");
	printf("Usage: LogStatistics 服务器名[Tomcat|...] 统计方式[-h按时|-m按分|-s按秒] 日志路径 \n");
	printf("====================================\n");
}

void UpdateFile(char *HHMMSS, SIZE count)
{
	int ret = 0;
	FILE * pFile = NULL;
	if ( NULL == (pFile = fopen(DAT_PATH, "a")) ) {
		printf("结果文件 %s 打开失败!\n", DAT_PATH);
		return ;
	}

	ret = fprintf(pFile,"%s,%u\n", HHMMSS, count);
	printf("写入参数的个数是 %d\n", ret);
	
	fclose(pFile);
}

