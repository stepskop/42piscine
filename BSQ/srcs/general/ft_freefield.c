/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freefield.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:13:53 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 14:18:55 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

void	ft_freefield(char **field, int map_height)
{
	int	i;

	i = -1;
	while (++i < map_height)
		free(field[i]);
	free(field);
}
