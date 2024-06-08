/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:22:23 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/09 00:26:40 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (str[i] < 'a' || str[i] > 'z')
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