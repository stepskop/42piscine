/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:44:30 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/06 15:44:35 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Uncomment for testing
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/*
int	main(void)
{
	int num1;
	int	num2;
	int* ptr1 = &num1;
	int* ptr2 = &num2;

	num1 = 'R';
	num2 = 'L';
	
	ft_swap(ptr1, ptr2);

	// Should print 'L'
	write(1, &num1, 1);

	// Should print 'R'
	write(1, &num2, 1);

	return (0);
}
*/