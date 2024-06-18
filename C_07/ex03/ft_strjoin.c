/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:01:25 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/18 21:28:26 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*create_buffer(int size, char **strs, char *sep)
{
	char	*buffer;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += ft_strlen(sep) * (size - 1);
	if (size <= 0)
		len = 1;
	buffer = (char *)malloc(sizeof(char) * len);
	return (buffer);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		f;

	str = create_buffer(size, strs, sep);
	i = -1;
	f = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[f++] = strs[i][j];
			j++;
		}
		j = 0;
		while (sep[j] && i < (size - 1))
		{
			str[f++] = sep[j];
			j++;
		}
	}
	str[f] = '\0';
	return (str);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *text[] = {"Mirek", "je", "frajer"} ;
// 	char *str;
// 	int word_count = 3;
// 	str = ft_strjoin(word_count, text, " ");
// 	printf("%s", str);
// 	free(str);
// 	return 0;
// }