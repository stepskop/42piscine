/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:25:12 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/16 17:47:09 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int **grid, int row, int col, int num);

int	check_views(int **grid, int *views);

int	solve(int **grid, int *views, int row, int col)
{
	int	num;

	if (row == 4)
		return (check_views(grid, views));
	if (col == 4)
		return (solve(grid, views, row + 1, 0));
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, views, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
