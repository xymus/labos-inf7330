#include <stdlib.h>
#include <stdio.h>

struct maillon {
	int valeur;
	struct maillon *next;
};

struct liste {
	struct maillon *head;
};

void new_list(struct liste *l);

void add_first(int valeur, struct liste *l);

void add_tail(int valeur, struct liste *l);

void show_list(const struct liste *l);

int list_size(const struct liste *l);

struct maillon *list_head(const struct liste *l);

struct maillon *list_tail(const struct liste *l);

void list_remove_head(struct liste *l);

void list_remove_tail(struct liste *l);
