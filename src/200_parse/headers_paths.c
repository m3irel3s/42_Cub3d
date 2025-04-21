/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:38:43 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/21 21:57:46 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Checks the paths of the textures in the headers.
 *
 * This function iterates through the headers array and checks if the
 * tag is one of the texture tags. If it is, it calls ft_valid_fd to
 * check if the path is a valid file. If it is, it closes the file
 * descriptor. If not, it calls ft_cleanup to exit the program with
 * an error message.
 *
 * @param game The game struct containing the game state.
 * @param headers The headers array from the .cub file.
 */
void	ft_check_headers_textures(t_game *game, t_headers *headers)
{
	int	fd;
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (headers[i].tag == SO_TAG || headers[i].tag == NO_TAG
			|| headers[i].tag == EA_TAG || headers[i].tag == WE_TAG)
		{
			fd = ft_valid_fd(game, headers[i].value);
			close(fd);
		}
	}
}
