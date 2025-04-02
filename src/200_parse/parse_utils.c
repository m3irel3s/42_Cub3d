/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:42:48 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/02 15:30:55 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_valid_map_chars(char c)
{
	int		i;
	char	*valid_chars;

	i = 0;
	valid_chars = "01NSEW";
	while (valid_chars[i])
	{
		if (valid_chars[i] == c)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int	ft_set_grid_start_index(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->cub_file[i])
	{
		j = 0;
		while (ft_strchr(" ", game->cub_file[i][j]))
			j++;
		while (ft_strchr("1", game->cub_file[i][j]))
		{
			if (!game->cub_file[i][j + 3])
				return (i);
			j++;
		}
	i++;
	}
	return (ERROR);
}

int	ft_is_empty_line(char *str)
{
	if (str[0] == 13 && str[1] == '\n')
		return (SUCCESS);
	return (FAILURE);
}


