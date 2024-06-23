/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:39:03 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/23 14:45:38 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	no_file(char **argv)
{
	char	buf;

	while (read(0, &buf, 1))
	{
		if (!errno)
			write(1, &buf, 1);
		else
		{
			ft_putstro(2, basename(argv[0]));
			ft_putstro(2, ": stdin: ");
			ft_putstro(2, strerror(errno));
			ft_putstro(2, "\n");
		}
	}
}
