#include "../ush-low.h"

void
USH_COMMAND_ERROR(ush_t *u, ush_cell_t **inp, ush_cell_t **out)
{
	char buffer[sizeof(u->err)]; buffer[0]='\0';
	for(ush_cell_t *c=*inp;c;c=c->next) {
		const char *s = ush_cell_get_string(c);
		if(s) {
			strncat(buffer,s,sizeof(buffer)-1);
			strncat(buffer,(c->next)?" ":"",sizeof(buffer)-1);
		}
	}
	ush_set_error(u,"%s",buffer);
}
