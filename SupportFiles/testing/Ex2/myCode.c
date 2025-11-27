#include<stdio.h>
#include"module1.h"
#include"testUnit.h"
#include<CUnit/CUnit.h>
#include<CUnit/Basic.h>
int main(void)
{
	CU_initialize_registry();
	CU_pSuite suite1=CU_add_suite("mod1_test",0,0);
	CU_add_test(suite1,"test1_maxiFunc",test_maxi);
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return 0;
}


