/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:02:20 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 00:40:44 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

// Uncomment for testing
/*
#include <stdio.h>

int	main(void)
{
	int a;
	int	b;

	a = 5;
	b = 3;

	ft_ultimate_div_mod(&a, &b);

	printf("%d", a);
	printf("%d", b);
}
*/