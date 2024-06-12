/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:53:02 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/12 21:50:08 by sskopek          ###   ########.fr       */
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

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (1);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] > 126)
			return (1);
		j = i + 1;
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;

	base_len = ft_strlen(base);
	if (ft_base_check(base))
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr < base_len)
		write(1, &base[nbr], 1);
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base);
		ft_putnbr_base(nbr % base_len, base);
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
#include <stdio.h>
int main()
{

	ft_putnbr_base(-45, "568");

}