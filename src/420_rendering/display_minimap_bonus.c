/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:41:20 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/23 16:32:23 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_calc_minimap_scale(t_game *game);
static void	ft_scale_minimap(t_game *game, void *orig_img,
				int orig_w, int orig_h);
static void	ft_blit_minimap_line(t_game *game, char *orig_addr,
				int line_len, int bpp, int orig_w, int orig_h, int y);

/**
 * @brief Displays the minimap within the game window.
 *
 * Loads the minimap image, scales it to the screen size, centers it,
 * then draws the grid and player icon. Frees old images to avoid leaks.
 *
 * @param game The game structure containing rendering state.
 */
void	ft_display_minimap(t_game *game)
{
	void	*orig_img;
	int		orig_w;
	int		orig_h;

	if (game->img->mlx_img)
		mlx_destroy_image(game->mlx, game->img->mlx_img);
	orig_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/minimap.xpm", &orig_w, &orig_h);
	if (!orig_img)
		ft_cleanup(game, ERR_TEXTURE, 2, EXIT_FAILURE);
	ft_scale_minimap(game, orig_img, orig_w, orig_h);
	mlx_destroy_image(game->mlx, orig_img);
	ft_calc_minimap_scale(game);
	ft_draw_grid(game);
	ft_draw_player(game);
}

/**
 * @brief Calculates minimap scale and origin based on map dimensions.
 *
 * Centers the minimap horizontally and vertically using MINIMAP_RATIO.
 *
 * @param game The game structure containing the map grid.
 */
static void	ft_calc_minimap_scale(t_game *game)
{
	int	max_w;
	int	h;

	max_w = 0;
	h = 0;
	while (game->map->grid[h])
	{
		if ((int)ft_strlen(game->map->grid[h]) > max_w)
			max_w = ft_strlen(game->map->grid[h]);
		h++;
	}
	game->map->minimap.scale = (SCREEN_HEIGHT
			/ game->map->height) * MINIMAP_RATIO;
	game->map->minimap.start_x = SCREEN_WIDTH * 0.55
		- ((max_w * game->map->minimap.scale) / 2);
	game->map->minimap.start_y = SCREEN_HEIGHT / 2
		- ((game->map->height * game->map->minimap.scale) / 2);
}

/**
 * @brief Scales the minimap background to screen and stores in img.
 *
 * Copies each pixel from original image into a new full‐screen image.
 *
 * @param game    The game structure for rendering.
 * @param orig_img Original XPM minimap image.
 * @param orig_w  Original image width.
 * @param orig_h  Original image height.
 */
static void	ft_scale_minimap(t_game *game, void *orig_img,
	int orig_w, int orig_h)
{
	char	*orig_addr;
	int		bpp;
	int		line_len;
	int		y;

	orig_addr = mlx_get_data_addr(orig_img, &bpp,
			&line_len, &game->img->endian);
	game->img->mlx_img = mlx_new_image(game->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->mlx_img,
			&game->img->bpp, &game->img->line_len,
			&game->img->endian);
	y = -1;
	while (++y < SCREEN_HEIGHT)
		ft_blit_minimap_line(game, orig_addr, line_len,
			bpp, orig_w, orig_h, y);
}

/**
 * @brief Blits one horizontal line of the scaled minimap.
 *
 * Calculates source X/Y and writes pixel by pixel.
 *
 * @param game      Game structure for putting pixels.
 * @param orig_addr Address of original image data.
 * @param line_len  Bytes per line in original image.
 * @param bpp       Bits per pixel of original image.
 * @param orig_w    Original image width.
 * @param orig_h    Original image height.
 * @param y         Screen Y coordinate to draw.
 */
static void	ft_blit_minimap_line(t_game *game, char *orig_addr,
	int line_len, int bpp, int orig_w, int orig_h, int y)
{
	int	x;
	int	orig_x;
	int	orig_y;
	int	color;

	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		orig_x = (float)x / SCREEN_WIDTH * orig_w;
		orig_y = (float)y / SCREEN_HEIGHT * orig_h;
		color = *(int *)(orig_addr
				+ orig_y * line_len + orig_x * (bpp / 8));
		ft_mlx_pixel_put_to_image(game, x, y, color);
	}
}
