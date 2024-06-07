/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 08:51:22 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/07 09:09:31 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// Uncomment for testing
/*
#include <stdio.h>

int	main(void)
{
	int a;
	int	b;
	int div;
	int mod;
	int*	ptr_div;
	int*	ptr_mod;

	ptr_div = &div;
	ptr_mod = &mod;

	a = 5;
	b = 3;

	ft_div_mod(a, b, ptr_div, ptr_mod);

	printf("%d", div);
	printf("%d", mod);	
	return (0);
}
*/