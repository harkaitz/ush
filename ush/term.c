#include "ush-low.h"
#include <string.h>

void
ush_print_prompt(ush_t *ush)
{
	if ( ush_tst_flag(ush,'i') || ush_tst_flag(ush,'p') ) {
		const char *prompt = ush_get_string(ush,(ush->t.start)?"PS1":"PS2");
		if (!prompt) {
			prompt = (ush->t.start)?"%02i> ":"    ";
		}
		ush_printf(ush,2,prompt,ush_cell_count(ush));
		fflush(ush->fp[1]); fflush(ush->fp[2]);
	}
}

int
ush_eat(ush_t *ush, char c)
{
	if (!ush->t.lst) {
		ush->t.lst = ush_cell_new(ush);
	}
	
	if (ush_parser_add_chr(ush,ush->t.lst,c,ush->t.start)) {
		ush_eval(&(ush->t.lst->next));
		if (ush_tst_flag(ush,'i')) {
			for (ush_cell_t *i=ush->t.lst; i; i=i->next) {
				const char *s = ush_cell_get_string(i);
				if (s) {
					ush_printf(ush,1,"%s\n",s);
				}
			}
		}
		ush_cell_del(ush->t.lst);
		ush->t.lst = NULL;
		ush->t.start = 1;
		ush_clr_flag(ush,'b');
		ush_clr_flag(ush,'c');
		if(ush_pop_flag(ush,'e') && (!ush_tst_flag(ush,'i'))) {
			return 0;
		}
	} else {
		ush->t.start = 0;
	}
	
	if (ush_tst_flag(ush,'q')) {
		return 0;
	}
	
	if (c=='\n') {
		ush_print_prompt(ush);
	}
	return 1;
}

void
ush_eval_str(ush_t *u,const char *str,ush_cell_t **out)
{
	ush_cell_t *lst = ush_cell_new(u); int start = 1;
	
	for (const char *c=str;;c++) {
		if (ush_parser_add_chr(u, lst, *c, start)) {
			ush_eval(&(lst->next));
			// ush_cell_print(lst,stdout);
			if (*out) {
				ush_cell_del(*out);
			}
			*out = lst->next; lst->next = NULL;
			start = 1;
		} else {
			start = 0;
		}
		if(!*c) {
			break;
		}
		if( ush_tst_flag(u,'q') ||
		    ush_tst_flag(u,'b') ||
		    ush_tst_flag(u,'c') ||
		    ush_tst_flag(u,'e')) {
			break;
		}
	}
	ush_cell_del(lst);
}

void
ush_loop(ush_t *ush,int (*gc) (void *),void *u)
{
	if(ush_tst_flag(ush,'i')) {
		const char *msg = ush_get_string(ush,"MESSAGE");
		if(msg) {
			ush_printf(ush,2,"%s\n",msg);
		}
	}
	ush_print_prompt(ush);
	for(int c=gc(u);c!=EOF;c=gc(u)) {
		if(!ush_eat(ush,c)) {
			break;
		}
	}
}
