/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:24:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/01 17:19:58 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_cub_file_size(t_game *game);
static void	ft_trim_cub_file(t_game *game);

void	ft_set_cub_file(t_game *game)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	fd = open(game->map->map_path, O_RDONLY);
	i = ft_get_cub_file_size(game);
	game->cub_file = malloc(sizeof(char *) * i + 1);
	j = -1;
	while(++j < i)
	{
		line = get_next_line(fd);
		game->cub_file[j] = ft_strdup(line);
		ft_free(line);
	}
	game->cub_file[j] = NULL;
	close(fd);
	ft_trim_cub_file(game);
	return ;
}

static int	ft_get_cub_file_size(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(game->map->map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		ft_free(line);
		line = get_next_line(fd);
	}
	ft_free(line);
	close(fd);
	return (i);
}

static void	ft_trim_cub_file(t_game *game)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (game->cub_file[i])
	{
		temp = ft_strtrim(game->cub_file[i], " \t");
		ft_free(game->cub_file[i]);
		game->cub_file[i] = temp;
		i++;
	}
}
