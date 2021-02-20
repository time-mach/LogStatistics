#include <stdio.h>
#include "Nginx.h"

void Nginx(char *pForm, char *pLog)
{
	switch (*(pForm + 1))
	{
	case 'h':
		Nginx_h(pLog);
		break;
	case 'm':
		Nginx_m(pLog);
		break;
	case 's':
		Nginx_s(pLog);
		break;
	default:
		printf("参数不对\n");
		break;
	}
	
	return;
}

