/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:05:36 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/12 22:34:16 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_numstart(char *str, int *sign)
{
	*sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while ((*str == '+' || *str == '-') && *str)
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
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

	str_len = 0;
	base_len = ft_base_check(base);
	if (base_len < 2)
		return (0);
	str = ft_numstart(str, &sign);
	res = 0;
	while (ft_charinbase(str[str_len], base) != -1)
	{
		res = (res * base_len) + ft_charinbase(str[str_len], base);
		str_len++;
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