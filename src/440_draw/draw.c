/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:56:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 11:03:33 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_draw_textured_wall_loop(t_game *game, int x,
				t_drawdata *data);
static int	ft_compute_fog(double perp_wall_dist);

/**
 * @brief Draw a textured wall from the given ray.
 * @param game The game data structure.
 * @param x The x-coordinate of the ray.
 * @param ray The ray data structure containing the wall side, wall x, and
 *            draw start and end.
 *
 * This function draws a textured wall from the given ray. It calculates the
 * texture x-coordinate, step, and texture position, and then calls
 * ft_draw_textured_wall_loop to draw the wall.
 */
void	ft_draw_textured_wall(t_game *game, int x, t_ray *ray)
{
	t_img		*texture;
	t_drawdata	data;

	texture = &game->textures[ray->wall_side];
	data.texture = texture;
	data.tex_x = (int)(ray->wall_x * texture->width);
	if (ray->wall_side == SOUTH)
		data.tex_x = texture->width - data.tex_x - 1;
	if (data.tex_x < 0)
		data.tex_x = 0;
	else if (data.tex_x >= texture->width)
		data.tex_x = texture->width - 1;
	data.step = (double)texture->height / ray->line_height;
	data.tex_pos = (ray->draw_start - (SCREEN_HEIGHT / 2
				- ray->line_height / 2)) * data.step;
	data.draw_start = ray->draw_start;
	data.draw_end = ray->draw_end;
	data.fog_times = ft_compute_fog(ray->perp_wall_dist);
	ft_draw_textured_wall_loop(game, x, &data);
}

/**
 * @brief Put a pixel on the screen at the given coordinates.
 * @param game The game data structure, which contains the mlx image and window.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color of the pixel as an integer.
 *
 * This function simply sets the value of the pixel on the screen at the given
 * coordinates to the given color.
 */
void	ft_mlx_pixel_put_to_image(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = game->img->addr + (y * game->img->line_len
			+ x * (game->img->bpp / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief Compute the number of times to darken the color of a ray for
 * the fog effect.
 * @param perp_wall_dist The perpendicular distance of the ray to the wall.
 * @return The number of times to darken the color for the fog effect.
 *
 * This function computes the number of times to darken the color of a ray for
 * the fog effect. The fog effect is a way to simulate the effect of the
 * atmosphere on the visibility of objects in the game.
 * The farther away the object is, the darker it should appear. The number
 * of times to darken the color is computed by dividing the distance of the
 * ray to the wall by a small value (0.100001).
 * The result is then rounded up to the nearest integer.
 */
static int	ft_compute_fog(double perp_wall_dist)
{
	int		times;
	double	distance;

	if (perp_wall_dist > 4.2)
		return (50);
	distance = 1.0;
	times = 0;
	while (distance < perp_wall_dist)
	{
		distance += 0.100001;
		times++;
	}
	return (times);
}

/**
 * @brief Loops through the ray and draws a textured wall.
 * @param game The game data structure.
 * @param x The x-coordinate of the ray.
 * @param data A structure containing the necessary data to draw the wall.
 *
 * This function loops through the ray and draws a textured wall. It uses the
 * texture, texture position, and fog times from the data structure to draw the
 * wall. The loop iterates from the start of the wall to the end, and for each
 * iteration, it calculates the position of the texture on the y-axis, gets the
 * color from the texture at that position, darkens the color by the fog times,
 * and then draws the pixel on the screen at the given x and y coordinates.
 */
static void	ft_draw_textured_wall_loop(t_game *game, int x,
					t_drawdata *data)
{
	int		y;
	int		color;
	int		tex_y;

	y = data->draw_start;
	while (y < data->draw_end)
	{
		tex_y = (int)(data->tex_pos);
		color = *(int *)(data->texture->addr + (tex_y * data->texture->line_len
					+ data->tex_x * (data->texture->bpp / 8)));
		color = ft_darken_rgb_color3(color, 0.9, data->fog_times);
		ft_mlx_pixel_put_to_image(game, x, y, color);
		data->tex_pos += data->step;
		y++;
	}
}
