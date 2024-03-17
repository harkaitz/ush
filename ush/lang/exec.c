#include "../ush-low.h"

void
USH_COMMAND_EXEC(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	int c = ush_cell_get_count(*inp);
	if(c<2) { ush_set_error(u,"Exec at least needs 2 arguments."); return; }
	
	/* Get cmd. */
	const char *cmd_name = ush_cell_get_string((*inp));
	ush_cell_t *cmd = ush_cell_get(u,cmd_name);
	if(!cmd) { ush_set_error(u,"Command `%s` not found.",(cmd_name)?cmd_name:"-"); return; }
	
	/* Get body. */
	u->level++;
	int i = 1;
	for(ush_cell_t *var=(*inp)->next;var;var=var->next) {
		snprintf(var->name,sizeof(var->name)-1,"%i",i++);
	}
	ush_eval_str(u,ush_cell_get_string(cmd),out);
	u->level--;
}

