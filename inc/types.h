/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:15:10 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/31 18:54:39 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

//============================================================================//
//                                  ENUMS                                     //
//============================================================================//


//============================================================================//
//                                STRUCTURES                                  //
//============================================================================//

typedef struct s_iter
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
}	t_iter;

typedef struct	s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct	s_img
{
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
}	t_img;

typedef struct	s_path
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_path;

typedef struct	s_map
{
	char	**grid;
	size_t	width;
	size_t	height;
	t_point	*s_pos;
	t_img	*img;
	t_path	*paths;
	char	*map_path;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*win;
}	t_game;


#endif
