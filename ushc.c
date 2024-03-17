#include <stdio.h>
#include "ush/ush.h"

int
main(int argc,char *argv[])
{
	ush_t ush; int ret = 1;
	
	ush_init(&ush);
	ush_library_init(&ush);
	
	if(argc==1) {
		ush_set_string(
		    &ush,
		    "MESSAGE",
		    "\n"
		    "uSh - A small, extensible interpreter."                    "\n"
		    "Copyright (c) 2018, Harkaitz Agirre, All rights reserved." "\n"
		    ""                                                          "\n"
		    "It's not finished, but you can test it. Try;"              "\n"
		    "--------------------------------\n"
		    "  if (== (+ 2 2) 5) {       \n"
		    "      echo \"No No\"        \n"
		    "  } else {                  \n"
		    "      echo Hurray!!         \n"
		    "  }                         \n"
		    "-------------------------------\n"
		    "Type `exit` without quotes to quit.\n",
		    0
		);
		ush_loop(&ush,(void*)getc,stdin);
		ret = 0;
	}
#       if defined(__unix__) || defined(_WIN32) 
	else {
		FILE *fp = fopen(argv[1],"rb");
		if(fp) {
			ush_clr_flag(&ush,'i');
			ush_loop(&ush,(void*)getc,fp);
			fclose(fp);
			ret = 0;
		} else {
			ush_set_error(&ush,"Can't open `%s`.",argv[1]);
			ret = 1;
		}
	}
#       endif
	ush_clean(&ush);
	return ret;
}
