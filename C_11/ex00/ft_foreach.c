/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:06:14 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/20 16:53:37 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}

// #include <stdio.h>
// void	printnbr(int nb)
// {
// 	printf("%d", nb);
// }

// int main()
// {
// 	int i[] = {4,8,8,9,1,3};
// 	ft_foreach(i, 6, &printnbr);
// }