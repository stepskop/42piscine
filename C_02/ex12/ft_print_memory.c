/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:46:27 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/11 00:40:53 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned long dec, unsigned int char_count)
{
	int				mod;
	unsigned int	i;
	char			hex_str[32];

	i = 0;
	while (i < char_count)
	{
		mod = dec % 16;
		if (mod < 10)
			mod += 48;
		else
			mod += 87;
		hex_str[char_count - 1 - i] = mod;
		dec /= 16;
		i++;
	}
	write(1, hex_str, char_count);
}

void	ft_print_data(unsigned char *addr, unsigned int size)
{
	char			curr_char;
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i < size)
			ft_print_hex((addr)[i], 2);
		else if (i != 16)
			write(1, "  ", 2);
		i++;
	}
	write(1, " ", 1);
	i = 0;
	while (i < size)
	{
		curr_char = addr[i];
		if (curr_char >= 32 && curr_char <= 126)
			write(1, &addr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	data_size;

	i = 0;
	while (i * 16 < size)
	{
		if (i < size / 16)
			data_size = 16;
		else
			data_size = size % 16;
		
		ft_print_hex((unsigned long)(addr + i * 16), 15);
		write(1, ":", 1);
		ft_print_data((unsigned char *)(addr + i * 16), data_size);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}

/*
int main()
{
	char *str;

	str = "Some string with some length. It has 5 \n\r\b\r\r special characters";
	ft_print_memory(str, 35);
	return 0;
}
*/
int main()
{
	char *str;

	str = "Some string with some length. It has 5 \n\r\b\r\r special characters";
	ft_print_memory(str, 35);
	return 0;
}