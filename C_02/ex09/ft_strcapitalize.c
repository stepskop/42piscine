/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:03:33 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/10 12:01:07 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha_num(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_alpha_num(str[i]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] - 32;
			}
			i++;
			while (is_alpha_num(str[i]))
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
				{
					str[i] = str[i] + 32;
				}
				i++;
			}
		}
		i++;
	}
	return (str);
}

// Uncomment
/*
#include <stdio.h>
int main()
{
	char string[] = "salut, comment tu vas ?";
	printf("%s\n", ft_strcapitalize(string));
}
*/