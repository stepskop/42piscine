/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:23:06 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/20 17:39:15 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*res;
	int	i;

	i = -1;
	res = malloc(sizeof(int) * length);
	while (++i < length)
		res[i] = f(tab[i]);
	return (res);
}

// #include <stdio.h>

// int increment(int a)
// {
// 	return (a + 1);
// }

// int main()
// {
// 	int tab[] = {1,5,8,6,14,6};
// 	int size = 6;

// 	int *res = ft_map(tab, size, &increment);
// 	for (int i = 0; i < size; i++)
// 		printf("%d", res[i]);
// }