#include "../ush-low.h"

void
USH_COMMAND_CMD(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	ush_eval(inp);
	*out = *inp;
	*inp = NULL;
}
