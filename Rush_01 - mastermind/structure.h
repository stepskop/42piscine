typedef struct s_brdrs
{
	int *top;
	int *bottom;
	int	*left;
	int *right;
} t_brdrs;

typedef struct s_cell
{
	int x;
	int y;
	int value;
	int only_op;
	int *opts;
	int tries;
} t_cell;

typedef	struct s_table 
{
	int size;
	t_brdrs borders;
	t_cell **cells;
} t_table;