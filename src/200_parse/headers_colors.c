/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:04:54 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/21 21:57:45 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_parse_color(t_game *game, t_rgb *set_color, char *color);
static int	ft_parse_rgb(t_game *game, char *str, char **res);
static int	ft_check_number(char *str);

/**
 * @brief Checks and sets the floor and ceiling colors from the headers.
 *
 * This function iterates through the headers to find the ones with F_TAG
 * and C_TAG, which represent the floor and ceiling colors, respectively.
 * It then parses the color values and sets them in the provided game structure.
 *
 * @param game The game struct containing the game state.
 * @param headers An array of headers to check for the color tags.
 */

void	ft_check_and_set_headers_colors(t_game *game, t_headers *headers)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (headers[i].tag == F_TAG)
			ft_parse_color(game, &game->floor_color, headers[i].value);
		else if (headers[i].tag == C_TAG)
			ft_parse_color(game, &game->ceiling_color, headers[i].value);
	}
	return ;
}

/**
 * @brief Parses a color from a string and sets the given t_rgb struct.
 *
 * Given a string in the format "R,G,B", this function parses the color and
 * sets the corresponding values of the given t_rgb struct.
 *
 * @param game The game struct containing the game state.
 * @param set_color The t_rgb struct to set.
 * @param color The string containing the color to parse.
 */
static void	ft_parse_color(t_game *game, t_rgb *set_color, char *color)
{
	char	**res;
	int		red;
	int		green;
	int		blue;

	res = ft_split(color, ',');
	if (!res)
		ft_cleanup(game, ERROR_SPLITTING_COLOR, 2);
	if (ft_array_len(res) != 3 || ft_count_occurs(color, ',') != 2)
	{
		ft_free_arr(res);
		ft_cleanup(game, FOUND_INVALID_COLOR, 2);
	}
	red = ft_parse_rgb(game, res[0], res);
	green = ft_parse_rgb(game, res[1], res);
	blue = ft_parse_rgb(game, res[2], res);
	set_color->r = red;
	set_color->g = green;
	set_color->b = blue;
	ft_free_arr(res);
}

/**
 * @brief Checks if the given RGB color is valid and returns its value.
 *
 * The given string is trimmed of its spaces and then checked if it is a valid
 * number. If it is not, an error message is printed and the game is exited.
 * If the number is out of the valid color range, an error message is printed
 * and the game is exited.
 *
 * @param game The game structure containing the game state.
 * @param str The string containing the RGB value to parse.
 * @param res The array of strings containing the RGB values.
 *
 * @return The parsed RGB value.
 */
static int	ft_parse_rgb(t_game *game, char *str, char **res)
{
	int		number;
	char	*temp;

	temp = NULL;
	temp = ft_strtrim(str, " ");
	if (ft_check_number(temp) != SUCCESS)
	{
		ft_free_arr(res);
		ft_free(temp);
		ft_cleanup(game, INVALID_COLOR_NUMBER, 2);
	}
	number = ft_atoi(temp);
	ft_free(temp);
	if (number < 0 || number > 255)
	{
		ft_free_arr(res);
		ft_cleanup(game, COLOR_OUT_OF_LIMITS, 2);
	}
	return (number);
}

/**
 * @brief Checks if the given string represents a valid non-negative integer.
 *
 * This function verifies if the input string is a valid representation of a
 * non-negative integer. The string can optionally have a leading '+' sign.
 * If the string contains only digit characters (with an optional leading '+'),
 * the function returns SUCCESS; otherwise, it returns ERROR.
 *
 * @param str The input string to be checked.
 * @return SUCCESS if the string is a valid non-negative integer, otherwise ERROR.
 */

static int	ft_check_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		return (ERROR);
	if (str[0] == '+')
	{
		i = 1;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (ERROR);
			i++;
		}
		return (SUCCESS);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
