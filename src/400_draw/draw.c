/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:56:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/04 21:54:27 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_mlx_pixel_put_to_image(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = game->img->addr + (y * game->img->line_len + x * (game->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_textured_wall(t_game *game, int x, t_ray *ray)
{
	t_img	*texture;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;
	int		color;

	texture = &game->textures[ray->wall_side];
	tex_x = (int)(ray->wall_x * texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	else if (tex_x >= texture->width)
		tex_x = texture->width - 1;
	step = (double)texture->height / (ray->draw_end - ray->draw_start);
	tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		int tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= texture->height)
			tex_y = texture->height - 1;
		color = *(int *)(texture->addr + (tex_y * texture->line_len + tex_x * (texture->bpp / 8)));
		ft_mlx_pixel_put_to_image(game, x, y, color);
		tex_pos += step;
		y++;
	}
}
