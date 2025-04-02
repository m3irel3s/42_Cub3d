/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:15:10 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/02 14:41:36 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

//============================================================================//
//                                  ENUMS                                     //
//============================================================================//

typedef enum e_tag
{
	SO_TAG,
	NO_TAG,
	EA_TAG,
	WE_TAG,
	F_TAG,
	C_TAG,
	UNKNOWN
}	t_tag;

typedef enum e_cell
{
	EMPTY,
	WALL,
	FLOOR
}	t_cell;

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

typedef struct s_headers
{
	t_tag	tag;
	char	*tag_name;
	char	*value;
}	t_headers;

typedef struct	s_texture
{
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
}	t_texture;

typedef struct	s_path
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_path;

typedef struct	s_map
{
	char		**grid;
	size_t		width;
	size_t		height;
	int			grid_start_index;
	t_point		*s_pos;
	t_texture	*textures;
	t_path		*paths;
	t_rgb		floor_color;
	t_rgb		ceiling_color;
	char		*map_path;

}	t_map;

typedef struct s_game
{
	t_map	*map;
	char	**cub_file;
	void	*mlx;
	void	*win;
}	t_game;


#endif
