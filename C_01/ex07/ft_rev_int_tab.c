/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:41:50 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 00:54:13 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < (size / 2))
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

// Uncomment for testing
/*
#include <stdio.h>
int	main(void)
{
	int	i;
	int	nums[] = {1, 5, 7, 8, 4, 2, 5, 0};
	
	ft_rev_int_tab(nums, 8);
	i = 0;
	while (i < 8)
	{
		printf("%d", nums[i]);
		i++;
	}
	
}
*/