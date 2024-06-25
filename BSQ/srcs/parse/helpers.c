/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:44:05 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/25 12:26:29 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

void	line_len(char *f_cont, t_map *map)
{
	while ((f_cont[map->width] == map->empt || f_cont[map->width] == map->obst) \
	&& f_cont[map->width])
		map->width = map->width + 1;
}

char	*f_after_meta(char *f_cont)
{
	char	*new_cont;

	new_cont = f_cont;
	while (*new_cont != '\n')
		new_cont++;
	new_cont++;
	return (new_cont);
}

int	check_height(char *f_cont, t_map *map)
{
	int	n;
	int	line_count;
	int	empty;

	n = 0;
	line_count = 0;
	empty = 0;
	while (f_cont[n])
	{
		if (!empty && f_cont[n] == map->empt)
			empty = 1;
		if (f_cont[n++] == '\n')
			line_count++;
	}
	if (line_count != map->height || !empty)
		return (0);
	return (1);
}

int	read_charset(char *f_cont, int m_len, t_map *map)
{
	int	i;

	i = m_len - 3;
	if (m_len < 4)
		return (0);
	while (i < m_len)
	{
		if (!ft_is_printable(f_cont[i++]))
			return (0);
	}
	if (f_cont[m_len] == '\n' && \
	(f_cont[m_len - 3] != f_cont[m_len - 2] && \
	f_cont[m_len - 2] != f_cont[m_len - 1]))
	{
		map->empt = f_cont[m_len - 3];
		map->obst = f_cont[m_len - 2];
		map->sqre = f_cont[m_len - 1];
		return (1);
	}
	return (0);
}
