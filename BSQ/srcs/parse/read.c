/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:55:00 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 13:13:44 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

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
		close(file_fd);
	}
	buffer = malloc(sizeof(char) * (f_size + 1));
	file_fd = open(file, O_RDONLY);
	if (file_fd != -1)
	{
		bytes_read = read(file_fd, buffer, f_size);
		close(file_fd);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}
