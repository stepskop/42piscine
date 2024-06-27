/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:59:23 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/27 12:18:28 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

void	print_last_ascii(char *str, int last)
{
	int	j;
	int	f_len;

	f_len = ft_strlen(str);
	j = last;
	while (j % 16 != 0)
	{
		if (j % 8 == 0)
			ft_putstro(1, " ");
		ft_putstro(1, "   ");
		j++;
	}
	ft_putstro(1, " ");
	ft_putstrn(&str[last - f_len % 16], f_len % 16 + 1);
}

void	print_ascii(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (i % 16 == 0)
			new_line(i);
		if (i % 8 == 0)
			ft_putstro(1, " ");
		ft_print_hex((unsigned long)str[i], 2);
		ft_putstro(1, " ");
		if ((i + 1) % 16 == 0)
		{
			ft_putstro(1, " ");
			ft_putstrn(&str[i - 15], 16);
			ft_putstro(1, "\n");
		}
	}
	if (ft_strlen(str) % 16 != 0)
		print_last_ascii(str, i);
}

void	print_hex_only(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (i % 16 == 0)
			new_line(i);
		ft_print_hex((unsigned long)str[i], 2);
		if (i % 2 > 0)
			ft_putstro(1, " ");
		if ((i + 1) % 16 == 0)
			ft_putstro(1, "\n");
	}
}
