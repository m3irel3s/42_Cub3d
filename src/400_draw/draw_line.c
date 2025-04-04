/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:56:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/04 21:38:07 by meferraz         ###   ########.fr       */
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

void	ft_draw_line(t_game *game, int x, int draw_start, int draw_end, t_ray *ray)
{
	int		tex_index;
	t_img	*tex;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;

	/* Convert wall side (stored as a char) to texture index.
	   Mapping: 'N'->0, 'S'->1, 'W'->2, 'E'->3.
	   (Adjust if you prefer a different mapping.) */
	if (ray->wall_side == 'N')
		tex_index = 0;
	else if (ray->wall_side == 'S')
		tex_index = 1;
	else if (ray->wall_side == 'W')
		tex_index = 2;
	else if (ray->wall_side == 'E')
		tex_index = 3;
	else
		tex_index = 0; /* Fallback */

	tex = &game->textures[tex_index];

	/* Calculate the x coordinate on the texture */
	tex_x = (int)(ray->wall_x * (double)tex->width);
	/* Adjust texture coordinate if needed (flip horizontally) */
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;

	/* Calculate how much to increase the texture coordinate per screen pixel */
	step = (double)tex->height / (draw_end - draw_start);
	tex_pos = 0.0;
	y = draw_start;
	while (y < draw_end)
	{
		int tex_y = (int)tex_pos;
		/* Ensure tex_y is within bounds */
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		/* Get the color from the texture pixel */
		char *tex_pixel = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
		int color = *(unsigned int *)tex_pixel;
		ft_mlx_pixel_put_to_image(game, x, y, color);
		tex_pos += step;
		y++;
	}
}
