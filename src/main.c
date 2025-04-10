/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:22 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/10 17:50:22 by meferraz         ###   ########.fr       */
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
