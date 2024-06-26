/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:39:03 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/26 17:01:34 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	append_char(char **buff, int curr_len, char c)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = malloc(sizeof(char) * (curr_len + 1));
	if (*buff)
	{
		while (++i < curr_len)
			tmp[i] = (*buff)[i];
		free(*buff);
	}
	tmp[curr_len] = c;
	*buff = tmp;
}

char	*read_stdin(void)
{
	char	*buffer;
	char	c;
	int		f_size;

	buffer = NULL;
	f_size = 0;
	while (read(0, &c, 1))
	{
		if (errno)
		{
			if (buffer)
				free(buffer);
			return (NULL);
		}
		append_char(&buffer, f_size, c);
		f_size++;
	}
	append_char(&buffer, f_size, '\0');
	return (buffer);
}

int	printstdin(int n_bytes, int single, int first)
{
	char	*stdin;
	int		stdin_len;

	if (!single)
	{
		if (!first)
			ft_putstro(1, "\n");
		ft_putstro(1, "==> standard input <==\n");
	}
	stdin = read_stdin();
	if (!stdin)
		return (0);
	stdin_len = ft_strlen(stdin);
	ft_putstro(1, &stdin[(unsigned int)(stdin_len - n_bytes)]);
	free(stdin);
	return (1);
}

int	tail_stdin(int n_bytes, int single, int first, char *program)
{
	if (!printstdin(n_bytes, single, first))
	{
		ft_putstro(2, basename(program));
		ft_putstro(2, ": stdin: ");
		ft_putstro(2, strerror(errno));
		ft_putstro(2, "\n");
		return (1);
	}
	return (0);
}
