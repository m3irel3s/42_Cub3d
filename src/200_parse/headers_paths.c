/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:38:43 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/07 17:02:19 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
