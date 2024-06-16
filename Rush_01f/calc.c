#include "structure.h"
#include <unistd.h>
#include <stdio.h>

int	find_val(t_border b, t_cell cells[4][4], int xy[3], int *i);
int solve_rec(t_border b, t_cell c_arr[4][4], int x, int y)
{
	int i;
	int xy[2];

	xy[0] = x;
	xy[1] = y;
	i = 0;
	if (x == 4)
		return (0);
	else if (y == 4)
		return (solve_rec(b, c_arr, x + 1, 0));
	else if (c_arr[x][y].value != -1)
		return (solve_rec(b, c_arr, x, y + 1));	
	else
	{
		if (find_val(b, c_arr, xy, &i) == 0)
			return (0);
		else
			return (1);	
	}
}
void	solve(t_border b, t_cell c_arr[4][4])
{
	int res;

	res = solve_rec(b, c_arr, 0, 0);
	if (res == 0)
	{
		
		write(1, "Success", 5);
	}
	else
		write(1, "Errorek", 7);
}