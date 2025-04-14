/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:11:35 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/14 19:03:48 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_headers	*ft_headers(t_game *game);
static void			ft_parse_header_line(t_headers *headers, char *line);

void	ft_parse_headers(t_game *game)
{
	t_headers	*headers;

	game->headers = ft_headers(game);
	headers = game->headers;
	ft_check_and_set_headers_tags(game, headers);
	ft_check_headers_values(game, headers);
	ft_check_and_set_headers_colors(game, headers);
	ft_check_headers_textures(game, headers);
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
	if (headers_size != 6)
		ft_cleanup(game, FOUND_INVALID_N_HEADERS, 2);
	headers = ft_safe_malloc(sizeof(t_headers) * (headers_size + 1));
	while (i < game->map->grid_start_index)
	{
		if (ft_is_empty_line(game->cub_file[i]) == SUCCESS)
		{
			i++;
			continue ;
		}
		ft_parse_header_line(&headers[k], game->cub_file[i]);
		k++;
		i++;
	}
	headers[k].tag_name = NULL;
	headers[k].value = NULL;
	return (headers);
}

static void	ft_parse_header_line(t_headers *headers, char *line)
{
	int	j;
	int	z;

	j = 0;
	while (line[j] && !ft_is_space(line[j]))
		j++;
	headers->tag_name = ft_substr(line, 0, j);
	while (line[j] == ' ')
		j++;
	z = j;
	while (line[j])
		j++;
	headers->value = ft_substr(line, z, j - z);
}
