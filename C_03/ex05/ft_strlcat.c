/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:55:58 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/11 02:30:05 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len >= size || size == 0)
		return (src_len + size);
	i = 0;
	while (src[i] && i < size - dest_len - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}

/*

Declaration of the custom ft_strlcat function
#include <stdio.h>
#include <string.h>
#include <bsd/string.h> 
int main() {
    // Test case 1: Normal concatenation within size limit
    char dest1[20] = "Hello";
    char dest2[20] = "Hello";
    char *src1 = " World";
    printf("Test 1: Normal concatenation within size limit\n");
    printf("Original: %lu, %s\n", strlcat(dest1, src1, 20), dest1);
    printf("Custom:   %u, %s\n", ft_strlcat(dest2, src1, 20), dest2);

    return 0;
}
*/