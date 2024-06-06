/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:21:45 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/06 12:21:53 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Uncomment for testing
//#include <unistd.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

// Uncomment for testing
/*
int main(void)
{
	int	n;
	int*			ptr;
	int**			ptr1 = &ptr;
	int***			ptr2 = &ptr1;
	int****			ptr3 = &ptr2;
	int*****		ptr4 = &ptr3;
	int******		ptr5 = &ptr4;
	int*******		ptr6 = &ptr5;
	int********		ptr7 = &ptr6;
	int*********	ptr8 = &ptr7;

    n = 65;
	ptr = &n;

	// Should print 'A' since 65 is ASCII code for A 
	write(1, &n, 1);

	// Changes value of pointer
	ft_ultimate_ft(ptr8);

	// Should print changed value '*' since ASCII code for * is 42
	write(1, &n, 1);
	return (0);
}
*/