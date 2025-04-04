/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:56:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/03 22:12:41 by meferraz         ###   ########.fr       */
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

static int	ft_get_texture_x(int side, double wallX,
				int tex_width, t_ray *ray)
{
	int		tex_x;

	tex_x = (int)(wallX * tex_width);
	if (side == 0)
	{
		if (ray->ray_dir_x > 0)
			tex_x = tex_width - tex_x - 1;
	}
	else
	{
		if (ray->ray_dir_y < 0)
			tex_x = tex_width - tex_x - 1;
	}
	return (tex_x);
}

void	ft_draw_texture_line(t_game *game, int x, int draw_start,
				int draw_end, int side, double wallX, void *ray_ptr)
{
	t_ray		*ray;
	int			y;
	int			tex_x;
	int			tex_y;
	int			color;
	char		*tex_addr;
	int			tex_bpp;
	int			tex_line_len;
	int			tex_endian;
	int			tex_width;
	int			tex_height;

	/* Cast ray_ptr to t_ray pointer */
	ray = (t_ray *)ray_ptr;
	/* Assume texture size is 64x64; update accordingly if stored */
	tex_width = 1024;
	tex_height = 1024;
	if (side == 0)
	{
		if (ray->ray_dir_x > 0)
			tex_addr = mlx_get_data_addr(game->map->imgs->we_img,
				&tex_bpp, &tex_line_len, &tex_endian);
		else
			tex_addr = mlx_get_data_addr(game->map->imgs->ea_img,
				&tex_bpp, &tex_line_len, &tex_endian);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			tex_addr = mlx_get_data_addr(game->map->imgs->no_img,
				&tex_bpp, &tex_line_len, &tex_endian);
		else
			tex_addr = mlx_get_data_addr(game->map->imgs->so_img,
				&tex_bpp, &tex_line_len, &tex_endian);
	}
	tex_x = ft_get_texture_x(side, wallX, tex_width, ray);
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = ((y - draw_start) * tex_height) / (draw_end - draw_start);
		color = *(unsigned int *)(tex_addr + (tex_y * tex_line_len +
					tex_x * (tex_bpp / 8)));
		ft_mlx_pixel_put_to_image(game, x, y, color);
		y++;
	}
}
