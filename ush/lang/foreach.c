#include "lang.h"
#include "../ush-low.h"

void
USH_COMMAND_FOREACH(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	const char *var = ush_cell_get_string(*inp);
	if (!var) return;
	
	ush_cell_t *lst = (*inp)->next;
	if (!lst) return;
	
	ush_cell_t *blk;
	for (blk=lst->next; blk->next; blk=blk->next) {
		/* Get last */
	}
	
	for (ush_cell_t *e=lst;e!=blk;e=e->next) {
		ush_cell_set_name(e,var);
		ush_cell_t *ign = NULL;
		USH_COMMAND_BLOCK(u,&blk,&ign); ush_cell_del(ign);
		ush_cell_set_name(e,"");
	}
}

