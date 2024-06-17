/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:53:51 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/17 21:44:21 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

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

char	*ft_hexrev(char *str)
{
	int	str_len;
	int	i;
	int tmp;
	int sign;
	
	str_len = ft_strlen(str);
	i = 0;
	sign = 0;
	if (str[0] == '-')
		sign = 1;
	while (i < str_len / 2)
	{
		tmp = str[i + sign];
		str[i + sign] = str[str_len - 1 - i];
		str[str_len - 1 - i] = tmp;
		i++;
	}
	return (str);
}
