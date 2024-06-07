/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:56:35 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 01:43:44 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	min_i;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		min_i = i;
		while (j < size)
		{
			if (tab[min_i] > tab[j])
			{
				min_i = j;
			}
			j++;
		}
		tmp = tab[min_i];
		tab[min_i] = tab[i];
		tab[i] = tmp;
		i++;
	}
}

// Uncomment for testing
/*
#include <stdio.h>

int	main()
{
	int	nums[] = {5, 67, 2, 4, 7, 19, 4, 1};
	int	i;	
	
	ft_sort_int_tab(nums, 8);
	i = 0;
	while (i < 8)
	{
		printf("%d ", nums[i]);
		i++;
	}
	
}
*/