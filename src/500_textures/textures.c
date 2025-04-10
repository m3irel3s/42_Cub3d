/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:44:54 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/10 17:56:06 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void ft_load_single_texture(t_game *game, char *path, t_wall_side side);

void	ft_load_textures(t_game *game)
{
	int			i;
	t_tag		tag;
	t_headers	*headers;
	char		*value;

	i = 0;
	headers= game->headers;
	while (i < 6)
	{
		tag = headers[i].tag;
		value = headers[i].value;
		if (tag == NO_TAG)
			ft_load_single_texture(game, value, NORTH);
		else if (tag == SO_TAG)
			ft_load_single_texture(game, value, SOUTH);
		else if (tag == EA_TAG)
			ft_load_single_texture(game, value, EAST);
		else if (tag == WE_TAG)
			ft_load_single_texture(game, value, WEST);
		i++;
	}
}

static void	ft_load_single_texture(t_game *game, char *path, t_wall_side index)
{
	game->textures[index].mlx_img = mlx_xpm_file_to_image(game->mlx, path,
		&game->textures[index].width, &game->textures[index].height);
	if (!game->textures[index].mlx_img)
		ft_cleanup(game, "Error loading texture", 1);
	game->textures[index].addr = mlx_get_data_addr(game->textures[index].mlx_img,
		&game->textures[index].bpp, &game->textures[index].line_len,
		&game->textures[index].endian);
	if (!game->textures[index].addr)
		ft_cleanup(game, "Error getting texture address", 1);
}
