/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 20:15:03 by jbahus            #+#    #+#             */
/*   Updated: 2018/06/04 20:15:17 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

typedef struct	s_xy
{
	float x;
	float y;
}				t_xy;

typedef struct	s_sector
{
	float		floor;
	float		ceil;
	t_xy		*vertex;
	signed char	*neighbors;
	unsigned	npoints;
}				t_sectors;

typedef struct	s_xyz
{
	float		x;
	float		y;
	float		z;
}				t_xyz;

typedef struct	s_player
{
	t_xyz		where;
	t_xyz		velocity;
	float		angle;
	float		anglesin;
	float		anglecos;
	float		yaw;
	unsigned	sector;
}				t_player;

void 			load_data();

#endif
