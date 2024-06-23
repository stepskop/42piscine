/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:57:59 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/23 20:49:13 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

// Includes
#include "bsq_struct.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Tools
char	**parse_map(char *file, t_map *map);
void	ft_putstro(int fd, char *str);
int		ft_strlen(char *str);
int		ft_is_printable(char c);

#endif