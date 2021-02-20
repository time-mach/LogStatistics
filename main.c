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

int main(int argc,char *argv[]) //比方输入main.exe Tomcat -h /localhost_access_2020-01-01.txt,  argc就是4, 第一个参数是main.exe 第二个参数是 Tomcat 第三个参数是 -h 第四个参数是日志路径和日志名 
{
	char server[SERVER_LEN] = {'\0'};//存储命令行参数第二个参数 比如Tomcat 
	//char form = '\0';//接收命令行第三个参数 比如-h -m -s
	char log[LOGPATH_LEN] = {'\0'}; //接收命令行第四个参数 日志路径
	
	//char *SERVERS[SERVERS_COUNT] = {"Tomcat", "Weblogic", "JBoss"};
	
	if (PARAMS_COUNT != argc)//如果输入参数个数有误 
	{
		Help();
		return 0;
	}
	
	printf("第一个参数是: %s, 第二个参数是: %s, 第三个参数是: %s\n", argv[1], argv[2], argv[3]);
	
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
		//扩充 
	}
	
	puts("欢迎使用, 再见!");
    system("pause");
    
	return 0;
}


