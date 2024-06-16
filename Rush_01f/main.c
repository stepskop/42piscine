#include "structure.h"
#include <unistd.h>
#include <stdio.h>

char *read_br(char *s);

t_border fill_br(char *str);

void def_grid(t_cell c[4][4]);

void	solve(t_border b, t_cell c_arr[4][4]);

int	main(int argc, char *argv[])
{
	t_cell cells[4][4];
	t_border border;

	if (argc == 2 && *read_br(argv[1]))
	{
		border = fill_br(read_br(argv[1]));
		def_grid(cells);
		solve(border, cells);
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}	
}

