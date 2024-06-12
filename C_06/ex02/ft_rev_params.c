/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:27:39 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/12 23:29:50 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	while (argc > 1)
	{
		while (*argv[argc - 1])
		{
			write(1, &*argv[argc - 1], 1);
			argv[argc - 1]++;
		}
		argc--;
		write(1, "\n", 1);
	}
}
