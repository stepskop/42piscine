/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:48:48 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 00:23:34 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	t_map map;
	char **field;
	
	field = parse_map(argv[1], &map);
	if (field)
	{
		for (int i = 0; i < map.height; i++)
		{
			for (int j = 0; j < map.width; j++)
			{
				write(1, &field[i][j], 1);
			}
			write(1, "\n", 1);
		}
	}
	
	// printf("%d\n", map.height);
	// printf("%c\n", map.empt);
	// printf("%c\n", map.obst);
	// printf("%c\n", map.sqre);
}