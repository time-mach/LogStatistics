#include <stdio.h>
#include <string.h>

#include "Tomcat.h"
#include "Weblogic.h"
#include "JBoss.h"
#include "Nginx.h"
#include "Common.h"

#define SERVER_LEN 10
#define SERVERS_COUNT 3
#define LOGPATH_LEN 100
#define PARAMS_COUNT 4

int main(int argc,char *argv[]) //�ȷ�����main.exe Tomcat -h /localhost_access_2020-01-01.txt,  argc����4, ��һ��������main.exe �ڶ��������� Tomcat ������������ -h ���ĸ���������־·������־�� 
{
	char server[SERVER_LEN] = {'\0'};//�洢�����в����ڶ������� ����Tomcat 
	//char form = '\0';//���������е��������� ����-h -m -s
	char log[LOGPATH_LEN] = {'\0'}; //���������е��ĸ����� ��־·��
	
	//char *SERVERS[SERVERS_COUNT] = {"Tomcat", "Weblogic", "JBoss"};
	
	if (PARAMS_COUNT != argc)//������������������ 
	{
		Help();
		return 0;
	}
	
	printf("��һ��������: %s, �ڶ���������: %s, ������������: %s\n", argv[1], argv[2], argv[3]);
	
	if( 0 == strcmp(argv[1], "Tomcat") )
	{
		Tomcat(argv[2], argv[3]);
	}
	else if( 0 == strcmp(argv[1], "Nginx") )
	{
		Nginx(argv[2], argv[3]);
	}
	else if( 0 == strcmp(argv[1], "Weblogic") )
	{
		Weblogic(argv[2], argv[3]);
	}
	else if( 0 == strcmp(argv[1], "JBoss") )
	{
		JBoss(argv[2], argv[3]);
	}
	else
	{
		//���� 
	}
	
	puts("��ӭʹ��, �ټ�!");
    system("pause");
    
	return 0;
}


