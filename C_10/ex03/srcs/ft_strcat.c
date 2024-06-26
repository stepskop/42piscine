/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:17:14 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/10 19:57:42 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
/*
int main()
{
	char	*a = "je boss";
	char	b[6] = "Mirek ";

	char	*c = "je boss";
	char	d[6] = "Mirek ";

	printf("%s\n", ft_strcat(b, a));
	printf("%s\n", strcat(d, c));
	
	return 0;
}
*/