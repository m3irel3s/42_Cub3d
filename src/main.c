/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:22 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/10 16:39:54 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		return (ft_putstr_fd(INVALID_ARGUMENTS, 2), FAILURE);
	game = ft_init_structs();
	if (!game)
		ft_cleanup(game, INIT_FAILED, 2);
	ft_parse(game, argv);
	ft_init_game(game);
	mlx_loop(game->mlx);
	ft_cleanup(game, "", 1);
	return (SUCCESS);
}

// #define NO_PATH "textures/no.xpm"
// #define SO_PATH "textures/so.xpm"
// #define WE_PATH "textures/we.xpm"
// #define EA_PATH "textures/ea.xpm"

// static void	ft_init_graphics(t_game *game);

// void ft_test(t_game *game)
// {
// 	int i, j;
// 	char orientation;

// 	// Alocar o player
// 	game->player = ft_safe_malloc(sizeof(t_player));
// 	if (!game->player)
// 		ft_cleanup(game, "Error allocating player", 1);

// 	/* Inicializa o mapa manualmente.
// 	Neste exemplo, vamos usar 7 linhas e cada linha tem 21 colunas. */
// 	game->map->grid = malloc(sizeof(char *) * 8); // 7 linhas + 1 para NULL
// 	if (!game->map->grid)
// 		ft_cleanup(game, "Error allocating map grid", 1);

// 	// Aqui usamos strings literais para exemplo, mas em produção
// 	// convém duplicá-las para que possam ser modificadas.
// 	game->map->grid[0] = ft_strdup("    11111111");
// 	game->map->grid[1] = ft_strdup("1111000100001");
// 	game->map->grid[2] = ft_strdup("1 11110000W001110011");
// 	game->map->grid[3] = ft_strdup("10000001100100001001");
// 	game->map->grid[4] = ft_strdup("101010100001001010001");
// 	game->map->grid[5] = ft_strdup(" 1110000000 1001010001");
// 	game->map->grid[6] = ft_strdup("111111111111111111111");
// 	game->map->grid[7] = NULL;

// 	// Define a largura e altura do mapa com base no número de colunas e linhas.
// 	// Neste exemplo, cada linha tem 21 caracteres e há 7 linhas.
// 	game->map->map_size = 7;

// 	/*
// 	* Procura na grid o carácter de orientação (N, S, E ou W) para definir
// 	* a posição inicial e a orientação do jogador.
// 	*/
// 	for (i = 0; i < (int)game->map->map_size; i++)
// 	{
// 		for (j = 0; j < (int)ft_strlen(game->map->grid[i]); j++)
// 		{
// 			orientation = game->map->grid[i][j];
// 			if (orientation == 'N' || orientation == 'S' ||
// 				orientation == 'E' || orientation == 'W')
// 			{
// 				// Posicionar o jogador no centro da célula
// 				game->player->pos_x = j + 0.5;
// 				game->player->pos_y = i + 0.5;

// 				// Definir os vetores de direção e do plano de acordo com a orientação
// 				if (orientation == 'N')
// 				{
// 					game->player->dir_x = 0;
// 					game->player->dir_y = -1;
// 					game->player->plane_x = FOV;
// 					game->player->plane_y = 0;
// 				}
// 				else if (orientation == 'S')
// 				{
// 					game->player->dir_x = 0;
// 					game->player->dir_y = 1;
// 					game->player->plane_x = -FOV;
// 					game->player->plane_y = 0;
// 				}
// 				else if (orientation == 'E')
// 				{
// 					game->player->dir_x = 1;
// 					game->player->dir_y = 0;
// 					game->player->plane_x = 0;
// 					game->player->plane_y = FOV;
// 				}
// 				else if (orientation == 'W')
// 				{
// 					game->player->dir_x = -1;
// 					game->player->dir_y = 0;
// 					game->player->plane_x = 0;
// 					game->player->plane_y = -FOV;
// 				}

// 				// Opcional: substituir a célula por um espaço vazio ('0')
// 				game->map->grid[i][j] = '0';

// 				// Encontrado o ponto de partida; podemos sair dos loops.
// 				goto end_search;
// 			}
// 		}
// 	}
// end_search:
// 	; // Apenas para terminar o goto

// 	// Se nenhum carácter de orientação for encontrado, podes definir um valor padrão ou lançar erro.
// 	// Exemplo: se não tiver sido configurado o player, podes definir valores padrão.
// 	// (Neste exemplo, assumimos que sempre haverá um marcador de orientação.)
// }



// int	main(int argc, char **argv)
// {
// 	t_game	*game;

// 	game = NULL;
// 	if (argc != 2)
// 		return (ft_putstr_fd("Invalid arguments given\n", 2), FAILURE);
// 	game = ft_init_structs();
// 	ft_parse(game, argv);
// 	ft_test(game);
// 	ft_init_graphics(game);
// 	mlx_loop(game->mlx);
// 	ft_cleanup(game, "", 1);
// 	return (SUCCESS);
// }

// int ft_quit_game(t_game *game)
// {
// 	ft_cleanup(game, "Game exited", 0);
// 	return (0);
// }

// static void	ft_init_graphics(t_game *game)
// {
// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 		ft_cleanup(game, "MLX initialization failed", 1);
// 	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d Test");
// 	game->img = ft_safe_malloc(sizeof(t_img));
// 	if (!game->img)
// 		ft_cleanup(game, "Error allocating image", 1);
// 	game->img->mlx_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	game->img->addr = mlx_get_data_addr(game->img->mlx_img, &game->img->bpp,
// 			&game->img->line_len, &game->img->endian);
// 	ft_load_textures(game);
// 	mlx_loop_hook(game->mlx, ft_render_next_frame, game);
// 	mlx_hook(game->win, 2, 1L << 0, ft_handle_key, game);
// 	mlx_hook(game->win, 17, 1L<<17, &ft_quit_game, game);
// }
