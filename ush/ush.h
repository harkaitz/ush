#ifndef _USH_H_
#define _USH_H_

#include "config.h"
#include <stdio.h>
#include <string.h>

typedef struct ush_s      ush_t;
typedef struct ush_cell_s ush_cell_t;
typedef void (*ush_cmd_t) (ush_t *,ush_cell_t **,ush_cell_t **);

struct ush_cell_s {
	char	 type; /* l:Last d:Deleted n:None m:Malloc s:String c:Command */
	char	 name[USH_NAME_MAXIMUN_LENGTH];
	int	 level;
	struct	 ush_cell_s *next;
	int	 length;
	struct	 ush_s *ush;
	union {
		char		const *s;
		char		*m;
		ush_cmd_t	 c;
	} d;
};

struct ush_s {
	FILE	*fp[3];
	int	 level;
	char	 flags[10];
	struct	 ush_cell_s cells[USH_MAX_VARIABLES];
	char	 err[USH_ERR_MAXIMUN_LENGTH];
	
	/* Terminal. */
	struct {
		int	start;
		struct	ush_cell_s *lst;
	} t;

	/* Parser. */
	struct {
		int	escape;
		int	level;
		char	level_up;
		char	level_dw;
		int	point;
		char	buffer[256];
	} p;
};

/* [base.c] [lists.c] */
extern void	 ush_init(ush_t *);
extern void	 ush_clean(ush_t *);
extern void	 ush_set_error(ush_t *, const char *,...);
extern void	 ush_printf(ush_t *,int, const char *, ...);
extern char	*ush_tst_flag(ush_t *,char);
extern void	 ush_set_flag(ush_t *,char);
extern void	 ush_clr_flag(ush_t *,char);
extern char	*ush_pop_flag(ush_t *,char);
extern int	 ush_cell_count(ush_t *);
extern int	 ush_add_command(ush_t *, const char [],ush_cmd_t);
extern char	const *ush_get_string(ush_t *,const char []);
extern char	const *ush_set_string(ush_t *,const char [],const char [],int);

/* [term.c] */
extern void	ush_print_prompt(ush_t *);
extern void	ush_loop(ush_t *, int (*) (void *),void *);
extern int	ush_eat(ush_t *, char);
extern void	ush_eval_str(ush_t *, const char *, ush_cell_t **);

/* [numbers.c] */
extern int	ush_integer(ush_cell_t **inp);

/* [lang/] */
extern void	ush_library_init(ush_t *);

#endif
