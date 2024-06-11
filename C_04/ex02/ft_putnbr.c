/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:57:00 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/11 10:43:48 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	c;

	if (nb / 10 > 9)
		ft_putnbr(nb / 10);
	else if (nb / 10 != 0)
	{
		c = nb / 10 + 48;
		write(1, &c, 1);
	}
	c = nb % 10 + 48;
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
}
*/