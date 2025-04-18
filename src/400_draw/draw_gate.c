/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:29:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/18 22:01:35 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_draw_gate_loop(t_game *game, int x, t_drawdata *data, double perp_wall_dist);
static int	ft_get_pixel(t_img *texture, int x, int y);

void ft_draw_gate(t_game *game, int x, t_ray *ray)
{
	t_drawdata	data;
	t_door_data	*door;

	door = &game->map->gates[ray->gate_index];
	data.texture = &game->gate_textures[door->frame];
	data.tex_x = (int)(ray->wall_x * (double)data.texture->width);
	data.draw_end = ray->draw_end;
	data.draw_start = ray->draw_start;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		data.tex_x = data.texture->width - data.tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		data.tex_x = data.texture->width - data.tex_x - 1;
	data.step = 1.0 * data.texture->height / ray->line_height;
	data.tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2 + ray->line_height / 2) * data.step;
	ft_draw_gate_loop(game, x, &data, ray->perp_wall_dist);
}

static void	ft_draw_gate_loop(t_game *game, int x, t_drawdata *data, double perp_wall_dist)
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

int	ft_get_pixel(t_img *texture, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	dst = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(int *)dst);
}
