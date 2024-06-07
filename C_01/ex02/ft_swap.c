/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:44:30 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 00:37:46 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

//Uncomment for testing
//#include <unistd.h>
/*
int	main(void)
{
	int num1;
	int	num2;

	num1 = 'R';
	num2 = 'L';
	
	ft_swap(&num1, &num2);

	// Should print 'L'
	write(1, &num1, 1);

	// Should print 'R'
	write(1, &num2, 1);

	return (0);
}
*/
