/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:15:39 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/18 16:22:03 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

char	*ft_numstart(char *str, int *sign);

int		ft_base_check(char *base);

int		ft_charinbase(char c, char *base);

char	*ft_hexrev(char *str);

int	get_digits(unsigned int nb, int base)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	j = 1;
	while ((i * base) <= nb)
	{
		if ((i - 1) * base < 2147483648)
		{
			i *= base;
			j++;
		}
		else
			return (j);
	}
	return (j);
}

char	*ft_to_base(int nbr, char *base, char *str)
{
	int				base_len;
	unsigned int	unbr;

	base_len = ft_base_check(base);
	if (base_len < 2)
		return ((void *)0);
	if (nbr < 0)
	{
		str[0] = '-';
		unbr = nbr * -1;
	}
	else
		unbr = (unsigned int)nbr;
	str[ft_strlen(str)] = base[unbr % base_len];
	if (unbr < (unsigned int)base_len)
		return (ft_hexrev(str));
	else
		return (ft_to_base(unbr / base_len, base, str));
}

long int	ft_from_base(char *str, char *base)
{
	int			base_len;
	int			str_len;
	int			sign;
	long int	res;

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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	num;
	char		*out;
	int			tbase_len;

	if (!ft_base_check(base_from) || !ft_base_check(base_to))
		return (NULL);
	tbase_len = ft_base_check(base_to);
	num = ft_from_base(nbr, base_from);
	if (num > 2147483647 || num < -2147483648)
		return (NULL);
	if (num < 0)
		out = malloc(8 * (get_digits(-num, tbase_len) + 1));
	else
		out = malloc(get_digits(num, tbase_len) * 8);
	return (ft_to_base(num, base_to, out));
}

// #include <stdio.h>
// int 	main()
// {	
// 	char *str;
// 	str = ft_convert_base("-2147483648", "0123456789", "01");
// 	printf("%s\n", str);
// }