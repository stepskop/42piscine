/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:20:05 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/23 14:45:16 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	read_file(char *file)
{
	char	buf[BUF_SIZE];
	int		file_fd;
	int		size;

	file_fd = open(file, O_RDONLY);
	if (file_fd != -1)
	{
		size = read(file_fd, &buf, BUF_SIZE);
		while (size != 0)
		{
			write(1, buf, size);
			size = read(file_fd, &buf, BUF_SIZE);
		}
		return (1);
	}
	return (0);
}
