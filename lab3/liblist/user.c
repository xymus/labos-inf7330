#include <stdlib.h>
#include <stdio.h>

#include "list.h"

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
