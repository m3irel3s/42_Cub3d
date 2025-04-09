/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:56:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/09 22:54:03 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_darken_rgb_color3(int color, double factor, int times);

void	ft_mlx_pixel_put_to_image(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = game->img->addr + (y * game->img->line_len + x * (game->img->bpp / 8));
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

static void	ft_draw_textured_wall_loop(t_game *game, int x, t_img *texture,
		int tex_x, double step, double tex_pos, int draw_start, int draw_end,
		int fog_times)
{
	int	y;
	int	color;
	int	tex_y;

	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos;
		color = *(int *)(texture->addr + (tex_y * texture->line_len +
					tex_x * (texture->bpp / 8)));
		color = ft_darken_rgb_color3(color, 0.9, fog_times);
		ft_mlx_pixel_put_to_image(game, x, y, color);
		tex_pos += step;
		y++;
	}
}

void	ft_draw_textured_wall(t_game *game, int x, t_ray *ray)
{
	t_img	*texture;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		fog_times;

	texture = &game->textures[ray->wall_side];
	tex_x = (int)(ray->wall_x * texture->width);
	if (ray->wall_side == SOUTH)
		tex_x = texture->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	else if (tex_x >= texture->width)
		tex_x = texture->width - 1;
	step = (double)texture->height / ray->line_height;
	tex_pos = (ray->draw_start - (SCREEN_HEIGHT / 2 - ray->line_height / 2))
		* step;
	fog_times = ft_compute_fog(ray->perp_wall_dist);
	ft_draw_textured_wall_loop(game, x, texture, tex_x, step, tex_pos,
		ray->draw_start, ray->draw_end, fog_times);
}
