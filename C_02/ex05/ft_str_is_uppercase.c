/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:29:05 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 18:32:38 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_uppercase(char c)
{
	char	a;

	a = 'A';
	while (a <= 'Z')
	{
		if (c == a)
		{
			return (1);
		}
		a++;
	}
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		is_uppercase(str[i]);
		if (is_uppercase(str[i]) == 0)
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
	printf("%d", ft_str_is_uppercase("MIREKJEBOSS"));	// 1
	printf("%d", ft_str_is_uppercase("jMIREK"));	// 0
	printf("%d", ft_str_is_uppercase("MIREK455"));	// 0
	printf("%d", ft_str_is_uppercase("+-MIREK"));	// 0
	printf("%d", ft_str_is_uppercase(""));	// 1
}
*/