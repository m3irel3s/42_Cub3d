/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:01:37 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/23 00:43:31 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_safe_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
	{
		ft_printf(2, "Err malloc failed\n");
		//fix here LMAO
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
