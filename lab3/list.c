#include <stdlib.h>
#include <stdio.h>

struct maillon {
	int valeur;
	struct maillon *next;
};

struct liste {
	struct maillon *head;
};

void new_list(struct liste *l) {
	l->head = NULL;
}

void add_first(int valeur, struct liste *l) {
	struct maillon *nouveau = malloc(sizeof(struct maillon));
	nouveau->valeur = valeur;
	nouveau->next = l->head;
	l->head = nouveau;
}

/* Alexis */
void add_tail(int valeur, struct liste *l) {
	struct maillon *nouveau = malloc(sizeof(struct maillon));
	nouveau->valeur = valeur;
	nouveau->next = NULL;

	if ( l->head == NULL ) {
		l->head = nouveau;
		return;
	}

	/* trouver la fin */
	struct maillon *curseur = l->head;
	while (curseur->next != NULL ) {
		curseur = curseur->next;
	}

	curseur->next = nouveau;
}

void show_list(const struct liste *l) {
	struct maillon *curseur;
	for(curseur = l->head; curseur != NULL; curseur = curseur->next) {
		printf("%d\n", curseur->valeur);
	}
}

/* Alexis */
int list_size(const struct liste *l) {
	int size = 0;
	struct maillon *curseur;
	for(curseur = l->head; curseur != NULL; curseur = curseur->next) {
		size ++;
	}
	return size;
}

/* Alexis */
struct maillon *list_head(const struct liste *l) {
	return l->head;
}

/* Alexis */
struct maillon *list_tail(const struct liste *l) {
	if ( l->head == NULL ) {
		return NULL;
	}

	/* trouver la fin */
	struct maillon *curseur = l->head;
	while (curseur->next != NULL ) {
		curseur = curseur->next;
	}

	return curseur;
}

/* Alexis */
void list_remove_head(struct liste *l) {
	if ( l->head == NULL ) {
		fprintf( stderr, "Error: trying to delete head of an empty list" );
		exit(1);
	}

	struct maillon *old_head = l->head;
	l->head = l->head->next;
	free( old_head );
}

/* Alexis */
void list_remove_tail(struct liste *l) {
	if ( l->head == NULL ) {
		fprintf( stderr, "Error: trying to delete tail of an empty list" );
		exit(1);
	}

	struct maillon *curseur = l->head;

	/* If there is only 1 element */
	if ( curseur->next == NULL ) {
		free( l->head );
		l->head = NULL;
		return;
	}

	while (curseur->next->next != NULL ) {
		curseur = curseur->next;
	}

	/* curseur->next is the tail */
	free( curseur->next );
	curseur->next = NULL;
}

int main(void) {
	struct liste l;
	new_list(&l);
	add_first(1, &l);
	show_list(&l);

	printf( "#1\n" );
	add_tail(2, &l);
	add_first(-10, &l);
	show_list(&l);

	printf( "#2\n" );
	list_remove_tail(&l);
	show_list(&l);

	return 0;
}
