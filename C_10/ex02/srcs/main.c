/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:25:59 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/26 16:57:40 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	check_args(int argc, char *argv[])
{
	if (argc < 3)
	{
		ft_putstro(2, basename(argv[0]));
		ft_putstro(2, ": option requires an argument -- 'c'");
		ft_putstro(2, "\n");
		return (0);
	}
	if (ft_atoi(argv[2]) == -1)
	{
		ft_putstro(2, basename(argv[0]));
		ft_putstro(2, ": invalid number of bytes: ");
		ft_putstro(2, argv[2]);
		ft_putstro(2, "\n");
		return (0);
	}
	return (1);
}

int	arg_isstdin(char *arg)
{
	if (!ft_strcmp(arg, "-") || !ft_strcmp(arg, "--"))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (!check_args(argc, argv))
		return (1);
	if (argc == 3)
		tail_stdin(ft_atoi(argv[2]), 1, 1, argv[0]);
	else if (argc == 4)
	{
		if (arg_isstdin(argv[3]))
			tail_stdin(ft_atoi(argv[2]), 1, 1, argv[0]);
		else
			tail_file(argv, 3, ft_atoi(argv[2]), 1);
	}
	else if (argc > 3)
	{
		i = 2;
		while (++i < argc)
		{
			if (arg_isstdin(argv[i]))
				tail_stdin(ft_atoi(argv[2]), 0, (i == 3), argv[0]);
			else
				tail_file(argv, i, ft_atoi(argv[2]), 0);
		}
	}
}
