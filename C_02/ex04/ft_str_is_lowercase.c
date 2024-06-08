/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:22:23 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 18:28:12 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	char	a;

	a = 'a';
	while (a <= 'z')
	{
		if (c == a)
		{
			return (1);
		}
		a++;
	}
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		is_lowercase(str[i]);
		if (is_lowercase(str[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d", ft_str_is_lowercase("mirekjeborec"));	// 1
	printf("%d", ft_str_is_lowercase("Mirekjeborec"));	// 0
	printf("%d", ft_str_is_lowercase("mirekJeborec"));	// 0
	printf("%d", ft_str_is_lowercase("mire789jeborec"));	// 0
	printf("%d", ft_str_is_lowercase("mirek*-++borec"));	// 0
	printf("%d", ft_str_is_lowercase(""));	// 1
}
*/