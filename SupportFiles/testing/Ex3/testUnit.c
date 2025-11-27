#include<stdlib.h>
#include<string.h>
#include<CUnit/CUnit.h>
#include"module1.h"
#ifndef __testUnit_C
#define __testUnit_C
void test_maxi(void)
{
	CU_ASSERT(maxi(0,2)==2);
	CU_ASSERT(maxi(0,-2)==0);
	CU_ASSERT(maxi(2,2)==2);
}
void test_divFun(void)
{
	float x1=2,y1=4;
	float *resPtr=malloc(sizeof(float));
	char *validityPtr=malloc(10*sizeof(char));
	divFun(x1,y1,resPtr,validityPtr);
	
	CU_ASSERT(*resPtr==2);
	CU_ASSERT(strcmp(validityPtr,"Valid")==0);

	x1=0; y1=5;
	divFun(x1,y1,resPtr,validityPtr);
	CU_ASSERT(strcmp(validityPtr,"InValid")==0);
}
#endif

