/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:26:54 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 13:48:46 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char c)
{
	char	a;

	a = 'A';
	while (a <= 'Z')
	{
		if (c == a || c == (a + 32))
		{
			return (1);
		}
		a++;
	}
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (is_alpha(str[i]) == 0)
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
	printf("%d", ft_str_is_alpha("flsndkflj")); // 1
	printf("%d", ft_str_is_alpha("flsnIIUWNRflj")); // 1
	printf("%d", ft_str_is_alpha("DASD468fsdf")); // 0
	printf("%d", ft_str_is_alpha("a664+:.")); // 0
	printf("%d", ft_str_is_alpha("")); // 1
}
*/