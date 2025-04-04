/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:56:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/01 15:58:15 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_mlx_pixel_put_to_image(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = game->img->addr + (y * game->img->line_len + x * (game->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_line(t_game *game, int x, int draw_start, int draw_end, int side)
{
	int	y;
	int	color;

	y = draw_start;
	if (side == 1)
		color = 0x00FF00;  /* Green for y-sides */
	else
		color = 0xFF0000;  /* Red for x-sides */
	while (y < draw_end)
	{
		ft_mlx_pixel_put_to_image(game, x, y, color);
		y++;
	}
}
