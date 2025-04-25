/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_path_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:31:22 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

/**
 * @brief Verifies if the file path passed as argument to the program has a
 *        valid name.
 *
 * The function checks if the file path has a '.cub' extension. It also checks
 * if the file is in the root directory or if it is in a directory with a name
 * that has a length of 5 or more characters. If the file does not meet these
 * conditions, the program is terminated and an error message is printed.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 */
void	ft_parse_file_path(t_game *game)
{
	char	*extension;
	char	*to_compare;

	extension = ft_strrchr(game->file_path, '.');
	to_compare = ft_strrchr(game->file_path, '/');
	if (extension && (ft_strcmp(extension, ".cub") == 0))
	{
		if (to_compare == NULL || ft_strlen(to_compare) > 5)
			return ;
	}
	ft_cleanup(game, INVALID_FILE_NAME, 2, EXIT_FAILURE);
}
