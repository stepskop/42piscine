/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:55:35 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/11 09:55:36 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

// Uncomment for testing
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_strlen("Mirek"));
	return (0);
}
*/