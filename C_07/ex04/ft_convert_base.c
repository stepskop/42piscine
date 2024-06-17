/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:15:39 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/17 22:37:01 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

char	*ft_numstart(char *str, int *sign);

int		ft_base_check(char *base);

int		ft_charinbase(char c, char *base);

char	*ft_hexrev(char *str);

int		get_pow(int nb, int base)
{
	int i;
	int	j;

	i = 1;
	j = 0;
	while (i <= nb)
	{
		j++;
		i *= base;
	}
	return (j);
}

char	*ft_to_base(int nbr, char *base, char *str)
{
	int				base_len;
	unsigned int	unbr;

	base_len = ft_base_check(base);
	if (base_len < 2)
		return (void *)0;
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

int		ft_from_base(char *str, char *base)
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int 	num;
	char	*out;
	int tbase_len;

	tbase_len = ft_base_check(base_to);
	num = ft_from_base(nbr, base_from);

	if (num < 0)
		out = malloc(get_pow(num, tbase_len) + 1);
	else
		out = malloc(get_pow(num, tbase_len));
	return (ft_to_base(num, base_to, out));
}

#include <stdio.h>
int 	main()
{	
	printf("%s", ft_convert_base("-101101110100101101101", "01", "0123456789ABCDEF"));
}