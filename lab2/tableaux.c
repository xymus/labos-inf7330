// 03-tableaux.pdf page 18

#include<stdio.h>
#include<stdlib.h>

int main( int argc, char **argv ) {

	int t1[5] = {10, 20, 30, 40, 50} ;
	printf("%p %ld\n", t1, sizeof(t1)) ;
	// 0x7fff75c2acf0 20

	printf("%p %ld\n", &t1, sizeof(&t1)) ;
	// 0x7fff75c2acf0 8

	printf("%d %ld\n", t1[0], sizeof(t1[0])) ;
	// 10 4

	int *t2 = t1 ; // t2 -> t1
	printf("%p %ld\n", t2, sizeof(t2)) ;
	// 0x7fff75c2acf0 8

	printf("%d %ld\n", t2[0], sizeof(t2[0])) ;
	// 10 4

	int **t3 = &t2 ; // t3 -> t2 -> t1
	printf("%p %ld\n", t3, sizeof(t3)) ;
	// 0x7fff75c2acc8 8

	printf("%p %ld\n", t3[0], sizeof(t3[0])) ;
	// 0x7fff75c2acf0 8

	int *t4[2] = { t2, NULL } ;
	printf("%p %ld\n", t4, sizeof(t4)) ;
	// 0x7fff75c2ace0 16

	printf("%p %ld\n", t4[0], sizeof(t4[0])) ;
	// 0x7fff75c2acf0 8

	int (*t5)[5] = &t1 ;
	printf("%p %ld\n", t5, sizeof(t5)) ;
	// 0x7fff75c2acf0 8

	printf("%p %ld\n", t5[0], sizeof(t5[0])) ;
	//0x7fff75c2acf0 20

	return 0;
}
