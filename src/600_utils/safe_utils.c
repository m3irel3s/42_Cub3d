/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:01:37 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/22 11:04:26 by meferraz         ###   ########.fr       */
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
		ft_printf(2, "Error\nmalloc failed\n");
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
		ft_cleanup(game, INVALID_FD_OPEN, 2);
	return (fd);
}
