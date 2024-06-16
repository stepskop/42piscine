/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:25:12 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/16 17:41:50 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
void	print_grid(int **grid, int size);
int		**create_grid(void);
int		*parse_views(char *str);
int		solve(int **grid, int *views, int row, int col);

int	main(int argc, char **argv)
{
	int	**grid;
	int	*views;

	if (argc != 2 || ft_strlen(argv[1]) != 31)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	grid = create_grid();
	views = parse_views(argv[1]);
	if (solve(grid, views, 0, 0))
		print_grid(grid, 4);
	else
		write(1, "No solution found\n", 18);
	return (0);
}
