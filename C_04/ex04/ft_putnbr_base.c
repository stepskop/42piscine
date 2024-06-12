/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:53:02 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/12 14:59:25 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return ("0");
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return ("0");
		j = i + 1;
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j])
				return ("0");
			j++;
		}
		i++;
	}
	return (base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	char	*parsed_base;

	parsed_base = ft_base_check(base);
	base_len = ft_strlen(parsed_base);
	if (base_len < 2)
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if ((nbr / base_len) > base_len - 1)
	{
		ft_putnbr_base(nbr / base_len, base);
		write(1, &parsed_base[nbr % base_len], 1);
	}
	else
	{
		if (nbr / base_len > 0)
			write(1, &parsed_base[nbr / base_len], 1);
		write(1, &parsed_base[nbr % base_len], 1);
	}
}

/*
#include <stdio.h>
int main()
{
	ft_putnbr_base(3, "0123456789");
	printf("\n");
	ft_putnbr_base(-45, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(-19823, "01");
	printf("\n");
	ft_putnbr_base(145, "01234567");
	printf("\n");
}
*/