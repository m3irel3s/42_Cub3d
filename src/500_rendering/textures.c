/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:00:00 by yourname          #+#    #+#             */
/*   Updated: 2025/04/03 16:55:41 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_load_textures(t_game *game)
{
	int	width;
	int	height;

	game->map->imgs = ft_safe_malloc(sizeof(t_texture));
	if (!game->map->imgs)
		ft_cleanup(game, "Error allocating texture structure", 1);
	game->map->imgs->no_img = mlx_xpm_file_to_image(game->mlx, game->map->paths->no_path, &width, &height);
	if (!game->map->imgs->no_img)
		ft_cleanup(game, "Error loading NO texture", 1);
	game->map->imgs->so_img = mlx_xpm_file_to_image(game->mlx, game->map->paths->so_path, &width, &height);
	if (!game->map->imgs->so_img)
		ft_cleanup(game, "Error loading SO texture", 1);
	game->map->imgs->we_img = mlx_xpm_file_to_image(game->mlx, game->map->paths->we_path, &width, &height);
	if (!game->map->imgs->we_img)
		ft_cleanup(game, "Error loading WE texture", 1);
	game->map->imgs->ea_img = mlx_xpm_file_to_image(game->mlx, game->map->paths->ea_path, &width, &height);
	if (!game->map->imgs->ea_img)
		ft_cleanup(game, "Error loading EA texture", 1);
}
