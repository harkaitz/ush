#include "../ush-low.h"

void
USH_COMMAND_CAT(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	int l = 0;
	
	/* Calculate size. */
	for(ush_cell_t *i=*inp;i;i=i->next) {
		const char *s = ush_cell_get_string(i);
		l += (s)?strlen(s):0;
	}
	/* Create new cell. */
	//// TODO.
}
