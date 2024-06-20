/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:09:17 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/20 20:21:01 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	j;
	int	res;

	j = 0;
	res = 0;
	while (j < length)
	{
		if (f(tab[j]) != 0)
			res++;
		j++;
	}
	return (res);
}

// int	startswa(char *str)
// {
// 	if (str[0] == 'a')
// 		return (1);
// 	return (0);
// }

// #include <stdio.h>
// int main()
// {
// 	char *tab[] = {"airek", "je", "bnormalni", "aorec"};
// 	printf("%d", ft_count_if(tab, 4, &startswa));
// }