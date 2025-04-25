/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:22 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/24 17:14:47 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * Main function to start the game loop.
 *
 * It takes 2 arguments:
 * 	- argc: the number of command line arguments
 * 	- argv: an array of strings containing the command line arguments
 *
 * It first checks if the number of arguments is correct (only 1 argument, the
 * .cub file path).
 * Then it initializes the game structure, parses the .cub file, initializes
 * the game, and starts the game loop.
 *
 * If any error occurs, it prints the error message and exits the program with
 * the error code.
 *
 * @param argc number of command line arguments
 * @param argv an array of strings containing the command line arguments
 * @return 0 if the program runs without errors, 1 otherwise
 */
int	main(int argc, char **argv)
{
	t_game		*game;

	(void)argv;
	(void)argc;
	game = NULL;
	if (argc != 2)
		return (ft_putstr_fd(INVALID_ARGUMENTS, 2), FAILURE);
	game = ft_init_structs();
	if (!game)
		ft_cleanup(game, STRUCT_INIT_FAILED, 2, EXIT_FAILURE);
	ft_parse(game, argv);
	ft_init_game(game);
	mlx_loop(game->mlx);
	return (SUCCESS);
}
