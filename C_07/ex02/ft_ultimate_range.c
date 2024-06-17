/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:45:54 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/17 12:01:52 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = (void *)0;
		return (0);
	}
	*range = malloc((max - min) * 32);
	i = -1;
	while (++i < (max - min))
		(*range)[i] = i + min;
	return (max - min);
}

/*
#include <stdio.h>
int	main()
{
	int *range;
	int min = 0;
	int max = 8;
	printf("%d\n", ft_ultimate_range(&range, min, max));
	for (int i = 0; i < max - min; i++)
		printf("%d", range[i]);
}
*/