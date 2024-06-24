/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:51:56 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 21:41:07 by sskopek          ###   ########.fr       */
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

void	line_len(char *f_cont, t_map *map)
{
	while ((f_cont[map->width] == map->empt || f_cont[map->width] == map->obst) \
	&& f_cont[map->width])
		map->width = map->width + 1;
}

char *f_after_meta(char *f_cont)
{	
	char *new_cont;

	new_cont = f_cont;
	while (*new_cont != '\n')
		new_cont++;
	new_cont++;
	return (new_cont);
}

int check_height(char *f_cont, t_map *map)
{
	int	n;
	int line_count;
	int empty;
	n = 0;
	line_count = 0;
	empty = 0;
	while(f_cont[n])
	{
		if(!empty && f_cont[n] == map->empt)
			empty = 1;
		if(f_cont[n++] == '\n')
			line_count++;
	}
	if (line_count != map->height || !empty)
		return (0);
	return (1);
}

int	validate_field(char *f_cont, t_map *map)
{
	int	i;
	int	j;
	int c_lines;

	i = -1;
	c_lines = 0;
	map->width = 0;
	f_cont = f_after_meta(f_cont);
	line_len(f_cont, map);
	if(!check_height(f_cont, map))
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
