#include "list.h"
#include <CUnit/Basic.h>

void test_creation() {
	struct liste l;
	new_list(&l);

	CU_ASSERT( list_size( &l ) == 0 );
}

void test_insertion() {
	struct liste l;
	new_list(&l);

	add_first( 3, &l );
	add_first( 2, &l );
	add_tail( 4, &l );
	add_tail( 5, &l );
	add_first( 1, &l );

	CU_ASSERT( list_size( &l ) == 5 );
}

void test_avec_erreur() {
	CU_ASSERT( 0 == 1 );
}

void test_effacer() {
	struct liste l;
	new_list(&l);

	add_tail( 1, &l );
	add_tail( 2, &l );
	add_tail( 3, &l );
	add_tail( 4, &l );

	CU_ASSERT( list_size( &l ) == 4 );

	list_remove_head( &l );

	CU_ASSERT( list_size( &l ) == 3);
	CU_ASSERT( list_head(&l) != NULL);
	CU_ASSERT( list_head(&l)->valeur == 2 );

	list_remove_tail( &l );

	CU_ASSERT( list_size( &l ) == 2);
	CU_ASSERT( list_tail(&l) != NULL);
	CU_ASSERT( list_tail(&l)->valeur == 3 );
}

int main() {
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	  return CU_get_error();

	/* add a suite to the registry */
	pSuite = CU_add_suite("Test list base", NULL, NULL ); // init_suite1, clean_suite1);
	if (NULL == pSuite)
		goto erreur;

	/* add the tests to the suite */
	if ((NULL == CU_add_test(pSuite, "tests de création", test_creation)) ||
	   (NULL == CU_add_test(pSuite, "test d'insertion", test_insertion)) ||
	   (NULL == CU_add_test(pSuite, "test avec erreur", test_avec_erreur)) ||
	   (NULL == CU_add_test(pSuite, "test effacer", test_effacer)))
		goto erreur;

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

erreur:
	CU_cleanup_registry();
	return CU_get_error();
}
