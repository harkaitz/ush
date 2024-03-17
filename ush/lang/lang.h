typedef struct ush_s ush_t;
typedef struct ush_cell_s ush_cell_t;

extern void	USH_COMMAND_BLOCK(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_ECHO(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_EXIT(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_EXPAND(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_SET(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_EVAL(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_IF(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_FOREACH(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_FOR(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_WHILE(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_CONTINUE(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_BREAK(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_PROC(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_EXEC(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_ERROR(ush_t *, ush_cell_t **, ush_cell_t **);
extern void	USH_COMMAND_CMD(ush_t *, ush_cell_t **, ush_cell_t **);


extern void	ush_library_init(ush_t *);
