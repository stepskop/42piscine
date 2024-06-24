/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:51:56 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 14:17:31 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

int	validate_metadata(char *f_cont, t_map *map)
{
	int	i;
	int	j;
	int	lines;

	i = 0;
	lines = 0;
	while (f_cont[i] >= '0' && f_cont[i] <= '9')
		lines = (lines * 10) + f_cont[i++] - 48;
	j = i + 3;
	while (i < j)
	{
		if (!ft_is_printable(f_cont[i++]))
			return (0);
	}
	if (f_cont[i] == '\n' && lines > 0 && \
	(f_cont[i - 3] != f_cont[i - 2] && f_cont[i - 2] != f_cont[i - 1]))
	{
		map->height = lines;
		map->empt = f_cont[i - 3];
		map->obst = f_cont[i - 2];
		map->sqre = f_cont[i - 1];
		return (1);
	}
	return (0);
}

int	validate_field(char *f_cont, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->width = 0;
	while (*f_cont != '\n')
		f_cont++;
	f_cont++;
	while ((f_cont[map->width] == map->empt || f_cont[map->width] == map->obst) \
	&& f_cont[map->width])
		map->width = map->width + 1;
	if (f_cont[(map->width + 1) * map->height - 1] != '\n' || \
	f_cont[(map->width + 1) * map->height])
		return (0);
	while (++i < map->height)
	{
		j = 0;
		while ((f_cont[j] == map->empt || f_cont[j] == map->obst) \
		&& j < map->width)
			j++;
		if (j != map->width || f_cont[j] != '\n')
			return (0);
		f_cont += j + 1;
	}
	return (1);
}

int	validate_solvability(char **field, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (field[++i])
	{
		j = -1;
		while (field[i][++j])
		{
			if (field[i][j] == map->empt)
				return (1);
		}
	}
	ft_freefield(field, map->height);
	return (0);
}
