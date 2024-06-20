/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:36:41 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/20 22:07:58 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);

void	ft_putnbr(int nb);

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	ft_doop(int n1, int n2, char *op)
{
	if (ft_strlen(op) != 1)
		ft_putnbr(0);
	else if (op[0] == '+')
		ft_putnbr(n1 + n2);
	else if (op[0] == '-')
		ft_putnbr(n1 - n2);
	else if (op[0] == '*')
		ft_putnbr(n1 * n2);
	else if (op[0] == '/')
		ft_putnbr(n1 / n2);
	else if (op[0] == '%')
		ft_putnbr(n1 % n2);
	else
		ft_putnbr(0);
}

int	main(int argc, char *argv[])
{
	int		n1;
	int		n2;
	char	*op;

	if (argc < 4)
		return (1);
	op = argv[2];
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	if (n2 == 0 && op[0] == '/')
	{
		write(1, "Stop : division by zero\n", 25);
		return (1);
	}
	if (n2 == 0 && op[0] == '%')
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	ft_doop(n1, n2, op);
}
