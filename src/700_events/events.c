/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:30:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/08 17:28:14 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_handle_key(int key, t_game *game)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.2;
	rot_speed = 0.1;
#ifdef __APPLE__
	if (key == 53) // ESC
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
	else if (key == 13) // W
		ft_move_forward(game, move_speed);
	else if (key == 1) // S
		ft_move_backward(game, move_speed);
	else if (key == 0) // A
		ft_move_left(game, move_speed);
	else if (key == 2) // D
		ft_move_right(game, move_speed);
	else if (key == 123) // Left arrow
		ft_rotate_left(game, rot_speed);
	else if (key == 124) // Right arrow
		ft_rotate_right(game, rot_speed);

#elif __linux__
	if (key == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
	else if (key == XK_w || key == 119) // W
		ft_move_forward(game, move_speed);
	else if (key == XK_s || key == 115) // S
		ft_move_backward(game, move_speed);
	else if (key == XK_a || key == 97)  // A
		ft_move_left(game, move_speed);
	else if (key == XK_d || key == 100) // D
		ft_move_right(game, move_speed);
	else if (key == XK_Left)
		ft_rotate_left(game, rot_speed);
	else if (key == XK_Right)
		ft_rotate_right(game, rot_speed);
#endif
	return (0);
}
