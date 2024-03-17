#ifndef _USH_LOW_H_
#define _USH_LOW_H_

#include "ush.h"

/* [base.c] [lists.c] */

extern ush_cell_t	*ush_cell_new(ush_t *);
extern void		 ush_cell_del(ush_cell_t *);
extern ush_cell_t	*ush_cell_get(ush_t *, const char []);

extern int	ush_cell_set_empty(ush_cell_t *);
extern int	ush_cell_set_name(ush_cell_t *, const char []);
extern int	ush_cell_set_string(ush_cell_t *, const char []);
extern int	ush_cell_set_malloc(ush_cell_t *, const void *, int);
extern int	ush_cell_set_command(ush_cell_t *, ush_cmd_t);

extern void	   ush_cell_string_to_malloc(ush_cell_t *);
extern char const *ush_cell_get_string(ush_cell_t *);
extern int	   ush_cell_get_integer(ush_cell_t *);
extern int	   ush_cell_get_count(ush_cell_t *);

extern void	ush_cell_append(ush_cell_t *, ush_cell_t *);
extern void	ush_cell_print(ush_cell_t *, FILE *);

#define USH_FOREACH_CELL_ALL(C,U) \
     for(ush_cell_t *C = (U)->cells; (C)->type != 'l'; (C)++)
#define USH_FOREACH_CELL_EMPTY(C,U) \
     USH_FOREACH_CELL_ALL(C,U) if((C)->type == 'd')
#define USH_FOREACH_CELL(C,U) \
     USH_FOREACH_CELL_ALL(C,U) if((C)->type != 'd')

/* [parser.c] */
extern ush_cell_t *ush_parser_add_chr(ush_t *, ush_cell_t *, char, int);
extern ush_cell_t *ush_parse(ush_t *, const char []);
extern void	   ush_eval(ush_cell_t **);

#endif
