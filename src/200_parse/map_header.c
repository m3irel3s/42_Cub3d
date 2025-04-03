/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:11:35 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/03 13:46:22 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check for duplicates
// iterate till 11111 (check if all elements are given)
// static t_ele	ft_check_inicials(char *str);

static t_headers	*ft_headers(t_game *game, t_headers *headers);

void	ft_parse_map_headers(t_game *game)
{
	t_headers	*headers;
	int			headers_size;

	headers_size = ft_count_headers(game);
	printf("header size -> %d\n", headers_size);
	if (headers_size != 6)
		ft_cleanup(game, FOUND_INVALID_N_HEADERS, 2);
	headers = ft_safe_malloc(sizeof(t_headers) * (headers_size + 1));
	ft_headers(game, headers);
	ft_check_map_tags(game, headers);
	
	// go for each tag, if it is texture do ...
	// if it is color do ...
	for (int i = 0; i < headers_size; i++)
	{
		printf("tag > :%s:\n", headers[i].tag_name);
		printf("value > :%s:\n", headers[i].value);
		// for (int j = 0; headers[i].value[j]; j++)
		// {
			// printf("%d -> %c\n", headers[i].value[j], headers[i].value[j]);
		// }
		
	}
	ft_check_map_values(game, headers);
	return ;
}

static t_headers	*ft_headers(t_game *game, t_headers *headers)
{
	int			i;
	int			j;
	int			z;
	int			k;

	i = 0;
	k = 0;
	while (i < game->map->grid_start_index)
	{
		if (ft_is_empty_line(game->cub_file[i]) == SUCCESS)
		{
			i++;
			continue;
		}
		j = 0;
		while (game->cub_file[i][j] && !ft_is_space(game->cub_file[i][j]))
			j++;
		headers[k].tag_name = ft_substr(game->cub_file[i], 0, j);
		while (ft_is_space(game->cub_file[i][j]))
			j++;
		z = j;
		while (game->cub_file[i][j] != 13 && game->cub_file[i][j])
			j++;
		if (j == z)
			headers[k].value = NULL;
		else
			headers[k].value = ft_substr(game->cub_file[i], z, j - z);
		k++;
		i++;
	}
	headers[k].tag_name = NULL;
	headers[k].value = NULL;
	return (headers);
}

