/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:46:22 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 19:00:30 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
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
	char string[] = "lowercase string with 5 words.";
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";
	printf("%s\n", ft_strupcase(string));
	printf("%s\n", ft_strupcase(alpha));
}
*/