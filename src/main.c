/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:22 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/02 10:25:53 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_init_graphics(t_game *game);

void ft_test(t_game *game)
{
	game->player = ft_safe_malloc(sizeof(t_player));
	if (!game->player)
		ft_cleanup(game, "Error allocating player", 1);
	game->player->pos_x = 3.5;
	game->player->pos_y = 3.5;
	game->player->dir_x = -1;
	game->player->dir_y = 0;
	game->player->plane_x = 0;    // Explicitly set
	game->player->plane_y = 0.66; // Field of view adjustment
	/* Map initialization remains the same */
	game->map->grid = malloc(sizeof(char *) * 8);
	if (!game->map->grid)
		ft_cleanup(game, "Error allocating map grid", 1);
	game->map->grid[0] = "1111111";
	game->map->grid[1] = "1000001";
	game->map->grid[2] = "1011101";
	game->map->grid[3] = "1000001";
	game->map->grid[4] = "1010101";
	game->map->grid[5] = "1000001";
	game->map->grid[6] = "1111111";
	game->map->grid[7] = NULL;
	game->map->width = 7;
	game->map->height = 7;
}

int	main(int argc, char **argv)
{
	t_game	*game;
	(void)argv;
	(void)argc;

	// game = NULL;
	// if (argc != 2)
	// 	return (ft_putstr_fd("Invalid arguments given\n", 2), FAILURE);
	game = ft_init_structs();
	//ft_parse(game, argv);

	ft_test(game);
	ft_init_graphics(game);
	mlx_loop(game->mlx);
	ft_cleanup(game, "", 1);
	return (SUCCESS);
}

/*************  ✨ Codeium Command ⭐  *************/
/**
 * ft_quit_game:
 * @game: The game structure containing all game-relevant data.
 *
 * Cleans up the game and its resources, then exits the game loop.
 *
 * Returns: 0
 */
/******  c99fbfee-4a7a-4238-bece-106b67a1e722  *******/
int ft_quit_game(t_game *game)
{
	ft_cleanup(game, "Game exited", 0);
	return (0);
}

static void	ft_init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_cleanup(game, "MLX initialization failed", 1);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d Test");
	game->img = ft_safe_malloc(sizeof(t_img));
	if (!game->img)
		ft_cleanup(game, "Error allocating image", 1);
	game->img->mlx_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->mlx_img, &game->img->bpp,
			&game->img->line_len, &game->img->endian);
	mlx_loop_hook(game->mlx, ft_render_next_frame, game);
	mlx_hook(game->win, 2, 1L << 0, ft_handle_key, game);
	mlx_hook(game->win, 17, 1L<<17, &ft_quit_game, game);
}
