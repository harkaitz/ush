#include "lang.h"
#include "../ush-low.h"

void
ush_library_init(ush_t *ush) {
	ush_add_command(ush,"echo",USH_COMMAND_ECHO);
	ush_add_command(ush,"exit",USH_COMMAND_EXIT);
	ush_add_command(ush,"quit",USH_COMMAND_EXIT);
	ush_add_command(ush,"%"   ,USH_COMMAND_EXPAND);
	ush_add_command(ush,"set" ,USH_COMMAND_SET);
	
	ush_add_command(ush,"eval"   ,USH_COMMAND_EVAL);
	ush_add_command(ush,"if"     ,USH_COMMAND_IF);
	ush_add_command(ush,"elseif" ,USH_COMMAND_IF);
	ush_add_command(ush,"elif"   ,USH_COMMAND_IF);
	ush_add_command(ush,"else"   ,USH_COMMAND_EVAL);
	
	ush_add_command(ush,"foreach" ,USH_COMMAND_FOREACH);
	ush_add_command(ush,"for"     ,USH_COMMAND_FOR);
	ush_add_command(ush,"while"   ,USH_COMMAND_WHILE);
	ush_add_command(ush,"continue",USH_COMMAND_CONTINUE);
	ush_add_command(ush,"break"   ,USH_COMMAND_BREAK);
	
	ush_add_command(ush,"proc"    ,USH_COMMAND_PROC);
	ush_add_command(ush,"exec"    ,USH_COMMAND_EXEC);
	
	ush_add_command(ush,"error"    ,USH_COMMAND_ERROR);
}

