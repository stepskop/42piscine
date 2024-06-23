/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:58:52 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 00:30:55 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*read_file(char *file)
{
	int		f_size;
	int		file_fd;
	char	c;
	char	*buffer;
	int		bytes_read;

	f_size = 0;
	bytes_read = 0;
	file_fd = open(file, O_RDONLY);
	if (file_fd != -1)
	{
		while (read(file_fd, &c, 1))
			f_size++;
	}
	buffer = malloc(sizeof(char) * f_size);
	close(file_fd);
	file_fd = open(file, O_RDONLY);
	if (file_fd != -1)
		bytes_read = read(file_fd, buffer, f_size);
	buffer[bytes_read] = '\0';
	return (buffer);
}

int	validate_metadata(char *file_content, t_map *map)
{
	int	i;
	int	j;
	int	lines;

	i = 0;
	lines = 0;
	if (file_content[0] == '0')
		return (0);
	while (file_content[i] >= '0' && file_content[i] <= '9')
		lines = (lines * 10) + file_content[i++] - 48;
	j = i + 3;
	while (i < j)
	{
		if (!ft_is_printable(file_content[i++]))
			return (1);
	}
	if (file_content[i] == '\n' && lines > 0)
	{
		map->height = lines;
		map->empt = file_content[i - 3];
		map->obst = file_content[i - 2];
		map->sqre = file_content[i - 1];
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
	if (f_cont[((j + 1) * i)] != '\0')
		return (0);
	return (1);
}

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
	return (field);
}
