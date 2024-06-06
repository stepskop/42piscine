/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:33:42 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/06 17:33:46 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);
				if (!(c == '9' && b == '8' && a == '7'))
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}

// Uncomment for testing
/*
int main(void)
{
	ft_print_comb();
	return (0);
}
*/
