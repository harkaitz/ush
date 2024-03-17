#include "../ush-low.h"

void
USH_COMMAND_BLOCK(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	ush_eval_str(u,ush_cell_get_string(*inp),out);
}
