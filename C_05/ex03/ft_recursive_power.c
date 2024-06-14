/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:24:20 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/14 10:18:32 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (res * ft_recursive_power(nb, power - 1));
}

/*
#include <stdio.h>
int	main()
{
	printf("%d", ft_recursive_power(-16,2));
}
*/