/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:48:48 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/23 21:36:08 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	t_map map;
	
	parse_map(argv[1], &map);
	printf("%d\n", map.lines);
	printf("%c\n", map.empt);
	printf("%c\n", map.obst);
	printf("%c\n", map.sqre);
}