/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:11:35 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/03 15:57:14 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check for duplicates
// iterate till 11111 (check if all elements are given)
// static t_ele	ft_check_inicials(char *str);

static t_headers	*ft_headers(t_game *game);
static void			ft_parse_header_line(t_headers *headers, char *line);

void	ft_parse_map_headers(t_game *game)
{
	t_headers	*headers;

	game->map->headers = ft_headers(game);
	headers = game->map->headers;
	ft_check_map_tags(game, headers);
	// ft_check_map_paths(game, headers);
	// ft_check_map_colors(game, headers);
	
	// go for each tag, if it is texture do ...
	// if it is color do ...

	for (int i = 0; i < 6; i++)
	{
		printf("tag > :%s:\n", headers[i].tag_name);
		printf("value > :%s:\n", headers[i].value);
		// for (int j = 0; headers[i].value[j]; j++)
		// {
		// 	printf("%d -> %c\n", headers[i].value[j], headers[i].value[j]);
		// }
		
	}
	ft_check_map_values(game, headers);
	return ;
}

static t_headers	*ft_headers(t_game *game)
{
	int			i;
	int			k;
	int			headers_size;
	t_headers	*headers;

	i = 0;
	k = 0;
	headers_size = ft_count_headers(game);
	printf("header size -> %d\n", headers_size);
	if (headers_size != 6)
		ft_cleanup(game, FOUND_INVALID_N_HEADERS, 2);
	headers = ft_safe_malloc(sizeof(t_headers) * (headers_size + 1));
	while (i < game->map->grid_start_index)
	{
		if (ft_is_empty_line(game->cub_file[i]) == SUCCESS)
		{
			i++;
			continue;
		}
		ft_parse_header_line(&headers[k], game->cub_file[i]);
		k++;
		i++;
	}
	headers[k].tag_name = NULL;
	headers[k].value = NULL;
	return headers;
}

static void	ft_parse_header_line(t_headers *headers, char *line)
{
	int j;
	int z;

	j = 0;
	while (line[j] && !ft_is_space(line[j]))
		j++;
	headers->tag_name = ft_substr(line, 0, j);
	while (ft_is_space(line[j]))
		j++;
	z = j;
	while (line[j])
		j++;
	headers->value = ft_substr(line, z, j - z);
}

