/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:51:29 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/14 17:17:36 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_update_gates(t_game *game)
{
	int			i;
	t_door_data	*door;

	i = -1;
	while (++i < game->map->num_gates)
	{
		door = &game->map->gates[i];
		if (door->state == DOOR_OPENING && ++door->frame_count >= 5)
		{
			door->frame_count = 0;
			if (++door->frame >= 7)
				door->state = DOOR_OPEN;
		}
		else if (door->state == DOOR_CLOSING && ++door->frame_count >= 5)
		{
			door->frame_count = 0;
			if (--door->frame <= 0)
				door->state = DOOR_CLOSED;
		}
	}
}
