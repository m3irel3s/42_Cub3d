/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:29:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	ft_draw_gate_loop(t_game *game, int x, \
	t_drawdata *data, double perp_wall_dist);
static int	ft_get_pixel(t_img *texture, int x, int y);

/**
 * @brief Draws a gate at the specified x-coordinate using the given ray.
 * @param game The game data structure.
 * @param x The x-coordinate of the gate.
 * @param ray The ray data structure containing the gate information.
 *
 * This function draws a gate at the specified x-coordinate using the texture
 * associated with the current frame of the gate. It calculates the texture
 *  x-coordinate based on the ray's wall x position and adjusts it according 
 * to the side and direction of the ray. It also calculates the step and 
 * texture position for vertical texture mapping.
 * 
 * The function then calls ft_draw_gate_loop to render the gate column.
 */

void	ft_draw_gate(t_game *game, int x, t_ray *ray)
{
	t_drawdata	data;
	t_door_data	*door;

	door = &game->map->gates[ray->gate_index];
	data.texture = &game->gate_textures[door->frame];
	data.tex_x = (int)(ray->wall_x * (double)data.texture->width);
	data.tex_x = data.texture->width - data.tex_x - 1;
	data.draw_end = ray->draw_end;
	data.draw_start = ray->draw_start;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		data.tex_x = data.texture->width - data.tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		data.tex_x = data.texture->width - data.tex_x - 1;
	data.step = 1.0 * data.texture->height / ray->line_height;
	data.tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2 + \
		ray->line_height / 2) * data.step;
	ft_draw_gate_loop(game, x, &data, ray->perp_wall_dist);
}

/**
 * @brief Loops through the gate column and draws it.
 * @param game The game data structure.
 * @param x The x-coordinate of the gate column.
 * @param data A structure containing the necessary data to draw the gate.
 * @param perp_wall_dist The perpendicular wall distance from the ray.
 *
 * This function loops through the gate column, gets the color of the gate
 * texture at the given position, darkens it by the fog times, and then draws
 * the pixel on the screen at the given x and y coordinates. It skips drawing
 * if the pixel is black (0x000000).
 */
static void	ft_draw_gate_loop(t_game *game, int x, \
	t_drawdata *data, double perp_wall_dist)
{
	int	y;
	int	color;
	int	fog_color;

	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->tex_pos += data->step;
		color = ft_get_pixel(data->texture, data->tex_x, (int)data->tex_pos);
		if (color != 0x000000)
		{
			fog_color = ft_compute_fog(perp_wall_dist);
			color = ft_darken_rgb_color3(color, 0.9, fog_color);
			ft_mlx_pixel_put_to_image(game, x, y, color);
		}
		y++;
	}
}

/**
 * @brief Retrieves the color of a pixel in a texture at a given position.
 *
 * @param texture The texture structure containing the image data.
 * @param x The x-coordinate of the pixel to retrieve.
 * @param y The y-coordinate of the pixel to retrieve.
 * @return The color of the pixel as an integer, or 0 if the coordinates 
 * are out of bounds.
 */
int	ft_get_pixel(t_img *texture, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	dst = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(int *)dst);
}
