/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_intro_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:17:14 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

static void	ft_load_intro_textures(t_game *game, char **frames);

/**
 * @brief Loads and initializes the intro textures for the game.
 *
 * This function sets up the paths for the intro animation frames,
 * allocates memory for the frame images, and initializes the animation
 * properties including frame count, current frame, frame duration, and
 * the last update time. It then loads the intro textures from the specified
 * file paths into memory.
 *
 * @param game The game struct containing the intro animation data.
 */

void	ft_load_and_init_intro_textures(t_game *game)
{
	char		*frames[5];

	frames[0] = "./textures/intro1.xpm";
	frames[1] = "./textures/intro2.xpm";
	frames[2] = "./textures/intro3.xpm";
	frames[3] = "./textures/intro4.xpm";
	frames[4] = "./textures/intro5.xpm";
	game->intro->animation.frames = ft_safe_malloc(sizeof(t_img) * 5);
	if (!game->intro->animation.frames)
		ft_cleanup(game, MALLOC_FAILED, 2, EXIT_FAILURE);
	game->intro->animation.frame_count = 5;
	game->intro->animation.current_frame = 0;
	game->intro->animation.frame_duration = 100;
	game->intro->animation.last_update = ft_get_time_ms();
	ft_load_intro_textures(game, frames);
}

/**
 * @brief Loads the intro textures for the game from the specified file paths.
 *
 * This function iterates through the frame count and loads the intro textures
 * from the specified file paths into memory. It uses mlx_xpm_file_to_image to
 * load the texture and mlx_get_data_addr to get the address of the texture.
 *
 * @param game The game struct containing the intro animation data.
 * @param frames An array of strings containing the file paths of the intro
 *               textures.
 */
static void	ft_load_intro_textures(t_game *game, char **frames)
{
	int	i;

	i = 0;
	while (i < game->intro->animation.frame_count)
	{
		game->intro->animation.frames[i].mlx_img
			= mlx_xpm_file_to_image(game->mlx, frames[i],
				&game->intro->animation.frames[i].width,
				&game->intro->animation.frames[i].height);
		if (!game->intro->animation.frames[i].mlx_img)
			ft_cleanup(game, ERR_TEXTURE, 2, EXIT_FAILURE);
		game->intro->animation.frames[i].addr
			= mlx_get_data_addr(game->intro->animation.frames[i].mlx_img,
				&game->intro->animation.frames[i].bpp,
				&game->intro->animation.frames[i].line_len,
				&game->intro->animation.frames[i].endian);
		if (!game->intro->animation.frames[i].addr)
			ft_cleanup(game, ERR_TEXTURE_ADDR, 2, EXIT_FAILURE);
		i++;
	}
}
