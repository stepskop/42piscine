/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:28:07 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/11 01:55:13 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	to_find_len;

	to_find_len = ft_strlen(to_find);
	i = 0;
	if (!to_find[0])
		return (str);
	while (str[i])
	{
		j = 0;
		while (j < to_find_len)
		{
			if (str[i + j] != to_find[j])
				break ;
			j++;
		}
		if (j == to_find_len)
			return (str + i);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	char m[] = "Mirekcek je pan";
	printf("%s", ft_strstr(m, "je"));
	return 0;
}
*/