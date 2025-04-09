/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:56:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/09 22:50:31 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
int ft_darken_rgb_color3(int color, double factor, int times);

void	ft_mlx_pixel_put_to_image(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = game->img->addr + (y * game->img->line_len + x * (game->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void ft_draw_textured_wall(t_game *game, int x, t_ray *ray)
{
	t_img *texture;
	int tex_x;
	double step;
	double tex_pos;
	int y;
	int color;
	int times;

	texture = &game->textures[ray->wall_side];

	// Calcula a coordenada horizontal da textura
	tex_x = (int)(ray->wall_x * texture->width);

	// Aplica inversão somente para o lado SOUTH, se desejado.
	if (ray->wall_side == SOUTH)
		tex_x = texture->width - tex_x - 1;

	// Garante que tex_x está dentro dos limites
	if (tex_x < 0)
		tex_x = 0;
	else if (tex_x >= texture->width)
		tex_x = texture->width - 1;

	// Calcula o step (passo) para mapear a textura na parede
	step = (double)texture->height / ray->line_height;
	tex_pos = (ray->draw_start - (SCREEN_HEIGHT / 2 - ray->line_height / 2)) * step;

	// Calcula o "fog" (escurecimento) baseado na distância
	if (ray->perp_wall_dist > 4.2)
		times = 50;
	else
	{
		double distance = 1.0;
		times = 0;
		while (distance < ray->perp_wall_dist)
		{
			distance += 0.100001;
			times++;
		}
	}

	// Desenha a parede pixel a pixel
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		int tex_y = (int)tex_pos;
		color = *(int *)(texture->addr + (tex_y * texture->line_len + tex_x * (texture->bpp / 8)));
		// Aplica o efeito fog
		color = ft_darken_rgb_color3(color, 0.9, times);
		ft_mlx_pixel_put_to_image(game, x, y, color);
		tex_pos += step;
		y++;
	}
}
