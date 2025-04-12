/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:41:20 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/12 20:52:27 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#define MINIMAP_RATIO 0.3
#define CELL_BORDER 0x0000000
#define COLOR_WALL 0x1a1a1c
#define COLOR_FLOOR 0xffd1ad
#define COLOR_PLAYER 0x681c2c

static void	ft_calc_minimap_scale(t_game *game);
static void	ft_draw_cell(t_game *game, int map_x, int map_y, t_cell type);
static void	ft_draw_grid(t_game *game);
static void	ft_draw_player(t_game *game);
static void	ft_render_minimap(t_game *game);
static void	ft_scale_minimap(t_game *game, void *orig_img, int orig_w, int orig_h);

void	ft_display_minimap(t_game *game)
{
	void	*orig_img;
	int		orig_width;
	int		orig_height;

	orig_img = mlx_xpm_file_to_image(game->mlx, "./textures/minimap.xpm",
			&orig_width, &orig_height);
	if (!orig_img)
		ft_cleanup(game, "Error\nMinimap background failed", 2);
	ft_scale_minimap(game, orig_img, orig_width, orig_height);
	mlx_destroy_image(game->mlx, orig_img);
	ft_calc_minimap_scale(game);
	ft_render_minimap(game);
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
	game->map->minimap.scale = (SCREEN_HEIGHT / game->map->height) \
		* MINIMAP_RATIO;
		game->map->minimap.start_x = SCREEN_WIDTH * 0.55 - \
		((max_width * game->map->minimap.scale) / 2);
	game->map->minimap.start_y = SCREEN_HEIGHT / 2 - \
		((game->map->height * game->map->minimap.scale) / 2);
}

void	ft_render_minimap(t_game *game)
{
	ft_draw_grid(game);
	ft_draw_player(game);
}

static void	ft_draw_grid(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map->grid[y]))
		{
			if (game->map->grid[y][x] == '1')
				ft_draw_cell(game, x, y, WALL);
			else if (game->map->grid[y][x] == '0')
				ft_draw_cell(game, x, y, FLOOR);
			else if (game->map->grid[y][x] == ' ')
				ft_draw_cell(game, x, y, EMPTY);
			x++;
		}
		y++;
	}
}

static void	ft_draw_cell(t_game *game, int map_x, int map_y, t_cell type)
{
	t_point	screen;
	int		color;
	int		y;
	int		x;

	color = 0x00000000;
	screen.x = game->map->minimap.start_x + map_x * game->map->minimap.scale;
	screen.y = game->map->minimap.start_y + map_y * game->map->minimap.scale;
	if (type == WALL)
		color = COLOR_WALL;
	else if (type == FLOOR)
		color = COLOR_FLOOR;
	y = 0;
	while (y < game->map->minimap.scale)
	{
		x = 0;
		while (x < game->map->minimap.scale)
		{
			if (y == 0 || x == 0 || y == game->map->minimap.scale - 1
				|| x == game->map->minimap.scale - 1)
				ft_mlx_pixel_put_to_image(game, screen.x + x, \
					screen.y + y, CELL_BORDER);
			else if (color != 0x00000000)
				ft_mlx_pixel_put_to_image(game, screen.x + x, \
					screen.y + y, color);
			x++;
		}
		y++;
	}
}

static void	ft_draw_direction(t_game *game, t_point center)
{
	t_point	end;
	double	scale;
	int		i;

	scale = game->map->minimap.scale * 1.5;
	end.x = center.x + (game->player->dir_x * scale);
	end.y = center.y + (game->player->dir_y * scale);
	i = -1;
	while (++i < (int)scale)
	{
		ft_mlx_pixel_put_to_image(game,
			center.x + game->player->dir_x * i,
			center.y + game->player->dir_y * i,
			COLOR_PLAYER);
	}
}

static void	ft_draw_player_circle(t_game *game, t_point center)
{
	int	x;
	int	y;
	int	radius;

	radius = 6;
	y = -radius - 1;
	while (++y <= radius)
	{
		x = -radius - 1;
		while (++x <= radius)
		{
			if (x * x + y * y <= radius * radius + radius * 0.8)
			{
				ft_mlx_pixel_put_to_image(game,
					center.x + x,
					center.y + y,
					COLOR_PLAYER);
			}
		}
	}
}

static void	ft_draw_player(t_game *game)
{
	t_point	center;

	center.x = game->map->minimap.start_x +
		(game->player->pos_x * game->map->minimap.scale);
	center.y = game->map->minimap.start_y +
		(game->player->pos_y * game->map->minimap.scale);

	ft_draw_player_circle(game, center);
	ft_draw_direction(game, center);
}
