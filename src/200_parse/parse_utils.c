/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:42:48 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/11 17:01:57 by jmeirele         ###   ########.fr       */
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

int	ft_get_grid_start_index(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->cub_file[i])
	{
		j = 0;
		while (game->cub_file[i][j] && ft_strchr(" ", game->cub_file[i][j]))
			j++;
		while (game->cub_file[i][j] && ft_strchr("10NSWE ", game->cub_file[i][j]))
		{
			if (game->cub_file[i][j + 1] == '\0' || game->cub_file[i][j + 1] == '\r')
				return (i);
			j++;
		}
		i++;
	}
	return (ERROR);
}


int	ft_get_grid_last_index(t_game *game)
{
	int	i;

	i = game->map->grid_start_index;
	while (game->cub_file[i])
		i++;
	return (i);
}

int	ft_is_empty_line(char *str)
{
	if (!str)
		return (SUCCESS);
	return (FAILURE);
}

int	ft_count_occurs(char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!str)
		return (ERROR);
	while (str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	return (counter);
}



