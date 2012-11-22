#include <stdio.h>

#define minimum(a,b) ( (a)<(b)? (a): (b) )

#define compare(a,b) ( (a)<(b)? -1 : (a)==(b)? 0 : 1 )

#define swap(a,b,t) do { \
	t tmp; \
	tmp = a; \
	a = b; \
	b = tmp; \
} while(0)

int main( ) {
	printf( "minimum: %d\n", minimum( 4, 888 ) );
	printf( "minimum: %d\n", minimum( 332, 45 ) );
	printf( "minimum: %d\n", minimum( 332, -45 ) );

	printf( "compare: %d\n", compare( 4, 888 ) );
	printf( "compare: %d\n", compare( 332, 45 ) );
	printf( "compare: %d\n", compare( 332, 332 ) );

	int x = 12,
		y = 34;
	swap( x, y, int );
	printf( "swap %d %d\n", x, y );

	return 0;
}
