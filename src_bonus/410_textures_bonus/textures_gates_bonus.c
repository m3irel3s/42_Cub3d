/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_gates_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:16:29 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_set_path_arr(char **path);

/**
 * @brief Loads all gate textures from the specified file paths and stores them
 * in game->gate_textures.
 *
 * The function allocates an array of 9 file paths, which are set by
 * ft_set_path_arr. It then uses MiniLibX to load each image file and
 * retrieve its address.
 *
 * If any of the image files or their addresses cannot be obtained, the function
 * triggers cleanup and exits the game.
 *
 * @param game The game data structure containing the gate textures array.
 */
void	ft_load_gate_textures(t_game *game)
{
	int		i;
	char	**path;

	path = ft_safe_malloc(sizeof(char *) * 9);
	if (!path)
		ft_cleanup(game, MALLOC_FAILED, 2, EXIT_FAILURE);
	ft_set_path_arr(path);
	i = 0;
	while (i < 8)
	{
		game->gate_textures[i].mlx_img = mlx_xpm_file_to_image(game->mlx,
				path[i], &game->gate_textures[i].width,
				&game->gate_textures[i].height);
		if (!game->gate_textures[i].mlx_img)
			ft_cleanup(game, ERR_TEXTURE, 2, EXIT_FAILURE);
		game->gate_textures[i].addr = mlx_get_data_addr(
				game->gate_textures[i].mlx_img,
				&game->gate_textures[i].bpp,
				&game->gate_textures[i].line_len,
				&game->gate_textures[i].endian);
		if (!game->gate_textures[i].addr)
			ft_cleanup(game, ERR_TEXTURE_ADDR, 2, EXIT_FAILURE);
		i++;
	}
	ft_free_arr(path);
}

/**
 * @brief Sets the file paths for the gate textures.
 *
 * The function allocates and assigns the file paths for the gate textures
 * to the specified array. The paths are for the images in the ./textures
 * directory and are door1.xpm to door8.xpm.
 *
 * @param path An array of pointers to char, where each element is a file path.
 */
static void	ft_set_path_arr(char **path)
{
	path[0] = ft_strdup("./textures/door1.xpm");
	path[1] = ft_strdup("./textures/door2.xpm");
	path[2] = ft_strdup("./textures/door3.xpm");
	path[3] = ft_strdup("./textures/door4.xpm");
	path[4] = ft_strdup("./textures/door5.xpm");
	path[5] = ft_strdup("./textures/door6.xpm");
	path[6] = ft_strdup("./textures/door7.xpm");
	path[7] = ft_strdup("./textures/door8.xpm");
	path[8] = NULL;
}
