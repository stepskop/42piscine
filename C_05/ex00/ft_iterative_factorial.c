/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:32:19 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/13 08:52:44 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	while (nb > 1)
	{
		res *= (nb - 1);
		nb--;
	}
	return (res);
}

/*
#include <stdio.h>
int main()
{
	printf("%d", ft_iterative_factorial(-1));
}
*/