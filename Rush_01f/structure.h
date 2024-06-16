typedef struct s_border
{
	int *top;
	int *bottom;
	int	*left;
	int *right;
	int size;
} t_border;

typedef struct s_cell
{
	int x;
	int y;
	int value;
} t_cell;