/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:15:26 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 00:55:29 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

// Uncomment for testing
/*
#include <unistd.h>

int main()
{
	int	n;

	n = 65;

	// Should print 'A' since 65 is ASCII code for A 
	write(1, &n, 1);

	// Changes value of pointer
	ft_ft(&n);		

	// Should print changed value '*' since ASCII code for * is 42
	write(1, &n, 1);
	return (0);
}
*/
