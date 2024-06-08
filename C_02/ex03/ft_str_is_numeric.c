/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:54:54 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 14:15:13 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char c)
{
	char	n;

	n = '0';
	while (n <= '9')
	{
		if (c == n)
		{
			return (1);
		}
		n++;
	}
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		is_number(str[i]);
		if (is_number(str[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// Uncomment for testing
/*
#include <stdio.h>
int	main()
{
	printf("%d", ft_str_is_numeric("78443312")); // 1
	printf("%d", ft_str_is_numeric("dAsd454")); // 0
	printf("%d", ft_str_is_numeric("4654dsdDA")); // 0
	printf("%d", ft_str_is_numeric("7978:_79")); // 0
	printf("%d", ft_str_is_numeric("")); // 1
}
*/
