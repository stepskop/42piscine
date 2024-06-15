#include <stdlib.h>
#include "structure.h"

t_cell	**def_cells(int size);

int *get_uniques(t_table table, int x, int y);

int check_extreme(t_table t, t_cell c);

t_table solve(t_table table, int x, int y)
{
	t_cell curr_cell;
	int	ch_extr;

	curr_cell = table.cells[x][y];
	if (curr_cell.only_op > 0 && x == 0)
		return (table);
	curr_cell.opts = get_uniques(table, x, y);
	while (curr_cell.tries < table.size)
	{
		if (curr_cell.opts[curr_cell.tries] != 0)
		{
			curr_cell.value = curr_cell.opts[curr_cell.tries];
			ch_extr = check_extreme(table, curr_cell);
			if (ch_extr >= 0)
			{
				if (ch_extr == 1)
					curr_cell.only_op = curr_cell.value;
				break ;
			}
		}
		curr_cell.tries++;
	}
	if (curr_cell.tries >= table.size)
	{
		if (x == 0 && y > 0)
			return (solve(table, table.size - 1, y - 1));
		else
			return (solve(table, x - 1, y));
	}
	else if (y != table.size && x != table.size)
	{
		if (x == table.size && y < table.size)
			return (solve(table, 0, y + 1));
		else
			return (solve(table, x + 1, y));
	}
	else
		return (table);
}

#include <stdio.h>
int main()
{
	t_table table;
	int top[] = {4,2,3,1};
	int bottom[] = {1,2,2,2};
	int left[] = {4,2,3,1};
	int right[] = {1,2,2,2};

	table.size = 4;
	table.borders.top = top;
	table.borders.bottom = bottom;
	table.borders.left = left;
	table.borders.right = right;
	//table.borders = def_brdrs(table.size, borders);
	table.cells = def_cells(table.size);
	// for (int i = 0; i < table.size; i++)
	// {
	// 	printf("%d", table.borders.top[i]);
	// }
	//int *arr;
	table = solve(table, 0, 0);
	//arr = get_uniques(table, 0, 0);
	
	// for (int i = 0; i < table.size; i++)
	// {
	// 	printf("%d", arr[i]);
	// }
}