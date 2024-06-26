/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:02:42 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/26 22:53:20 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

void	ft_print_hex(unsigned long dec, unsigned int char_count);
void	ft_putstro(int fd, char *str);
void	ft_putstrn(char *str, int n);
void	new_line(int i);
int		ft_strlen(char *str);
int		ft_is_printable(char c);
int		ft_strcmp(char *s1, char *s2);
char	*read_stdin(void);
char	*read_file(char *file);
int		throw_err(char *argv[], int argc, int n);
void	print_ascii(char *str);
void	print_hex_only(char *str);
char	*ft_strcat(char *dest, char *src);
void	merge_string(char **dest, char **src);

#endif