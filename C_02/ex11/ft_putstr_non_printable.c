/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:13:03 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/09 13:44:42 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char n)
{
	int	first;
	int	second;

	first = (n / 16) + 48;
	if (n % 16 < 10)
	{
		second = n + 48;
	}
	else
	{
		second = n + 87;
	}
	write(1, "\\", 1);
	write(1, &first, 1);
	write(1, &second, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 && str[i] > 0)
		{
			print_hex(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
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