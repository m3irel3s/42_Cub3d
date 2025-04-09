/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:30:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/09 22:27:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#ifdef __APPLE__
static void	ft_handle_key_app(int key, t_game *game,
				double move_speed, double rot_speed)
{
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
}
#endif

#ifdef __linux__
static void	ft_handle_key_linux(int key, t_game *game,
				double move_speed, double rot_speed)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
	else if (key == XK_w || key == 119)
		ft_move_forward(game, move_speed);
	else if (key == XK_s || key == 115)
		ft_move_backward(game, move_speed);
	else if (key == XK_a || key == 97)
		ft_move_left(game, move_speed);
	else if (key == XK_d || key == 100)
		ft_move_right(game, move_speed);
	else if (key == XK_Left)
		ft_rotate_left(game, rot_speed);
	else if (key == XK_Right)
		ft_rotate_right(game, rot_speed);
}
#endif

int	ft_handle_key(int key, t_game *game)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.2;
	rot_speed = 0.1;
#ifdef __APPLE__
	ft_handle_key_app(key, game, move_speed, rot_speed);
#elif __linux__
	ft_handle_key_linux(key, game, move_speed, rot_speed);
#endif
	return (0);
}
