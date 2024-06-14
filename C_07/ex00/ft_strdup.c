/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:48:55 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/14 12:56:16 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	int	str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	return (ft_strcpy(malloc(str_len), str));
}

/*
#include <stdio.h>
int main()
{
	char	*a = "Mirek";
	char	*b = ft_strdup(a);
	a = "Borec";
	printf("%s", b);
	
}
*/