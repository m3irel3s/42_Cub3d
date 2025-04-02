/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_header_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:35:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/02 15:19:01 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map_tags(t_game *game, t_headers *headers)
{
	int		i;
	t_tag	tag;
	int		found_tags[6] = {0};

	i = 0;
	while (i < 6)
	{
		tag = ft_compare_tags(headers[i].tag_name);
		headers[i].tag = tag;
		if (tag == UNKNOWN)
			ft_cleanup(game, INVALID_TAG_FOUND, 2);
		if (found_tags[tag] > 0)
			ft_cleanup(game, FOUND_DUPLICATE_TAG, 2);
		found_tags[tag]++;
		i++;
	}
}

t_tag	ft_compare_tags(char *str)
{
	if (ft_strcmp(str, "SO") == SUCCESS)
		return (SO_TAG);
	else if (ft_strcmp(str, "NO") == SUCCESS)
		return (NO_TAG);
	else if (ft_strcmp(str, "EA") == SUCCESS)
		return (EA_TAG);
	else if (ft_strcmp(str, "WE") == SUCCESS)
		return (WE_TAG);
	else if (ft_strcmp(str, "F") == SUCCESS)
		return (F_TAG);
	else if (ft_strcmp(str, "C") == SUCCESS)
		return (C_TAG);
	return (UNKNOWN);
}

int	ft_count_headers(t_game *game)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (i < game->map->grid_start_index)
	{
		if (ft_is_empty_line(game->cub_file[i]) == FAILURE)
			counter++;
		i++;
	}
	return counter;
}