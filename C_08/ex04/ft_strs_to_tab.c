/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:37:47 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/19 16:03:12 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*fill_stock(t_stock_str *buffer, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		buffer[i].str = av[i];
		buffer[i].size = j;
		buffer[i].copy = ft_strdup(av[i]);
		i++;
	}
	buffer[i].str = 0;
	buffer[i].copy = 0;
	buffer[i].size = 0;
	return (buffer);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;

	stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock)
		return (NULL);
	return (fill_stock(stock, ac, av));
}
