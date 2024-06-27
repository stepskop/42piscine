/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:26:35 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/27 11:56:28 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

int	get_fsize(char *file)
{
	int		file_fd;
	int		f_size;
	char	c;

	f_size = 0;
	file_fd = open(file, O_RDONLY);
	if (file_fd != -1)
	{
		while (read(file_fd, &c, 1))
			f_size++;
		close(file_fd);
	}
	else
		return (-1);
	return (f_size);
}

char	*read_file(char *file)
{
	int		file_fd;
	char	*buffer;
	int		bytes_read;
	int		f_size;

	f_size = get_fsize(file);
	if (f_size == -1)
		return (NULL);
	bytes_read = 0;
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

void	append_char(char **buff, int curr_len, char c)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = malloc(sizeof(char) * (curr_len + 1));
	if (*buff)
	{
		while (++i < curr_len)
			tmp[i] = (*buff)[i];
		free(*buff);
	}
	tmp[curr_len] = c;
	*buff = tmp;
}

char	*read_stdin(void)
{
	char	*buffer;
	char	c;
	int		f_size;

	buffer = NULL;
	f_size = 0;
	while (read(0, &c, 1))
	{
		if (errno)
		{
			if (buffer)
				free(buffer);
			return (NULL);
		}
		append_char(&buffer, f_size, c);
		f_size++;
	}
	append_char(&buffer, f_size, '\0');
	return (buffer);
}
