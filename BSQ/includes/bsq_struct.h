/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:34:57 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/24 17:55:16 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_STRUCT_H
# define BSQ_STRUCT_H

typedef struct s_map
{
	int		height;
	int		width;
	char	empt;
	char	obst;
	char	sqre;
}	t_map;

typedef struct s_sol
{
	int	size;
	int	x;
	int	y;
}	t_sol;

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

#endif