/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:09:46 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/18 22:17:34 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	ft_is_facing_door(t_game *game, t_door_data *door)
{
	double	px;
	double	py;
	double	dx;
	double	dy;
	double	dot;

	px = game->player->pos_x;
	py = game->player->pos_y;
	dx = door->pos.x + 0.5 - px;
	dy = door->pos.y + 0.5 - py;
	if (dx < -2.0 || dx > 2.0 || dy < -2.0 || dy > 2.0)
		return (false);
	dot = dx * game->player->dir_x + dy * game->player->dir_y;
	if (dot > 0.0)
		return (true);
	return (false);
}

void	ft_handle_gate_animation(t_game *game)
{
	int				i;
	t_door_data		*door;

	i = 0;
	while (i < game->map->num_gates)
	{
		door = &game->map->gates[i];
		if (ft_is_facing_door(game, door))
		{
			if (door->state == DOOR_CLOSED)
				door->state = DOOR_OPENING;
			else if (door->state == DOOR_OPEN)
				door->state = DOOR_CLOSING;
		}
		i++;
	}
}
