set(ush_SOURCES

  ## Lang
  lang/lang.c
  lang/cmd.c   lang/cat.c    lang/proc.c  lang/continue.c
  lang/for.c   lang/break.c  lang/error.c lang/foreach.c
  lang/exit.c  lang/if.c     lang/seq.c   lang/equal.c
  lang/block.c lang/while.c  lang/exec.c  lang/expand.c
  lang/eval.c  lang/exists.c lang/echo.c  lang/set.c
  
  ## Core.
  numbers.c
  term.c
  parser.c
  lists.c
  base.c
)
set(ush_HEADERS
  ush.h ush-low.h lang/lang.h
)

add_library(ush STATIC ${ush_SOURCES} ${ush_HEADERS})
install(TARGETS ush DESTINATION lib)
install(FILES ${ush_HEADERS} DESTINATION include/ush)

