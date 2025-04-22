/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:44:54 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 16:21:38 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void ft_load_single_texture(t_game *game, char *path, t_wall_side index);

/**
 * @brief Loads all textures from the header tags and stores them
 * in game->textures.
 *
 * @param game The game struct containing the game state.
 */
void	ft_load_textures(t_game *game)
{
	int			i;
	t_tag		tag;
	t_headers	*headers;
	char		*value;

	i = 0;
	headers = game->headers;
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
	ft_load_gate_textures(game);
	ft_load_and_init_intro_textures(game);
}

/**
 * Loads a texture image from the specified file path and stores it in the
 * game's texture array at the designated index.
 *
 * This function uses the MiniLibX library to load an XPM image file and
 * retrieve its memory address. If the image or its address cannot be
 * obtained, the function triggers cleanup and exits the game.
 *
 * @param game The game data structure that contains the texture array.
 * @param path The file path to the texture image.
 * @param index The index in the texture array where the loaded texture
 *              should be stored, corresponding to the wall side.
 */
static void	ft_load_single_texture(t_game *game, char *path, t_wall_side index)
{
	game->textures[index].mlx_img = mlx_xpm_file_to_image(game->mlx, path,
			&game->textures[index].width, &game->textures[index].height);
	if (!game->textures[index].mlx_img)
		ft_cleanup(game, ERR_TEXTURE, 1);
	game->textures[index].addr
		= mlx_get_data_addr(game->textures[index].mlx_img,
			&game->textures[index].bpp, &game->textures[index].line_len,
			&game->textures[index].endian);
	if (!game->textures[index].addr)
		ft_cleanup(game, ERR_TEXTURE_ADDR, 1);
}
