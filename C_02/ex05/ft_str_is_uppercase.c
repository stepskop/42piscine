/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:29:05 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/09 00:27:43 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (str[i] < 'A' || str[i] > 'Z')
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
