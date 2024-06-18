/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:01:25 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/18 18:46:55 by sskopek          ###   ########.fr       */
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

	stra_len = 0;
	i = 0;
	while (i < size)
	{
		stra_len += ft_strlen(strs[i]);
		i++;
	}
	final_len = stra_len + ((size - 1) * ft_strlen(sep));
	buffer = malloc(sizeof(char) * (final_len + 1));
	return (ft_fillbuffer(strs, buffer, sep, final_len));
}

// int main(void)
// {
// 	char *text[] = {"", "adsad"} ;
// 	char *str;
// 	int word_count = 4;
// 	str = ft_strjoin(0, text, " -- ");
// 	for (int i = 0; i < 1; i++)
// 	{
// 		str = ft_strjoin(2, text, "");
// 		printf("%s", str);	
// 	}
// 	free(str);
// 	return 0;
// }