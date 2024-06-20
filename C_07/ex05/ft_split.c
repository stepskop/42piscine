/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:54:20 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/20 13:49:23 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (str[i])
	{
		if (!is_separator(str[i], charset) && is_separator(str[i + 1], charset))
			wcount++;
		i++;
	}
	return (wcount);
}

void	add_word(char *dest, char *src, char *charset)
{
	while (!is_separator(*src, charset))
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}

void	fill_array(char **dest, char *str, char *charset)
{
	int	curr_word;
	int	i;
	int	j;

	i = 0;
	curr_word = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i], charset))
			i++;
		else
		{
			j = 0;
			while (!is_separator(str[i + j], charset))
				j++;
			dest[curr_word] = malloc(j + 1);
			add_word(dest[curr_word], str + i, charset);
			curr_word++;
			i += j;
		}
	}
	dest[curr_word] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**splitted;
	int		wcount;

	wcount = count_words(str, charset);
	splitted = malloc(wcount * 8 + 1);
	fill_array(splitted, str, charset);
	return (splitted);
}

// #include <unistd.h>
// int	main()
// {
// 	char **splitted;
// 	int i;
// 	int j;
// 	i = 0;
// 	splitted = ft_split("Ahoj Meae, Mi.rku, toto je par.", ",. ");
// 	while (splitted[i])
// 	{
// 		j = 0;
// 		while (splitted[i][j])
// 		{
// 			write(1, &splitted[i][j], 1);		
// 			j++;
// 		}
// 		write(1, "\n", 1);
// 		i++;
// 	}
// }