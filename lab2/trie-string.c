// 03-tableaux.pdf page 23

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*! Échange la position deux pointeurs de chaînes de caractères
*
* \param pa Premier élément à échanger
* \param pb Deuxième élément à échanger
*/
void swap(char **pa, char **pb) {
	char *tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

/*! Trie un tableau avec strcmp et la fonction swap
*
* \param tab Tableau a trier
* \param size Taille du tableau
*/
void sort(char **tab, size_t size) {
	size_t i,j,k;
	for(i=0;i<size;i++) {
		/* invariant: tab[0] Ã  tab[i-1] est bien triÃ©
		 * maintenant, on va cherche la bonne valeur de tab[i]
		 * dans tab[i]..tab[size-1] */
		k = i;
		for(j=i+1; j<size; j++) {
			if (strcmp(tab[j], tab[k]) < 0)
				k = j;
		}
		swap(&tab[i],&tab[k]);
	}
}

/*! \brief Programme triant les mots passés en argument
*
* Usage: trie-string mot0 [mot1 [mot2 [...]]]
*
* Affiche le mots entrés en ordre lexicographique sur la sortie standard.
*
* \return Code d'erreur
*/
int main(int argc, char **argv) {

	char **tab = argv+1;
	int tabc = argc -1;

	if ( tabc <= 0 ) {
		printf( "Usage: %s mot0 [mot1 [mot2 [...]]]\n", argv[0] );
		return 1;
	} else {
		sort( tab, tabc );

		int i;
		for ( i = 0; i < tabc; i ++ )
			printf( "%s, ", tab[i] );

		printf( "\n" );
		return 0;
	}
}

