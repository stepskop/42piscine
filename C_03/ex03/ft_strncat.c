/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:22:38 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/11 01:22:08 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < nb)
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[j + i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

// Declaration of the custom ft_strncat function
int main() {
    // Test case 1: Normal concatenation
    char dest1[20] = "Hello";
    char dest2[20] = "Hello";
    char *src1 = " World";
    printf("Test 1: Normal concatenation\n");
    printf("Original: %s\n", strncat(dest1, src1, 6));
    printf("Custom:   %s\n", ft_strncat(dest2, src1, 6));

    // Test case 2: Concatenation with nb greater than source length
    char dest3[20] = "Foo";
    char dest4[20] = "Foo";
    char *src2 = "Bar";
    printf("\nTest 2: nb greater than source length\n");
    printf("Original: %s\n", strncat(dest3, src2, 10));
    printf("Custom:   %s\n", ft_strncat(dest4, src2, 10));

    // Test case 3: Concatenation with nb equal to zero
    char dest5[20] = "Baz";
    char dest6[20] = "Baz";
    char *src3 = "Qux";
    printf("\nTest 3: nb equal to zero\n");
    printf("Original: %s\n", strncat(dest5, src3, 0));
    printf("Custom:   %s\n", ft_strncat(dest6, src3, 0));

    // Test case 4: Concatenation to an empty destination string
    char dest7[20] = "";
    char dest8[20] = "";
    char *src4 = "Empty";
    printf("\nTest 4: Empty destination string\n");
    printf("Original: %s\n", strncat(dest7, src4, 5));
    printf("Custom:   %s\n", ft_strncat(dest8, src4, 5));

    // Test case 5: Concatenation of an empty source string
    char dest9[20] = "NonEmpty";
    char dest10[20] = "NonEmpty";
    char *src5 = "";
    printf("\nTest 5: Empty source string\n");
    printf("Original: %s\n", strncat(dest9, src5, 5));
    printf("Custom:   %s\n", ft_strncat(dest10, src5, 5));

    return 0;
}
*/