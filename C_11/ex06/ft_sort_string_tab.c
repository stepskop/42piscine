/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:23:10 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/23 12:13:45 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		if (tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

// #include <stdio.h>
// int main()
// {
// 	int i;
// 	char *strings[5] = {"mirek", "je", "abcd", "frajer"};
// 	strings[4] = 0;
// 	i = 0;
// 	ft_sort_string_tab(strings);
// 	while (strings[i])
// 	{
// 		printf("%s\n", strings[i]);
// 		i++;
// 	}
// }