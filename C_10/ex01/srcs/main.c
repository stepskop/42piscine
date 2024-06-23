/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:25:59 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/23 14:42:32 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 1)
		no_file(argv);
	while (++i < argc)
	{
		if (!read_file(argv[i]))
		{
			ft_putstro(2, basename(argv[0]));
			ft_putstro(2, ": ");
			ft_putstro(2, argv[i]);
			ft_putstro(2, ": ");
			ft_putstro(2, strerror(errno));
			ft_putstro(2, "\n");
		}
	}
}
