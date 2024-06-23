/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:34:57 by sskopek           #+#    #+#             */
/*   Updated: 2024/06/23 20:50:05 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_STRUCT_H
# define BSQ_STRUCT_H

typedef	struct s_map
{
	int	lines;
	char	empt;
	char	obst;
	char	sqre;
} t_map;

#endif