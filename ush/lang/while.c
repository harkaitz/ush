#include "lang.h"
#include "../ush-low.h"

void
USH_COMMAND_WHILE(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	int c = ush_cell_get_count(*inp);
	if(c!=2) { ush_set_error(u,"While needs 2 arguments."); return; }
	ush_cell_t *ck = (*inp);
	ush_cell_t *bd = (*inp)->next;
	(*inp) = ush_cell_new(u);
	(*inp)->next = ck;
	(*inp)->next->next = ush_cell_new(u);
	(*inp)->next->next->next = bd;
	return USH_COMMAND_FOR(u,inp,out);
}
