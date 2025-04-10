/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:38:45 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/10 17:35:48 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	ft_rgb_to_hex(int r, int g, int b);

void	ft_set_floor_n_ceiling(t_game *game)
{
	t_rgb	f_col;

	f_col = game->floor_color;
	game->floor_color_hex = ft_rgb_to_hex(f_col.r, f_col.g, f_col.b);
	f_col = game->ceiling_color;
	game->ceiling_color_hex = ft_rgb_to_hex(f_col.r, f_col.g, f_col.b);
}

static int	ft_rgb_to_hex(int r, int g, int b)
{
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	if (b > 255)
		b = 255;
	return ((r << 16) | (g << 8) | b);
}
