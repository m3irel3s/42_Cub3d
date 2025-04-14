/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:04:54 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/14 18:58:03 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_parse_color(t_game *game, t_rgb *set_color ,char *color);
static int	ft_parse_rgb(t_game *game, char *str, char **res);
static int	ft_check_number(char *str);

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

static void ft_parse_color(t_game *game, t_rgb *set_color ,char *color)
{
	char	**res;
	int		red;
	int		green;
	int		blue;

	res = ft_split(color, ',');
	if (!res)
		ft_cleanup(game, ERROR_SPLITTING_COLOR, 2);
	// printf("\n");
	// for (int i = 0; res[i]; i++)
	// 	printf("res[%d] :%s:\n", i, res[i]);
	// printf("\n");
	// printf("array_len -> %d\n", ft_array_len(res));
	if (ft_array_len(res) != 3 || ft_count_occurs(color, ',') != 2)
	{
		ft_free_arr(res);
		ft_cleanup(game, FOUND_INVALID_COLOR, 2);
	}
	// printf("\n");
	// for (int i = 0; res[i]; i++)
	// 	printf("res[%d] :%s:\n", i, res[i]);
	// printf("\n");
	// printf("array_len -> %d\n", ft_array_len(res));
	red = ft_parse_rgb(game, res[0], res);
	green = ft_parse_rgb(game, res[1], res);
	blue = ft_parse_rgb(game, res[2], res);
	// printf("red -> %d\n", red);
	// printf("green -> %d\n", green);
	// printf("blue -> %d\n", blue);
	set_color->r = red;
	set_color->g = green;
	set_color->b = blue;
	ft_free_arr(res);
}

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
