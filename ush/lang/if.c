#include "lang.h"
#include "../ush-low.h"

void
USH_COMMAND_IF(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	ush_cell_t *p = *inp;
	if(ush_cell_get_integer(p)) {
		p = p->next;
		return USH_COMMAND_EVAL(u, &p, out);
	} else if((p = p->next)) {
		return USH_COMMAND_CMD(u, &(p->next), out);
	}
}
