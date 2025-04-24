/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:53:37 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/24 17:14:09 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	ft_handle_horizontal_movement(int delta_x, t_game *game);

int	ft_mouse_move_handler(int x, int y, t_game *game)
{
	int			center_x;
	int			center_y;
	int			delta_x;
	int			delta_y;
	static int	first_call;

	center_x = SCREEN_WIDTH / 2;
	center_y = SCREEN_HEIGHT / 2;
	if (first_call)
	{
		mlx_mouse_move(game->mlx, game->win, center_x, center_y);
		first_call = 0;
		return (0);
	}
	delta_x = x - center_x;
	delta_y = y - center_y;
	ft_handle_horizontal_movement(delta_x, game);
	mlx_mouse_move(game->mlx, game->win, center_x, center_y);
	return (0);
}

static int	ft_handle_horizontal_movement(int delta_x, t_game *game)
{
	float	sensitivity_x;

	sensitivity_x = 0.0004;
	if (delta_x != 0)
	{
		ft_rotate(game, delta_x * sensitivity_x);
	}
	return (0);
}
