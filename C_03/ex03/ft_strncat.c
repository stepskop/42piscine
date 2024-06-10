/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:22:38 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/10 20:33:56 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *s1, char *s2, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s2[i])
		i++;
	j = 0;
	while (s1[j] && j < nb)
	{
		s2[j + i] = s1[j];
		j++;
	}
	s2[j + i] = '\0';
	return (s2);
}
