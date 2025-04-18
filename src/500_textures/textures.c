/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:44:54 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/18 21:54:55 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_load_single_texture(t_game *game, char *path, t_wall_side side);
void	ft_set_path_arr(char **path);
/**
 * @brief Loads all textures from the header tags and stores them
 * in game->textures.
 *
 * @param game The game struct containing the game state.
 */
void	ft_load_textures(t_game *game)
{
	int			i;
	t_headers	*header;

	i = 0;
	while (i < 6)
	{
		header = &game->headers[i];
		if (header->tag == NO_TAG)
			ft_load_single_texture(game, header->value, NORTH);
		else if (header->tag == SO_TAG)
			ft_load_single_texture(game, header->value, SOUTH);
		else if (header->tag == EA_TAG)
			ft_load_single_texture(game, header->value, EAST);
		else if (header->tag == WE_TAG)
			ft_load_single_texture(game, header->value, WEST);
		i++;
	}
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
		ft_cleanup(game, "Error\nLoading texture", 1);
	game->textures[index].addr
		= mlx_get_data_addr(game->textures[index].mlx_img,
			&game->textures[index].bpp, &game->textures[index].line_len,
			&game->textures[index].endian);
	if (!game->textures[index].addr)
		ft_cleanup(game, "Error\nGetting texture address", 1);
}

void	ft_load_gate_textures(t_game *game)
{
	int		i;
	char	**path;

	path = ft_safe_malloc(sizeof(char *) * 8);
	if (!path)
		ft_cleanup(game, "Error\nAllocating path array", 1);
	ft_set_path_arr(path);
	i = 0;
	while (i < 8)
	{
		game->gate_textures[i].mlx_img = mlx_xpm_file_to_image(game->mlx, path[i],
				&game->gate_textures[i].width, &game->gate_textures[i].height);
		if (!game->gate_textures[i].mlx_img)
			ft_cleanup(game, "Error\nLoading gate texture", 1);
		game->gate_textures[i].addr = mlx_get_data_addr(
				game->gate_textures[i].mlx_img,
				&game->gate_textures[i].bpp,
				&game->gate_textures[i].line_len,
				&game->gate_textures[i].endian);
		if (!game->gate_textures[i].addr)
			ft_cleanup(game, "Error\nGetting gate texture address", 1);
		i++;
	}
	//ft_free_arr(path);
}

void	ft_set_path_arr(char **path)
{
	path[0] = ft_strdup("./textures/door1.xpm");
	path[1] = ft_strdup("./textures/door2.xpm");
	path[2] = ft_strdup("./textures/door3.xpm");
	path[3] = ft_strdup("./textures/door4.xpm");
	path[4] = ft_strdup("./textures/door5.xpm");
	path[5] = ft_strdup("./textures/door6.xpm");
	path[6] = ft_strdup("./textures/door7.xpm");
	path[7] = ft_strdup("./textures/door8.xpm");
}
