/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:53:57 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 19:00:10 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

// Uncomment for testing
/*
#include <stdio.h>
int main()
{
	char string[] = "LOWERCASE TEXT WITH 5 WORDS.";
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWYZ";
	printf("%s\n", ft_strlowcase(string));
	printf("%s\n", ft_strlowcase(alpha));
}
*/