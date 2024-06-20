/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:43:13 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/20 20:06:24 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
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
// 	char *tab[] = {"mirek", "je", "bnormalni", "borec", "\0"};
// 	printf("%d", ft_any(tab, &startswa));
// }