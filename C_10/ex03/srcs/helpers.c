/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:02:20 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/26 22:53:09 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

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

void	new_line(int i)
{
	ft_print_hex(i, 8);
	ft_putstro(1, " ");
}

void	ft_putstrn(char *str, int n)
{
	int	i;

	i = 0;
	write(1, "|", 1);
	while (str[i] && i < n)
	{
		if (ft_is_printable(str[i]))
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|", 1);
}

int	throw_err(char *argv[], int argc, int n)
{
	(void)argc;
	if (!ft_strcmp(argv[n], "-") || !ft_strcmp(argv[n], "--"))
	{
		ft_putstro(2, basename(argv[0]));
		ft_putstro(2, ": stdin: ");
		ft_putstro(2, strerror(errno));
		ft_putstro(2, "\n");
	}
	else
	{
		ft_putstro(2, basename(argv[0]));
		ft_putstro(2, ": ");
		ft_putstro(2, argv[n]);
		ft_putstro(2, ": ");
		ft_putstro(2, strerror(errno));
		ft_putstro(2, "\n");
	}
	return (1);
}

void	merge_string(char **dest, char **src)
{
	int		dest_len;
	int		src_len;
	char	*buffer;
	int		i;

	i = -1;
	dest_len = 0;
	src_len = 0;
	if (*dest)
		dest_len = ft_strlen(*dest);
	src_len = ft_strlen(*src);
	buffer = (char *)malloc(sizeof(char) * (dest_len + src_len + 1));
	if (*dest)
	{
		while (++i < (dest_len + src_len))
			buffer[i] = (*dest)[i];
		
		free(*dest);
	}
	ft_strcat(buffer, *src);
	*dest = buffer;
	// if (*src)
	// 	free(*src);
}
