#include "structure.h"
#include <stdio.h>

int leftright(t_border b, t_cell c_arr[4][4], int x, int y)
{
	int check;
	int i;
	int highest;
	int count_vis;

	i = 0;
	highest = 0;
	count_vis = 0;
	while (i < 4)
	{
		if (c_arr[i][y].value > highest)
		{
			highest = c_arr[i][y].value;
			count_vis++;
		}
		if (c_arr[i][y].value == -1)
			check = 1;
		i++;
	}
	if (count_vis > b.left[y] && check == 0)
		return (1);
	if (count_vis != b.left[y] && check == 0)
		return (1);
	return (0);
}

int rightleft(t_border b, t_cell c_arr[4][4], int x, int y)
{
	int check;
	int i;
	int highest;
	int count_vis;

	i = 3;
	highest = 0;
	count_vis = 0;
	while (i > -1)
	{
		if (c_arr[i][y].value > highest)
		{
			highest = c_arr[i][y].value;
			count_vis++;
		}
		if (c_arr[i][y].value == -1)
			check = 1;
		i--;
	}
	if (count_vis > b.right[y] && check == 0)
		return (1);
	if (count_vis != b.right[y] && check == 0)
		return (1);
	return (0);
}

int topbottom(t_border b, t_cell c_arr[4][4], int x, int y)
{
	int check;
	int i;
	int highest;
	int count_vis;

	i = 0;
	highest = 0;
	count_vis = 0;
	while (i < 4)
	{
		if (c_arr[x][i].value > highest)
		{
			highest = c_arr[x][i].value;
			count_vis++;
		}
		if (c_arr[x][i].value == -1)
			check = 1;
		i++;
	}
	if (count_vis > b.top[x] && check == 0)
		return (1);
	if (count_vis != b.top[x] && check == 0)
		return (1);
	return (0);
}

int bottomtop(t_border b, t_cell c_arr[4][4], int x, int y)
{
	int check;
	int i;
	int highest;
	int count_vis;

	i = 3;
	highest = 0;
	count_vis = 0;
	while (i > -1)
	{
		if (c_arr[x][i].value > highest)
		{
			highest = c_arr[x][i].value;
			count_vis++;
		}
		if (c_arr[x][i].value == -1)
			check = 1;
		i--;
	}
	if (count_vis > b.bottom[x] && check == 0)
		return (1);
	if (count_vis != b.bottom[x] && check == 0)
		return (1);
	return (0);
}