/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:46:27 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/10 18:17:58 by sskopek          ###   ########.fr       */
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

void	fill_line(unsigned int size)
{
	if (size % 2 == 1)
	{
		size += 1;
		write(1, "  ", 2);
	}
	while (size < 16)
	{
		write(1, "     ", 5);
		size += 2;
	}
}

void	ft_print_hex_data(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_print_hex(((char *)addr)[i], 2);
		if (i < size - 1)
		{
			ft_print_hex(((char *)addr)[i + 1], 2);
			i++;
		}
		write(1, " ", 1);
		i++;
	}
	fill_line(size);
}

void	ft_print_char_data(void *addr, unsigned int size)
{
	char			curr_char;
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		curr_char = ((char *)addr)[i];
		if (curr_char >= 32 && curr_char <= 126)
		{
			write(1, &addr[i], 1);
		}
		else
		{
			write(1, ".", 1);
		}
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void			*current_addr;
	unsigned int	data_size;

	current_addr = addr;
	data_size = size;
	while (current_addr < addr + size)
	{
		ft_print_hex((unsigned long)current_addr, 16);
		write(1, ": ", 2);
		if ((data_size / 16) > 0)
		{
			ft_print_hex_data(current_addr, 16);
			ft_print_char_data(current_addr, 16);
		}
		else
		{
			ft_print_hex_data(current_addr, data_size % 16);
			ft_print_char_data(current_addr, data_size % 16);
		}
		write(1, "\n", 1);
		current_addr += 16;
		data_size -= 16;
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
