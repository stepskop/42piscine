/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:34:52 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/09 00:35:05 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
#include <stdio.h>
int main()
{
	printf("%d", ft_str_is_printable("abcdEF45:*+")); // 1
	printf("%d", ft_str_is_printable("abcdEF\n5:*+")); // 0
	printf("%d", ft_str_is_printable("abcd\rEF45:*+")); // 0
	printf("%d", ft_str_is_printable(".;'*+")); // 1
}
*/