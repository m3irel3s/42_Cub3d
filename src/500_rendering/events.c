/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:30:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/02 09:29:46 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_handle_key(int key, t_game *game)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.2;
	rot_speed = 0.1;
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
	else if (key == 13)
		ft_move_forward(game, move_speed);
	else if (key == 1)
		ft_move_backward(game, move_speed);
	else if (key == 0)
		ft_move_left(game, move_speed);
	else if (key == 2)
		ft_move_right(game, move_speed);
	else if (key == 123)
		ft_rotate_left(game, rot_speed);
	else if (key == 124)
		ft_rotate_right(game, rot_speed);
	return (0);
}
