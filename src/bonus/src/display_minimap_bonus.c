/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:41:20 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/11 22:02:53 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

# define MINIMAP_PATH "../textures/minimap.xpm"
# define MINIMAP_SCALE 4
# define COLOR_WALL 0x00FF0000
# define COLOR_SPACE 0x00A9A9A9
# define COLOR_EMPTY 0x00000000

void	ft_display_minimap(t_game *game)
{
	if (game->mlx && game->img->mlx_img)
		mlx_destroy_image(game->mlx, game->img->mlx_img);
	game->img->mlx_img = mlx_xpm_file_to_image(game->mlx,
			MINIMAP_PATH, game->img->width, game->img->height);
	if (!game->img->mlx_img)
		ft_cleanup(game, "Error\nFailed to load minimap texture", 2);
	game->img->addr = mlx_get_data_addr(game->img->mlx_img,
			&game->img->bits_per_pixel, &game->img->line_length,
			&game->img->endian);
	if (!game->img->addr)
		ft_cleanup(game, "Error\nFailed to get minimap texture address", 2);
}

void	ft_draw_minimap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map->grid[i]))
		{
			if (game->map->grid[i][j] == '1')
				ft_put_pixel_block(game, j, i, COLOR_WALL);
			else if (game->map->grid[i][j] == '0')
				ft_put_pixel_block(game, j, i, COLOR_SPACE);
			else if (game->map->grid[i][j] == ' ')
				ft_put_pixel_block(game, j, i, COLOR_EMPTY);
			j++;
		}
		i++;
	}
	/* Desenha o jogador no centro do minimapa em cor verde */
	ft_put_pixel_block(game, (int)(game->player->pos_x),
		(int)(game->player->pos_y), 0x0000FF00);
}

void	ft_put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = game->img->addr + (y * game->img->line_length +
			x * (game->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
	Desenha um bloco MINIMAP_SCALE x MINIMAP_SCALE na posição (x, y)
	da grade do minimapa. Essa função multiplica as coordenadas pela escala.
*/
void	ft_put_pixel_block(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	start_x = x * MINIMAP_SCALE;
	start_y = y * MINIMAP_SCALE;
	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			ft_put_pixel(game, start_x + j, start_y + i, color);
			j++;
		}
		i++;
	}
}
