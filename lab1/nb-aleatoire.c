#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main( int argc, char **argv )
{
	int max;
	int valeurs_lues = 1;

	srand( time(NULL) );

	while ( valeurs_lues == 1 ) {
		printf( "Entrez un nombre: " );
		valeurs_lues = scanf( "%d", &max );
		if ( valeurs_lues == 1 ) {
			int aleatoire = rand(); // entre 0 et RAND_MAX
			int aleatoire_avec_max = aleatoire/(RAND_MAX/max);
			printf( "-> %d\n", aleatoire_avec_max );
		}
	}

	return 0;
}
