/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:14:16 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/12 23:44:28 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	(void)argc;
	i = 1;
	while (argv[i])
	{
		while (*argv[i])
		{
			write(1, &*argv[i], 1);
			argv[i]++;
		}
		i++;
		write(1, "\n", 1);
	}
}
