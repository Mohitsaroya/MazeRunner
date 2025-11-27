#include<CUnit/CUnit.h>
#include"module1.h"
#ifndef __testUnit_C
#define __testUnit_C
void test_maxi(void)
{
	CU_ASSERT(maxi(0,2)==2);
	
}
#endif

