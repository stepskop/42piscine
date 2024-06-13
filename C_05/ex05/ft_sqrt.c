/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:16:42 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/13 21:49:38 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	exp;

	exp = 1;
	while (exp * exp <= nb)
	{
		if (exp * exp == nb)
			return (exp);
		if (exp == 46340)
			return (0);
		exp++;
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	printf("%d", ft_sqrt(2147395601));
	return 0;
}
*/