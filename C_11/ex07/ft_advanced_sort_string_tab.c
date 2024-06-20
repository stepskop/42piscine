/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:36:45 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/20 22:41:13 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		min_i;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		min_i = i;
		while (tab[j])
		{
			if (cmp(tab[min_i], tab[j]) > 0)
				min_i = j;
			j++;
		}
		tmp = tab[min_i];
		tab[min_i] = tab[i];
		tab[i] = tmp;
		i++;
	}
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (s1[i] != '\0' && s1[i] == s2[i])
// 		i++;
// 	if (s1[i] == s2[i])
// 		return (0);
// 	else
// 		return (s1[i] - s2[i]);
// }

// #include <stdio.h>
// int main()
// {
// 	int i;
// 	char *strings[5] = {"mirek", "je", "abcd", "frajer"};
// 	strings[4] = 0;
// 	i = 0;
// 	ft_advanced_sort_string_tab(strings, &ft_strcmp);
// 	while (strings[i])
// 	{
// 		printf("%s\n", strings[i]);
// 		i++;
// 	}
// }