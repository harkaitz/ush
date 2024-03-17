#include "../ush-low.h"

void
USH_COMMAND_EXIT(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	ush_set_flag(u,'q'); ush_set_flag(u,'b');
}
