/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:41:20 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/23 16:04:47 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_calc_minimap_scale(t_game *game);
static void	ft_scale_minimap(t_game *game, void *orig_img, int orig_w, int orig_h);

void	ft_display_minimap(t_game *game)
{
	void	*orig_img;
	int		orig_width;
	int		orig_height;

	if (game->img->mlx_img)
			mlx_destroy_image(game->mlx, game->img->mlx_img);
	orig_img = mlx_xpm_file_to_image(game->mlx, "./textures/minimap.xpm",
			&orig_width, &orig_height);
	if (!orig_img)
		ft_cleanup(game, ERR_TEXTURE, 2, EXIT_FAILURE);
	ft_scale_minimap(game, orig_img, orig_width, orig_height);
	mlx_destroy_image(game->mlx, orig_img);
	ft_calc_minimap_scale(game);
	ft_draw_grid(game);
	ft_draw_player(game);
}

static void	ft_calc_minimap_scale(t_game *game)
{
	int	max_width;
	int	height;

	max_width = 0;
	height = 0;
	while (game->map->grid[height])
	{
		if ((int)ft_strlen(game->map->grid[height]) > max_width)
			max_width = ft_strlen(game->map->grid[height]);
		height++;
	}
	game->map->minimap.scale = (SCREEN_HEIGHT / game->map->height) * MINIMAP_RATIO;
	game->map->minimap.start_x = SCREEN_WIDTH * 0.55 - ((max_width * game->map->minimap.scale) / 2);
	game->map->minimap.start_y = SCREEN_HEIGHT / 2 - ((game->map->height * game->map->minimap.scale) / 2);
}

static void	ft_scale_minimap(t_game *game, void *orig_img, int orig_w, int orig_h)
{
	char	*orig_addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;

	orig_addr = mlx_get_data_addr(orig_img, &bpp, &line_len, &endian);
	game->img->mlx_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->mlx_img, &game->img->bpp,
			&game->img->line_len, &game->img->endian);
	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			int orig_x = (float)x / SCREEN_WIDTH * orig_w;
			int orig_y = (float)y / SCREEN_HEIGHT * orig_h;
			int color = *(int *)(orig_addr + (orig_y * line_len + orig_x * (bpp / 8)));
			ft_mlx_pixel_put_to_image(game, x, y, color);
		}
	}
}
