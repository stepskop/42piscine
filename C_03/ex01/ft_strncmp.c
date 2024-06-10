/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:41:00 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/10 19:54:32 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
	char	*a = "ABDABCDE";
	char	*b = "AB";

	printf("%d\n", strncmp(a, b, 4));
	printf("%d", ft_strncmp(a, b, 4));
	return 0;
}
*/