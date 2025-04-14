/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:09:46 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/14 17:17:14 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool ft_is_facing_door(t_game *game, t_door_data *door)
{
	int	px;
	int	py;
	int	dx;
	int	dy;

	px = (int)game->player->pos_x;
	py = (int)game->player->pos_y;
	dx = door->pos.x;
	dy = door->pos.y;
	if ((px == dx && abs(py - dy) == 1) || (py == dy && abs(px - dx) == 1))
	{
		if ((py == dy - 1 && game->player->dir_y > 0) ||
			(py == dy + 1 && game->player->dir_y < 0) ||
			(px == dx - 1 && game->player->dir_x > 0) ||
			(px == dx + 1 && game->player->dir_x < 0))
			return (true);
	}
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
