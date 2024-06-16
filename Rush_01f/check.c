#include "structure.h"
#include <unistd.h>
#include <stdio.h>

int solve_rec(t_border b, t_cell c_arr[4][4], int x, int y);

int leftright(t_border b, t_cell c_arr[4][4], int x, int y);
int rightleft(t_border b, t_cell c_arr[4][4], int x, int y);
int topbottom(t_border b, t_cell c_arr[4][4], int x, int y);
int bottomtop(t_border b, t_cell c_arr[4][4], int x, int y);
int applicable_val(t_border b, t_cell c_arr[4][4], int xy[2], int *i)
{	
	c_arr[xy[0]][xy[1]].value = *i;
	
	if (leftright(b, c_arr, xy[0], xy[1]))
		return (1);
	if (rightleft(b, c_arr, xy[0], xy[1]))
		return (1);
	if (topbottom(b, c_arr, xy[0], xy[1]))
		return (1);
	if (bottomtop(b, c_arr, xy[0], xy[1]))
		return (1);
	return (0);
}

int	predefined_situations(t_border b, t_cell c[4][4], int x, int y)
{
	if ((x == 0 && (b.left[y] == 2 || b.left[y] == 3)) \
	|| (x == 3 && (b.right[y] == 2 || b.right[y] == 3)) \
	|| (y == 0 && (b.top[x] == 2 || b.top[x] == 3)) \
	|| (y == 3 && (b.bottom[x] == 2 || b.bottom[x] == 3)))
		return (1);
	return (0);
}

int	find_val(t_border b, t_cell c[4][4], int xy[2], int *i)
{
	while (++*i < 5)
	{
		if (*i == 4 && (xy[0] == 0 || xy[1] == 0 \
		|| xy[0] == 3 || xy[1] == 3))
		{
			if (predefined_situations(b, c, xy[0], xy[1]) == 1)
				continue ;
		}
			
		if (applicable_val(b, c, xy, i) == 0)
		{
			if (solve_rec(b, c, xy[0], xy[1] + 1) == 0)
				return (0);
			c[xy[0]][xy[1]].value = -1;
		}
		else 
			c[xy[0]][xy[1]].value = -1;
	}
	return(1);
}

