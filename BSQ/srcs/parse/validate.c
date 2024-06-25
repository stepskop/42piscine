/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:51:56 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/25 12:26:03 by sskopek          ###   ########.fr       */
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
	while (ft_is_printable(f_cont[i]))
		i++;
	if (!read_charset(f_cont, i, map))
		return (0);
	j = 0;
	while (j < i - 3)
	{
		if (f_cont[j] < '0' || f_cont[j] > '9')
			return (0);
		lines = (lines * 10) + f_cont[j++] - 48;
	}
	if (lines < 0)
		return (0);
	map->height = lines;
	return (1);
}

int	validate_field(char *f_cont, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->width = 0;
	f_cont = f_after_meta(f_cont);
	line_len(f_cont, map);
	if (!check_height(f_cont, map))
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
