#include "lang.h"
#include "../ush-low.h"

void
USH_COMMAND_FOR(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	int c = ush_cell_get_count(*inp);
	if (c!=4) {
		ush_set_error(u,"For needs 4 arguments.");
		return;
	}
	
	const char *st =ush_cell_get_string((*inp));
	const char *ck =ush_cell_get_string((*inp)->next);
	const char *nx =ush_cell_get_string((*inp)->next->next);
	ush_cell_t *bd =(*inp)->next->next->next;
	
	/* Execute first. */
	if(st) {
		ush_eval_str(u,st,out);
		ush_cell_del(*out);
		*out = NULL;
	}
	
	while(1) {
		
		/* Check conditional. */
		if(ck) {
			ush_cell_t *nc = ush_parse(u,ck);
			c = ush_integer(&nc);
			ush_cell_del(nc);
			if(!c) break;
		}
		
		/* Evaluate body. */
		USH_COMMAND_BLOCK(u,&bd,out);
		ush_cell_del(*out);
		*out = NULL;
		ush_clr_flag(u,'c');
		if(ush_pop_flag(u,'b')) break;
		
		/* Evaluate next. */
		if(nx) {
			ush_eval_str(u,nx,out);
			ush_cell_del(*out);
			*out = NULL;
		}
	}
}
