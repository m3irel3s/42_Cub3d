/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:15:10 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/09 22:16:40 by meferraz         ###   ########.fr       */
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

typedef enum e_wall_side
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_wall_side;

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

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_headers
{
	t_tag	tag;
	char	*tag_name;
	char	*value;
}	t_headers;

typedef struct	s_map
{
	char		**grid;
	size_t		height;
	int			grid_start_index;
	int			grid_last_index;
	int			map_size;
	t_point		s_pos;
	char		s_dir;
}	t_map;

typedef struct s_ray_step
{
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
}	t_ray_step;

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	int			hit;
	int			hit_outside;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_ray_step	step;
	double		wall_x;
	t_wall_side	wall_side;
}	t_ray;

typedef struct s_game
{
	t_map		*map;
	char		*file_path;
	char		**cub_file;
	int			cub_file_size;
	void		*mlx;
	void		*win;
	t_headers	*headers;
	t_rgb		floor_color;
	int			floor_color_hex;
	t_rgb		ceiling_color;
	int			ceiling_color_hex;
	t_img		*img;
	t_img		textures[4];
	t_player	*player;
}	t_game;


#endif
