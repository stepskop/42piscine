/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:13:03 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/11 00:59:48 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			if (str[i] / 16 > 0)
			{
				write(1, &"0123456789abcdef"[(int)str[i] / 16], 1);
				write(1, &"0123456789abcdef"[(int)str[i] % 16], 1);
			}
			else
			{
				write(1, "0", 1);
				write(1, &"0123456789abcdef"[(int)str[i]], 1);
			}
		}
		i++;
	}
}

// Uncomment for testing
/*
int	main()
{
	ft_putstr_non_printable("Je Mi\rek \bo\rec? \nA\no.");
}
*/