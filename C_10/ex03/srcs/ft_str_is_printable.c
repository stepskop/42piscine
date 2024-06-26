/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:34:52 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/26 19:23:33 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
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