/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:44:54 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/04 20:50:09 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_load_textures(t_game *game)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	game->textures = ft_safe_malloc(sizeof(t_texture) * 4);
	if (!game->textures)
		ft_cleanup(game, "Error allocating texture structure", 1);
	while(i < 6)
	{
		if (game->headers[i].tag != C_TAG && game->headers[i].tag != F_TAG)
		{
			game->textures[j].no_img = mlx_xpm_file_to_image(game->mlx, game->headers[i].value, &game->textures[j].width, &game->textures[j].height);
			j++;
		}
		i++;
	}
}

void	ft_load_textures_addr(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img, &game->textures[i].bpp, &game->textures[i].line_len, &game->textures[i].endian);
		i++;
	}
}
