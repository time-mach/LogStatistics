#include <stdio.h>
#include "Common.h"

void Help() {
	printf("====================================\n");
	printf("��ӭʹ�� ƽ̨������ͳ�����\n");
	printf("Usage: LogStatistics ��������[Tomcat|...] ͳ�Ʒ�ʽ[-h��ʱ|-m����|-s����] ��־·�� \n");
	printf("====================================\n");
}

void UpdateFile(char *HHMMSS, SIZE count)
{
	int ret = 0;
	FILE * pFile = NULL;
	if ( NULL == (pFile = fopen(DAT_PATH, "a")) ) {
		printf("����ļ� %s ��ʧ��!\n", DAT_PATH);
		return ;
	}

	ret = fprintf(pFile,"%s,%u\n", HHMMSS, count);
	printf("д������ĸ����� %d\n", ret);
	
	fclose(pFile);
}

