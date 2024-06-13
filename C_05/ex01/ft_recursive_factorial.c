/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:00:34 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/13 09:15:33 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (res *= 1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_recursive_factorial(10));	
}
*/
