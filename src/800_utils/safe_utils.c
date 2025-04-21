/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:01:37 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/21 17:35:36 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	ft_valid_fd(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_cleanup(game, INVALID_FD_OPEN, 2);
	return (fd);
}
