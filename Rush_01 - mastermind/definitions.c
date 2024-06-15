
#include "structure.h"
#include <stdlib.h>

t_cell	**def_cells(int size)
{
	t_cell **cells;
	int i;
	int j;

	cells = malloc(size*size);
	i = 0;
	while (i < size)
	{
		cells[i] = malloc(size);
		j = 0;
		while (j < size)
		{
			cells[i][j].value = 0;
			cells[i][j].y = i;
			cells[i][j].x = j;
			cells[i][j].only_op = 0;
			cells[i][j].tries = 0;
			j++;
		}
		i++;
	}
	return (cells);
}

t_brdrs def_brdrs(int size, int **borders)
{
	t_brdrs b;
	int	i;

	i = 0;
	b.top = malloc(size);
	b.bottom = malloc(size);
	b.left = malloc(size);
	b.right = malloc(size);
	while (i < size)
	{
		b.top[i] = borders[0][i];
		b.bottom[i] = borders[1][i];
		b.left[i] = borders[2][i];
		b.right[i] = borders[3][i];
		i++;
	}
	return (b);
}