#include "ush-low.h"
#include <stdlib.h>

int   ush_i_asg(int   a,int   b) { return b; }

int   ush_i_sum(int   a,int   b) { return a + b; }

int   ush_i_div(int   a,int   b) { return a / b; }

int   ush_i_mod(int   a,int   b) { return a % b; }
int   ush_i_mul(int   a,int   b) { return a * b; }


int   ush_i_and(int   a,int   b) { return a && b; }
int   ush_i_or (int   a,int   b) { return a || b; }
int   ush_i_not(int   a,int   b) { return ! b;    }

int   ush_i_eql(int   a,int   b) { return a == b; }
int   ush_i_eqg(int   a,int   b) { return a >= b; }
int   ush_i_eqs(int   a,int   b) { return a <= b; }
int   ush_i_gre(int   a,int   b) { return a > b;  }
int   ush_i_sma(int   a,int   b) { return a < b;  }

static struct {
     const char *op;
     int         as;
     int   (*fi) (int   a,int   b);
     
} ops[] = {
     {"=",0,ush_i_asg},
     {"+",0,ush_i_sum},
     {"/",1,ush_i_div},
     {"%",1,ush_i_mod},
     {"*",1,ush_i_mul},
     
     
     {"&&",1,ush_i_and},
     {"||",1,ush_i_or },
     {"!" ,0,ush_i_not},
     
     {"==",1,ush_i_eql},
     {">=",1,ush_i_eqg},
     {"<=",1,ush_i_eqs},
     {">" ,1,ush_i_gre},
     {"<" ,1,ush_i_sma},

     {NULL}
};

int ush_integer(ush_cell_t **inp)
{
	int ret = 0; int asg;
	
	/* Get operation. */
	const char *s = ush_cell_get_string(*inp);
	if(!s) {
		return ret;
	}
	
	/* Search operation. */
	int (*fi) (int a,int b) = ops[0].fi;
	ush_cell_t *p = *inp;
	for (int i=0; ops[i].op; i++) {
		
		if(!ops[i].fi) {
			continue;
		}
		
		if(!strcasecmp(ops[i].op,s)) {
			fi = ops[i].fi;
			p  = (*inp)->next;
			asg= ops[i].as;
		}
	}
	
	/* Assign the first one if needed. */
	if(asg) {
		ret = ush_cell_get_integer(p);
		p = p->next;
	}
	
	/* The rest. */
	for(; p; p=p->next) {
		ret = fi(ret,ush_cell_get_integer(p));
	}
	
	return ret;
}

