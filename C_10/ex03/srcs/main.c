/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:57:39 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/26 22:53:02 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

void	hexdump(char *str, int ascii_sw)
{
	if (ascii_sw == 0)
		print_hex_only(str);
	else if (ascii_sw == 1)
		print_ascii(str);
	ft_print_hex((unsigned long)ft_strlen(str), 8);
	ft_putstro(1, "\n");
	free(str);
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*buff;
	int		i;
	int		ascii_sw;

	ascii_sw = 0;
	i = 0;
	str = NULL;
	buff = NULL;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-C") && !ascii_sw)
			ascii_sw = 1;
		else
		{
			if (!ft_strcmp(argv[i], "-") || !ft_strcmp(argv[i], "--"))
				buff = read_stdin();
			else if (ft_strcmp(argv[i], "-C") != 0)
				buff = read_file(argv[i]);
			if (!buff)
			{
				throw_err(argv, argc, i);
				continue ;
			}
			merge_string(&str, &buff);
		}
	}
	hexdump(str, ascii_sw);
}
