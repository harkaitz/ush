#include "../ush-low.h"

void
USH_COMMAND_PROC(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	int c = ush_cell_get_count(*inp);
	if (c<3) {
		ush_set_error(u,"Proc at least needs 3 arguments.");
		return;
	}
	const char *cmd_name = ush_cell_get_string(*inp);
	if(cmd_name) {
		ush_cell_t *body = (*inp)->next->next;
		ush_cell_del(ush_cell_get(u,cmd_name));
		ush_cell_set_name(body,cmd_name);
		*out = *inp; *inp= (*out)->next;
		(*inp)->next = NULL;
	}
}
