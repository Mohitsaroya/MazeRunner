#include<string.h>
#ifndef __module1_C
#define __module1_C
int maxi(int i1, int i2)
{
	return (i1>i2) ? i1 : i2;
}

void divFun(float x, float y, float * res, char *divStr)
{
	if( x==0)strcpy(divStr,"InValid");
	else{strcpy(divStr,"Valid");
	     *res=y/x;}	
	return;
}
#endif


