/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:15:10 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/23 18:33:05 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

//============================================================================//
//                                  ENUMS                                     //
//============================================================================//

/**
 * @brief Enum for identifying texture or color types in map headers.
 */
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

/**
 * @brief Enum representing map cell types.
 */
typedef enum e_cell
{
	EMPTY,
	WALL,
	FLOOR
}	t_cell;

/**
 * @brief Enum representing the wall direction hit by the ray.
 */
typedef enum e_wall_side
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_wall_side;

//============================================================================//
//                                BASIC STRUCTS                               //
//============================================================================//

/**
 * @brief Generic iteration counters.
 */
typedef struct s_iter
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
}	t_iter;

/**
 * @brief 2D coordinate point.
 */
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/**
 * @brief RGB color structure.
 */
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

//============================================================================//
//                            GRAPHICS STRUCTURES                             //
//============================================================================//

/**
 * @brief Image buffer structure.
 */
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

/**
 * @brief Rendering information for a vertical slice of a wall.
 */
typedef struct s_drawdata
{
	t_img	*texture;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		draw_start;
	int		draw_end;
	int		fog_times;
}	t_drawdata;

//============================================================================//
//                               GAME STRUCTURES                              //
//============================================================================//

/**
 * @brief Structure holding metadata from the map file header.
 */
typedef struct s_headers
{
	t_tag	tag;
	char	*tag_name;
	char	*value;
}	t_headers;

/**
 * @brief Player position, direction, and camera plane.
 */
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

/**
 * @brief 2D Map structure with grid and player start info.
 */
typedef struct s_map
{
	char		**grid;
	int			height;
	int			width;
	int			grid_start_index;
	int			grid_last_index;
	t_point		s_pos;
	t_point		flood_fill_pos;
	char		s_dir;
}	t_map;

//============================================================================//
//                            RAYCASTING STRUCTURES                           //
//============================================================================//

/**
 * @brief Holds step direction and distances for ray traversal.
 */
typedef struct s_ray_step
{
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
}	t_ray_step;

/**
 * @brief Raycasting data for each column rendered.
 */
typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_ray_step	step;
	double		wall_x;
	t_wall_side	wall_side;
}	t_ray;

//============================================================================//
//                                  GAME STATE                                //
//============================================================================//

/**
 * @brief Central game structure holding all necessary state and pointers.
 */
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
	t_img		textures[4];
	t_img		*img;
	t_player	*player;
}	t_game;

#endif
