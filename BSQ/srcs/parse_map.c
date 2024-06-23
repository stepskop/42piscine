/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:58:52 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/23 21:35:49 by sskopek          ###   ########.fr       */
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

int	validate_metadata(char *map_file, t_map *map)
{
	int	i;
	int	j;
	int	lines;

	i = 0;
	lines = 0;
	if (map_file[0] == '0')
		return (0);
	while (map_file[i] >= '0' && map_file[i] <= '9')
		lines = (lines * 10) + map_file[i++] - 48;
	j = i + 3;
	while (i < j)
	{
		if (!ft_is_printable(map_file[i++]))
			return (1);
	}
	if (map_file[i] == '\n')
	{
		map->lines = lines;
		map->empt = map_file[i - 3];
		map->obst = map_file[i - 2];
		map->sqre = map_file[i - 1];
		return (1);
	}
	return (0);
}

char	**parse_map(char *file, t_map *map)
{
	char	*map_file;

	map_file = read_file(file);
	validate_metadata(map_file, map);
	return (NULL);
}
