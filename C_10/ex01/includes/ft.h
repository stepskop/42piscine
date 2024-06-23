/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:46:46 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/23 14:39:20 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define BUF_SIZE 30000

# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

void	ft_putstro(int fd, char *str);
void	no_file(char	**argv);
int		read_file(char	*file);

#endif