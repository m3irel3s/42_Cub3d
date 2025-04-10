/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:56:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/10 21:23:27 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_draw_textured_wall_loop(t_game *game, int x,
					t_drawdata *data);
static int	ft_compute_fog(double perp_wall_dist);

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
	data.tex_pos = (ray->draw_start - (SCREEN_HEIGHT / 2 -
				ray->line_height / 2)) * data.step;
	data.draw_start = ray->draw_start;
	data.draw_end = ray->draw_end;
	data.fog_times = ft_compute_fog(ray->perp_wall_dist);
	ft_draw_textured_wall_loop(game, x, &data);
}

void	ft_mlx_pixel_put_to_image(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = game->img->addr + (y * game->img->line_len +
			x * (game->img->bpp / 8));
	*(unsigned int *)dst = color;
}

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
		color = *(int *)(data->texture->addr + (tex_y * data->texture->line_len +
				data->tex_x * (data->texture->bpp / 8)));
		color = ft_darken_rgb_color3(color, 0.9, data->fog_times);
		ft_mlx_pixel_put_to_image(game, x, y, color);
		data->tex_pos += data->step;
		y++;
	}
}
