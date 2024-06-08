/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:48:38 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/09 00:42:48 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	return (src_len);
}

/*
#include <stdio.h>
int	main()
{
	char	*src = "Mirek je superfrajer";
	char	dst[20];
	unsigned int	i;

	i = ft_strlcpy(dst, src, 21);

	printf("%d\n", i);
	printf("%s", dst);
}
*/