#include "../ush-low.h"


void
USH_COMMAND_SET(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	
	ush_cell_t *fnd = NULL;
	const char *var = ush_cell_get_string (*inp);
	const char *val = ush_cell_get_string ((*inp)->next);
	
	if(!var) { // 0 args
		ush_set_error(u,"set VAR [VAL]");
	} else if(!val) { // 1 args
		val = ush_cell_get_string(ush_cell_get(u,var));
		if(val) {
			*out = ush_cell_new(u);
			ush_cell_set_malloc(*out,val,-1);
		} else {
			ush_set_error(u,"Variable `%s` not found.",var);
		}
	} else if((fnd = ush_cell_get(u,var))) { // 2 args, already exists.
		ush_cell_set_malloc(fnd,val,-1);
	} else { // 2 args, new.
		ush_cell_set_name((*inp)->next,var);
		(*inp)->next = (*inp)->next->next;
	}
	
	return;
}
