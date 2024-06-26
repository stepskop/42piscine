/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:46:46 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/26 17:01:47 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define BUF_SIZE 30000

# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

void	ft_putstro(int fd, char *str);
int		ft_strlen(char *str);
int		putlastn(char *file, int n, int single, int first);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		tail_file(char *argv[], int argn, int n_bytes, int single);
int		tail_stdin(int n_bytes, int single, int first, char *program);
char	*read_stdin(void);

#endif