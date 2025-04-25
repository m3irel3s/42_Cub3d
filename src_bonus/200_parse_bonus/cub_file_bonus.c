/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:24:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/23 15:58:50 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	ft_get_cub_file_size(t_game *game);
static void	ft_trim_cub_file(t_game *game);
static void	ft_set_grid_indexs(t_game *game);

/**
 * @brief Reads the .cub file, stores its content into the cub_file array,
 *        and sets grid indices for the map. Trims unnecessary whitespace
 *        from each line of the file.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 *
 * This function opens the file specified by game->file_path, calculates the
 * number of lines in the file, allocates memory for game->cub_file, and
 * populates it with each line from the file. It then closes the file, sets
 * the start and end indices for the map grid, and trims whitespace from the
 * lines in the cub_file array.
 */
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

/**
 * @brief Calculates and sets the grid start and end indices from the cub file.
 *
 * This function sets the start and end indices of the map grid in the cub file
 * by calling ft_get_grid_start_index and ft_get_grid_last_index,
 * respectively. It also performs some error checking to ensure the map has a
 * valid size and is formatted correctly.
 */
static void	ft_set_grid_indexs(t_game *game)
{
	game->map->grid_start_index = ft_get_grid_start_index(game);
	if (game->map->grid_start_index == ERROR)
		ft_cleanup(game, COULDNT_FIND_MAP_START, 2, EXIT_FAILURE);
	game->map->grid_last_index = ft_get_grid_last_index(game);
	if ((game->map->grid_start_index + 3) > game->map->grid_last_index)
		ft_cleanup(game, INVALID_MAP_SIZE, 2, EXIT_FAILURE);
	if (game->map->grid_start_index < 6)
		ft_cleanup(game, INVALID_MAP_GRID, 2, EXIT_FAILURE);
}

/**
 * @brief Determines the number of lines in the .cub file.
 *
 * This function opens the file specified by game->file_path, reads each line
 * using get_next_line, counts the total number of lines, and then closes the
 * file. The result is stored as the cub_file_size in the game structure.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data, including the file path.
 *
 * @return The total number of lines in the .cub file.
 */
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

/**
 * @brief Trims unnecessary whitespace and newline characters from lines in
 *        the cub_file array.
 *
 * This function iterates over the cub_file array, trimming whitespace,
 * tabs, carriage returns, and newlines from each line up to the start of
 * the map grid using ft_strtrim. After the grid start index, it trims only
 * newline and carriage return characters. Each trimmed line replaces the
 * original line in the cub_file array.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data, including the cub_file array.
 */

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
