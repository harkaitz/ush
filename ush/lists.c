
#include "ush-low.h"
#include <string.h>
#include <stdlib.h>

/* Low level */

int
ush_cell_set_string(ush_cell_t *cell, const char *value)
{
	if(!cell) return 0;
	ush_cell_set_empty(cell);
	cell->type = 's';
	cell->d.s = value;
	return 0;
}

void
ush_cell_string_to_malloc(ush_cell_t *cell)
{
	if(!cell) return;
	if(cell->type=='s') {
		ush_cell_set_malloc(cell,cell->d.s,-1);
	}
	return ush_cell_string_to_malloc(cell->next);
}

int
ush_cell_set_command(ush_cell_t *cell, ush_cmd_t c)
{
	if(!cell) return 0;
	ush_cell_set_empty(cell);
	cell->type = 'c';
	cell->d.c = c;
	return 0;
}

void
ush_cell_append(ush_cell_t *cell, ush_cell_t *c2)
{
	if(cell->next) {
		return ush_cell_append(cell->next,c2);
	} else {
		cell->next = c2;
	}
}

void
ush_cell_print(ush_cell_t *cell, FILE *fp)
{
	if(!fp) {
		return;
	}
	if(!cell) {
		fprintf(fp,"|\n");
		return;
	}
	fprintf(fp,"|%c:l=%02i",cell->type,cell->level);
	switch(cell->type) {
	case 's':
		fprintf(fp,":Str=%s",cell->d.s);
		break;
	case 'm':
		if(cell->length==-1) {
			fprintf(fp,":Str=%s",cell->d.m);
		} else {
			fprintf(fp,":Len=%i",cell->length);
		}
		break;
	}
	return ush_cell_print(cell->next,fp);
}

const char *
ush_cell_get_string (ush_cell_t *cell)
{
	if(!cell) {
		return NULL;
	}
	if(cell->type=='s') {
		return cell->d.s;
	} else if(cell->type=='m' && cell->length==-1) {
		return cell->d.m;
	} else {
		return NULL;
	}
}

int
ush_cell_get_integer(ush_cell_t *cell)
{
	const char *s = ush_cell_get_string(cell);
	return (s)?atoi(s):0;
}

int
ush_cell_get_count(ush_cell_t *cell)
{
	int r = 0;
	for (ush_cell_t *c = cell;c;c=c->next) {
		r++;
	}
	return r;
}

/* High level manipulation */

int
ush_add_command(ush_t *ush, const char *name, ush_cmd_t c)
{
	ush_cell_t *cell = ush_cell_new(ush);
	if(!cell) {
		return -1;
	}
	ush_cell_set_name(cell,name);
	ush_cell_set_command(cell,c);
	return 0;
}

const char *
ush_get_string(ush_t *ush, const char *name)
{
	return ush_cell_get_string(ush_cell_get(ush,name));
}

const char *
ush_set_string(ush_t *ush, const char *name, const char *str, int m)
{
	ush_cell_t *cell = ush_cell_get(ush,name);
	if(!cell) {
		cell = ush_cell_new(ush);
		ush_cell_set_name(cell,name);
	}
	
	ush_cell_set_string(cell,str);
	if(m) {
		ush_cell_string_to_malloc(cell);
	}
	
	return ush_cell_get_string(cell);
}
