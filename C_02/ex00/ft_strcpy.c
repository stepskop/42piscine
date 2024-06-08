/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:26:01 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/08 12:07:51 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i + 1] = '\0';
	return (dest);
}

// Uncomment for testing
/*
#include <stdio.h>
int	main()
{
	char	*str_a = "Mirek";
	char	str_b[] = "Boss";

	ft_strcpy(str_b, str_a);

	printf("%s", str_b);
}
*/