/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:44:54 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/04 16:54:40 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_load_textures(t_game *game)
{
	int	width;
	int	height;

	width = 1024;
	height = 1024;
	game->textures->no_img = mlx_xpm_file_to_image(game->mlx, game->paths->no_path, &width, &height);
	if (!game->textures->no_img)
		ft_cleanup(game, "Error loading NO texture", 1);
	game->textures->so_img = mlx_xpm_file_to_image(game->mlx, game->paths->so_path, &width, &height);
	if (!game->textures->so_img)
		ft_cleanup(game, "Error loading SO texture", 1);
	game->textures->we_img = mlx_xpm_file_to_image(game->mlx, game->paths->we_path, &width, &height);
	if (!game->textures->we_img)
		ft_cleanup(game, "Error loading WE texture", 1);
	game->textures->ea_img = mlx_xpm_file_to_image(game->mlx, game->paths->ea_path, &width, &height);
	if (!game->textures->ea_img)
		ft_cleanup(game, "Error loading EA texture", 1);
}

void	ft_load_addresses(t_game *game)
{
	game->textures->no_img->addr = mlx_get_data_addr(game->textures->no_img,
			&game->textures->no_img->bpp, &game->textures->no_img->line_len,
			&game->textures->no_img->endian);
	game->textures->so_img->addr = mlx_get_data_addr(game->textures->so_img,
			&game->textures->so_img->bpp, &game->textures->so_img->line_len,
			&game->textures->so_img->endian);
	game->textures->we_img->addr = mlx_get_data_addr(game->textures->we_img,
			&game->textures->we_img->bpp, &game->textures->we_img->line_len,
			&game->textures->we_img->endian);
	game->textures->ea_img->addr = mlx_get_data_addr(game->textures->ea_img,
			&game->textures->ea_img->bpp, &game->textures->ea_img->line_len,
			&game->textures->ea_img->endian);
}

void	ft_set_img_size(t_game *game)
{
	game->textures->no_img->width = 1024;
	game->textures->no_img->height = 1024;
	game->textures->so_img->width = 1024;
	game->textures->so_img->height = 1024;
	game->textures->we_img->width = 1024;
	game->textures->we_img->height = 1024;
	game->textures->ea_img->width = 1024;
	game->textures->ea_img->height = 1024;
}
