/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:05:36 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/12 19:30:17 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_numstart(char *str, int *sign)
{
	*sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	ft_pow(int x, int e)
{
	int	i;
	int	n;

	n = 1;
	i = 0;
	if (e == 0)
		return (1);
	while (i < e)
	{
		n *= x;
		i++;
	}
	return (n);
}

int	ft_base_check(char *base)
{
	int	i;
	int	j;
	int	base_len;

	i = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (base_len);
}

int	ft_charinbase(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		base_len;
	int		str_len;
	int		sign;
	int		res;
	int		i;

	res = 0;
	str_len = 0;
	base_len = ft_base_check(base);
	str = ft_numstart(str, &sign);
	if (base_len < 2)
		return (0);
	while (ft_charinbase(str[str_len], base) != -1)
		str_len++;
	i = 0;
	while (i < str_len)
	{
		res += ft_charinbase(str[i], base) * ft_pow(base_len, str_len - 1 - i);
		i++;
	}
	return (res * sign);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d", ft_atoi_base("D", "0123456789ABCDEF"));
}
*/