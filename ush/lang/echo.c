#include "../ush-low.h"

void
USH_COMMAND_ECHO(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	if(!(*inp)) return;
	const char *s = ush_cell_get_string(*inp);
	if(s) ush_printf(u,1,"%s%c",s,((*inp)->next)?' ':'\n');
	return USH_COMMAND_ECHO(u,&((*inp)->next),out);
}

