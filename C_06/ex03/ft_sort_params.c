/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:31:18 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/12 23:59:45 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printargs(char *argv[])
{
	int	i;

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

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*tmp;
	int		min_i;

	(void)argc;
	min_i = 0;
	i = 1;
	while (argv[i])
	{
		j = i + 1;
		min_i = i;
		while (argv[j])
		{
			if (ft_strcmp(argv[min_i], argv[j]) > 0)
				min_i = j;
			j++;
		}
		tmp = argv[min_i];
		argv[min_i] = argv[i];
		argv[i] = tmp;
		i++;
	}
	printargs(argv);
}
