/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:01:37 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/23 15:52:30 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Safely allocates memory on the heap.
 *
 * @param size The size of memory to allocate.
 *
 * @return A pointer to the allocated memory or NULL if the allocation failed.
 * If the allocation failed, an error message is printed to stderr.
 */
void	*ft_safe_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
	{
		ft_printf(2, MALLOC_FAILED);
		return (NULL);
	}
	return (p);
}

/**
 * Checks if a file descriptor is valid.
 *
 * @param game The game struct containing the game state.
 * @param path The path to the file to check.
 *
 * @return The file descriptor if the file exists and can be opened, or -1
 * otherwise. If the file cannot be opened, the program is exited with an
 * error message.
 */
int	ft_valid_fd(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_cleanup(game, INVALID_FD_OPEN, 2, EXIT_FAILURE);
	return (fd);
}
