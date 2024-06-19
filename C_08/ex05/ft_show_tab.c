/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:08:55 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/19 16:03:04 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putnbr(int nb)
{
	int				c;
	unsigned int	unb;

	if (nb < 0)
	{
		write(1, "-", 1);
		unb = nb * -1;
	}
	else
		unb = (unsigned int)nb;
	if (unb / 10 > 9)
		ft_putnbr(unb / 10);
	else if (unb / 10 != 0)
	{
		c = unb / 10 + 48;
		write(1, &c, 1);
	}
	c = unb % 10 + 48;
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
	}
}

// struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
// int main()
// {
// 	char *txt[4] = {"Mirek", "je", "neskutecny", "frajer"};
// 	t_stock_str *list = ft_strs_to_tab(4, txt);
// 	ft_show_tab(list);
// 	return 0;
// }
