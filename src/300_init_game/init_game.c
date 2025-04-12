/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:12:01 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/12 21:29:32 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_graphics(t_game *game);

void	ft_init_game(t_game *game)
{
	ft_init_player(game);
	ft_init_graphics(game);
}

static void	ft_init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	printf("player pos x %f.2\n", game->player->pos_x);
	printf("player pos y %f.2\n", game->player->pos_y);
	if (!game->mlx)
		ft_cleanup(game, MLX_INIT_FAIL, 2);
	game->img = ft_safe_malloc(sizeof(t_img));
	if (!game->img)
		ft_cleanup(game, MLX_INIT_FAIL, 2);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d");
	game->img->mlx_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->mlx_img, &game->img->bpp,
			&game->img->line_len, &game->img->endian);
	ft_load_textures(game);
	mlx_loop_hook(game->mlx, ft_render_next_frame, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_handle_key, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, ft_handle_key_release, game);
	mlx_hook(game->win, 17, 1L<<17, &ft_quit_game, game);
}
