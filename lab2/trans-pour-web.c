#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *remplacer_pour_web( const char *ori );

/*! \brief Programme traduisant une chaîne de caractères pour le web
*
* \return Code d'erreur
*/
int main( int argc, char **argv ) {
	if ( argc == 2 ) {
		char *chaine_traite = remplacer_pour_web( argv[1] );
		printf( "%s\n", chaine_traite );
		return 0;
	}
	else {
		printf( "Usage: %s chaine\n", argv[0] );
		return 1;
	}
}

/*! \brief Traduit une chaîne de caractères pour le web
*
* \param ori Chaîne de caractère d'origine (ne sera pas modifiée)
* \return Chaîne de caractère modifiée
*/
char *remplacer_pour_web( const char *ori ) {

	// trouver futur taille
	int nouv_taille = 0;
	int i;
	int ori_taille = strlen( ori );

	for ( i = 0; i < ori_taille; i ++ ) {
		char c = ori[i];

		nouv_taille ++;
		if ( c == '&' ) nouv_taille += 4;
		if ( c == '<' ) nouv_taille += 3;
	}

	// générer nouvelle chaine
	char *nouv = malloc( nouv_taille + 1 );
	int n = 0;
	for ( i = 0; i < ori_taille; i ++ ) {
		char c = ori[i];
		if ( c == '<' ) {
			nouv[n++] = '&';
			nouv[n++] = 'l';
			nouv[n++] = 't';
			nouv[n++] = ';';
		}
		else if ( c == '&' ) {
			nouv[n++] = '&';
			nouv[n++] = 'a';
			nouv[n++] = 'm';
			nouv[n++] = 'p';
			nouv[n++] = ';';
		}
		else {
			nouv[n++] = c;
		}
	}

	nouv[n] = '\0';

	return nouv;
}
