/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:48:48 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 16:13:38 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	char	**field;
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			field = parse_map(read_file(argv[i++]), &map);
			if (field)
				print_field(field, map);
			else
				ft_putstro(2, "map error\n");
		}
	}
	else
	{
		field = parse_map(read_stdin(), &map);
		if (field)
			print_field(field, map);
		else
			ft_putstro(2, "map error\n");
	}
}
