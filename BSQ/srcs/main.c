/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:48:48 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 18:48:35 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	bsq(char *input_str, char **field, t_map *map, t_sol *sol)
{
	field = parse_map(input_str, map);
	if (field)
	{
		solve(field, *map, sol);
		print_field(field, *map);
	}
	else
		ft_putstro(2, "map error\n");
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_sol	sol;
	char	**field;
	int		i;

	i = 1;
	field = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			sol.size = 0;
			sol.x = 0;
			sol.y = 0;
			bsq(read_file(argv[i++]), field, &map, &sol);
		}
	}
	else
		bsq(read_stdin(), field, &map, &sol);
}
