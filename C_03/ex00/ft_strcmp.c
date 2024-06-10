/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:13:44 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/10 19:52:39 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
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
	char	*b = "ABD";

	printf("%d\n", strcmp(a, b));
	printf("%d", ft_strcmp(a, b));
	return 0;
}
*/