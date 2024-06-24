/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:57:59 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 17:05:19 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

// Includes
# include "bsq_struct.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// General
void	ft_putstro(int fd, char *str);
int		ft_strlen(char *str);
int		ft_is_printable(char c);
void	ft_freefield(char **field, int map_height);

// Parse
char	**parse_map(char *f_cont, t_map *map);
char	*read_file(char *file);
char	*read_stdin(void);
int		validate_metadata(char *f_cont, t_map *map);
int		validate_field(char *f_cont, t_map *map);
int		validate_solvability(char **field, t_map *map);

// Print
void	print_field(char **field, t_map map);

// Solve
void	solve(char **field, t_map map, t_sol *sol);

#endif