#include "../ush-low.h"

void
USH_COMMAND_EXPAND(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	*out = *inp;
	*inp = NULL;
}
