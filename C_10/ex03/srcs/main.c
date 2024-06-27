/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:57:39 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/27 12:19:07 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

void	hexdump(char *str, int ascii_sw)
{
	if (!str)
		str = read_stdin();
	if (ascii_sw == 0)
	print_hex_only(str);
	else if (ascii_sw == 1)
		print_ascii(str);
	ft_putstro(1, "\n");
	ft_print_hex((unsigned long)ft_strlen(str), 8);
	ft_putstro(1, "\n");
	free(str);
}

void	check_contarg(char *arg, char **buff)
{
	if (!ft_strcmp(arg, "-") || !ft_strcmp(arg, "--"))
		*buff = read_stdin();
	else if (ft_strcmp(arg, "-C") != 0)
		*buff = read_file(arg);
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
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-C"))
		{
			ascii_sw = 1;
			continue ;
		}
		check_contarg(argv[i], &buff);
		if (!buff)
		{
			throw_err(argv, argc, i);
			continue ;
		}
		merge_string(&str, &buff);
	}
	hexdump(str, ascii_sw);
}
