/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:57:00 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/13 13:41:05 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

/*
int main()
{
	for (int i = 0; i < 1000; i++)
	{
		ft_putnbr(i);
		write(1, "\n", 1);
	}
	ft_putnbr(-2147483648);
}
*/