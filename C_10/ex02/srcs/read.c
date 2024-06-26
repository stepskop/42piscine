/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:14:52 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/26 17:00:21 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

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

char	*read_file(char *file, int f_size)
{
	int		file_fd;
	char	*buffer;
	int		bytes_read;

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

int	putlastn(char *file, int n, int single, int first)
{
	char	*f_cont;
	int		f_contlen;
	int		f_size;

	f_size = get_fsize(file);
	if (f_size == -1)
		return (0);
	else
	{
		if (!single)
		{
			if (!first)
				ft_putstro(1, "\n");
			ft_putstro(1, "==> ");
			ft_putstro(1, file);
			ft_putstro(1, " <==\n");
		}
		f_cont = read_file(file, f_size);
		f_contlen = ft_strlen(f_cont);
		ft_putstro(1, &f_cont[(unsigned int)(f_contlen - n)]);
		free(f_cont);
		return (1);
	}
}

int	tail_file(char *argv[], int argn, int n_bytes, int single)
{
	if (!putlastn(argv[argn], n_bytes, single, (argn == 3)))
	{
		ft_putstro(2, basename(argv[0]));
		ft_putstro(2, ": cannot open '");
		ft_putstro(2, argv[argn]);
		ft_putstro(2, "' for reading: ");
		ft_putstro(2, strerror(errno));
		ft_putstro(2, "\n");
		return (1);
	}
	return (0);
}
