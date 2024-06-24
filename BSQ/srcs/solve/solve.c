/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:25:36 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 22:08:56 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

void	update_sol(t_coords xy, t_coords *ij, t_sol *sol, t_map map)
{
	int	j;
	int	i;

	j = ij->y;
	i = ij->x;
	if (i != -2 && (sol->size == 0))
	{
		sol->size = 1;
		sol->x = xy.x;
		sol->y = xy.y;
		ij->y = 0;
	}
	if (i != -2 && j > sol->size && i > sol->size \
	&& i + xy.x < map.width && j + xy.y < map.height)
	{
		sol->size = sol->size +1;
		sol->x = xy.x;
		sol->y = xy.y;
		ij->y = 0;
	}
}

void	find_biggest(t_coords xy, char **field, t_sol *sol, t_map map)
{
	t_coords	ij;

	ij.y = 0;
	while (ij.y <= sol->size && ij.y + xy.y < map.height)
	{
		ij.x = 0;
		while (ij.x <= sol->size && ij.x + xy.x < map.width)
		{
			if (field[xy.y + ij.y][xy.x + ij.x] == map.empt)
				ij.x = ij.x + 1;
			else
			{
				ij.x = -2;
				break ;
			}
		}
		if (ij.x == -2)
			break ;
		ij.y = ij.y + 1;
		update_sol(xy, &ij, sol, map);
	}
}

void	apply_sol(t_sol sol, t_map map, char **field)
{
	int	i;
	int	j;

	i = -1;
	printf("%d, %d with size of %d", sol.x, sol.y, sol.size);
	while (++i < sol.size)
	{
		j = -1;
		while (++j < sol.size)
			field[sol.y + j][sol.x + i] = map.sqre;
	}
}

void	solve(char **field, t_map map, t_sol *sol)
{
	t_coords	xy;

	xy.y = 0;
	while (xy.y < map.height)
	{
		xy.x = 0;
		while (xy.x < map.width)
		{
			find_biggest(xy, field, sol, map);
			xy.x = xy.x + 1;
		}
		xy.y = xy.y + 1;
	}
	apply_sol(*sol, map, field);
}
