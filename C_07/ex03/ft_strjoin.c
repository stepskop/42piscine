/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:01:25 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/17 16:33:35 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_fillbuffer(char **strs, char *buffer, char *sep, int b_len)
{
	int		i;
	int		j;
	int		strs_item;

	i = 0;
	strs_item = 0;
	while (i < b_len)
	{
		j = 0;
		while (strs[strs_item][j] && i + j < b_len)
		{
			buffer[i + j] = strs[strs_item][j];
			j++;
		}
		i += j;
		j = 0;
		while (sep[j] && i + j < b_len)
		{
			buffer[i + j] = sep[j];
			j++;
		}
		i += j;
		strs_item++;
	}
	return (buffer);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*buffer;
	int		final_len;
	int		stra_len;
	int		i;

	buffer = "";
	if (size <= 0)
		return (buffer);
	stra_len = 0;
	i = 0;
	while (i < size)
	{
		stra_len += ft_strlen(strs[i]);
		i++;
	}
	final_len = stra_len + ((size - 1) * ft_strlen(sep));
	buffer = malloc(final_len + 1);
	return (ft_fillbuffer(strs, buffer, sep, final_len));
}

// int main(void)
// {
// 	char *text[] = {"Ahoj", "mirku,", "ty", "frajere."};
// 	int word_count = 4;
// 	printf("%s", ft_strjoin(word_count, text, " -- "));
// 	return 0;
// }