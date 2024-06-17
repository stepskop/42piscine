/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:19:08 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/17 11:44:39 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	if (min >= max)
		return ((void *)0);
	res = malloc((max - min) * 32);
	i = -1;
	while (++i < (max - min))
		res[i] = i + min;
	return (res);
}

/*
#include <stdio.h>
int	main()
{
	int min = 3;
	int max = 31;
	int *arr = ft_range(min, max);

	for (int i = 0; i < max - min; i++)
		printf("%d", arr[i]);
}
*/