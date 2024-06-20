/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:22:23 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/20 22:43:45 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int main(int argc, char *argv[])
{
	int	file_fd;
	int size;
	char	buffer[1025];

	if (argc < 2)
		ft_puterr("File name missing.\n");
	else if (argc > 2)
		ft_puterr("Too many arguments.\n");
	else
	{
		file_fd = open(argv[1], O_RDONLY);
		if (file_fd == -1)
		{
			ft_puterr("Cannot read file.\n");
			return (1);
		}
		while ((size = read(file_fd, buffer, 1024)) > 0)
		{
			buffer[size] = 0;
			ft_putstr(buffer);
		}
		close(file_fd);
		return (0);
	}
	return (1);
}
