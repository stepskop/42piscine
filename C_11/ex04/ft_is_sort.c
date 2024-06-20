/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:27:14 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/20 21:26:47 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	des;

	i = 0;
	asc = 0;
	des = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			des++;
		if (f(tab[i], tab[i + 1]) <= 0)
			asc++;
		i++;
	}
	if (des == i || asc == i)
		return (1);
	return (0);
}

//#include <stdio.h>
// int	desc(int a, int b)
// {
// 	return (a - b);
// }

// int	asce(int a, int b)
// {
// 	return (b - a);
// }

// int main()
// {
// 	int a[] = {4, 8, 6, 84, 1};
// 	int b[] = {4, 6, 8, 10, 12};
// 	int c[] = {1,2,3,4,5};
// 	printf("%d", ft_is_sort(a, 5, &desc));
// 	printf("\n%d", ft_is_sort(b, 5, &desc));
// 	printf("\n%d", ft_is_sort(c, 5, &asce));
// }