#include "structure.h"
#include <stdlib.h>

int *get_uniques(t_table t, int x, int y)
{
	int i;
	int j;
	int *arr;

	i = 1;
	arr = malloc(t.size);
	while (i <= t.size)
	{
		j = 0;
		while (j < t.size)
		{
			if (t.cells[x][j].value == i || t.cells[j][y].value == i)
				break ;
			j++;
		}
		if (j == t.size)
			arr[i - 1] = i;
		else
			arr[i - 1] = 0;
		i++;
	}
	return (arr);
}

int check_max(t_table t, t_cell c)
{
	if (t.borders.top[c.x] == t.size && c.value != c.y + 1)
		return (-1);
	if (t.borders.bottom[c.x] == t.size && c.value != t.size - c.y)
		return (-1);
	if (t.borders.left[c.y] == t.size && c.value != c.x + 1)
		return (-1);
	if (t.borders.right[c.y] == t.size && c.value != t.size - c.x)
		return (-1);
	return (1);
}

int check_min(t_table t, t_cell c)
{
	if (t.borders.top[c.x] == 1 && c.y == 0 &&  c.value != t.size)
		return (-1);
	if (t.borders.bottom[c.x] == 1 && c.y == t.size - 1 && c.value != t.size)
		return (-1);
	if (t.borders.left[c.y] == 1 && c.x == 0 && c.value != t.size)
		return (-1);
	if (t.borders.bottom[c.y] == 1 && c.x == t.size - 1 && c.value != t.size)
		return (-1);
	return (1);
}

int check_extreme(t_table t, t_cell c)
{
	int min_y;
	int min_x;
	int	max_x;
	int max_y;

	max_x = (t.borders.top[c.x] == t.size || t.borders.bottom[c.x] == t.size);
	max_y = (t.borders.left[c.y] == t.size || t.borders.right[c.y] == t.size);
	if (max_x || max_y)
		return (check_max(t, c));

	min_y = (t.borders.top[c.x] == 1 || t.borders.bottom[c.x] == 1);
	min_x = (t.borders.left[c.y] == 1 || t.borders.right[c.y] == 1);
	if (min_x || min_y)
		return (check_min(t, c));
	return (0);
}