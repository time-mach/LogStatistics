#include <stdio.h>
#include "Tomcat.h"

void Tomcat(char *pForm, char *pLog)
{
	switch (*(pForm + 1))
	{
	case 'h':
		Tomcat_h(pLog);
		break;
	case 'm':
		Tomcat_m(pLog);
		break;
	case 's':
		Tomcat_s(pLog);
		break;
	default:
		printf("参数不对\n");
		break;
	}
	
	return;
}

