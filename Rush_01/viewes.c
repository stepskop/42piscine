/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   viewes.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sskopek <sskopek@student.42prague.com>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/16 17:37:19 by sskopek		   #+#	#+#			 */
/*   Updated: 2024/06/16 17:37:22 by sskopek		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	check_colt_view(int **grid, int *views, int col)
{
	int	max;
	int	count;
	int	j;

	max = 0;
	count = 0;
	j = 0;
	while (j < 4)
	{
		if (grid[j][col] > max)
		{
			max = grid[j][col];
			count++;
		}
		j++;
	}
	if (count != views[col + 8])
		return (0);
	return (1);
}

int	check_colb_view(int **grid, int *views, int col)
{
	int	max;
	int	count;
	int	j;

	max = 0;
	count = 0;
	j = 3;
	while (j >= 0)
	{
		if (grid[j][col] > max)
		{
			max = grid[j][col];
			count++;
		}
		j--;
	}
	if (count != views[col + 12])
		return (0);
	return (1);
}

int	check_rowl_view(int **grid, int *views, int row)
{
	int	max;
	int	count;
	int	j;

	max = 0;
	count = 0;
	j = 0;
	while (j < 4)
	{
		if (grid[row][j] > max)
		{
			max = grid[row][j];
			count++;
		}
		j++;
	}
	if (count != views[row])
		return (0);
	return (1);
}

int	check_rowr_view(int **grid, int *views, int row)
{
	int	max;
	int	count;
	int	j;

	max = 0;
	count = 0;
	j = 3;
	while (j >= 0)
	{
		if (grid[row][j] > max)
		{
			max = grid[row][j];
			count++;
		}
		j--;
	}
	if (count != views[row + 4])
		return (0);
	return (1);
}

int	check_views(int **grid, int *views)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_rowr_view(grid, views, i)
			||!check_colt_view(grid, views, i))
			return (0);
		if (!check_rowl_view(grid, views, i)
			||!check_colb_view(grid, views, i))
			return (0);
		i++;
	}
	return (1);
}
