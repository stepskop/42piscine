/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:58:52 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 15:13:38 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	**prep_field(char *f_cont, t_map *map)
{
	int		i;
	int		j;
	int		k;
	char	**field;

	i = -1;
	j = 0;
	k = 0;
	if (!validate_field(f_cont, map))
		return (NULL);
	field = malloc(sizeof(char *) * map->height);
	while (f_cont[k] != '\n')
		k++;
	k++;
	while (++i < map->height)
	{
		field[i] = malloc(sizeof(char) * map->width);
		j = 0;
		while (j < map->width)
			field[i][j++] = f_cont[k++];
		k++;
	}
	return (field);
}

char	**parse_map(char *f_cont, t_map *map)
{
	char	**field;

	if (!validate_metadata(f_cont, map))
	{
		free(f_cont);
		return (NULL);
	}
	field = prep_field(f_cont, map);
	if (!field)
	{
		free(f_cont);
		return (NULL);
	}
	free(f_cont);
	if (!validate_solvability(field, map))
		return (NULL);
	return (field);
}
