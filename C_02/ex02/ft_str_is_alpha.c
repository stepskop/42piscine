/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:26:54 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/09 00:24:23 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
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