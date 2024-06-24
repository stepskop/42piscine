/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:58:52 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 12:58:49 by sskopek          ###   ########.fr       */
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
	field = malloc(sizeof(char *) * map->height);
	if (!validate_field(f_cont, map))
		return (NULL);
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

char	**parse_map(char *file, t_map *map)
{
	char	*file_content;
	char	**field;

	file_content = read_file(file);
	if (!validate_metadata(file_content, map))
		return (NULL);
	field = prep_field(file_content, map);
	free(file_content);
	if (!field)
		return (NULL);
	if (!validate_solvability(field, map))
		return (NULL);
	return (field);
}
