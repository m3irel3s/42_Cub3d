/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:24:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/22 13:28:27 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	ft_get_cub_file_size(t_game *game);
static void	ft_trim_cub_file(t_game *game);
static void	ft_set_grid_indexs(t_game *game);

void	ft_set_cub_file(t_game *game)
{
	int		j;
	int		fd;
	char	*line;

	j = 0;
	fd = ft_valid_fd(game, game->file_path);
	game->cub_file_size = ft_get_cub_file_size(game);
	game->cub_file = malloc(sizeof(char *) * (game->cub_file_size + 1));
	line = get_next_line(fd);
	while (line)
	{
		game->cub_file[j++] = ft_strdup(line);
		ft_free(line);
		line = get_next_line(fd);
	}
	game->cub_file[j] = NULL;
	close(fd);
	ft_set_grid_indexs(game);
	ft_trim_cub_file(game);
}

static void	ft_set_grid_indexs(t_game *game)
{
	game->map->grid_start_index = ft_get_grid_start_index(game);
	if (game->map->grid_start_index == ERROR)
		ft_cleanup(game, COULDNT_FIND_MAP_START, 2);
	game->map->grid_last_index = ft_get_grid_last_index(game);
	printf("start index -> %d\n", game->map->grid_start_index);
	printf("last index -> %d\n", game->map->grid_last_index);
	if ((game->map->grid_start_index + 3) > game->map->grid_last_index)
		ft_cleanup(game, INVALID_MAP_SIZE, 2);
	if (game->map->grid_start_index < 6)
		ft_cleanup(game, INVALID_MAP_GRID, 2);
}

static int	ft_get_cub_file_size(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(game->file_path, O_RDONLY);
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
	while (i < game->map->grid_start_index)
	{
		temp = ft_strtrim(game->cub_file[i], "\t\r\n ");
		ft_free(game->cub_file[i]);
		game->cub_file[i] = temp;
		i++;
	}
	while (game->cub_file[i])
	{
		temp = ft_strtrim(game->cub_file[i], "\r\n");
		ft_free(game->cub_file[i]);
		game->cub_file[i] = temp;
		i++;
	}
}
