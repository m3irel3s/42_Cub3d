/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:04:54 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/04 16:12:36 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_parse_color(t_game *game, char *color);

void	ft_check_and_set_map_colors(t_game *game, t_headers *headers)
{
	int	i;
	(void)game;
	i = -1;
	while (++i < 6)
	{
		if (headers[i].tag == F_TAG)
		{
			printf("HEllo from F tag\n");
			ft_parse_color(game, headers[i].value);
		}
		else if (headers[i].tag == C_TAG)
		{
			printf("HEllo from C tag\n");
		}
	}
	return ;
}

static char	**ft_parse_color(t_game *game, char *color)
{
	char	**res;
	int		red;
	int		green;
	int		blue;

	res = ft_split(color, ',');
	printf("\n");
	for (int i = 0; res[i]; i++)
	{
		printf("res[%d] %s\n", i, res[i]);
	}
	printf("\n");
	if (!res[0] || !res[1] || !res[2] || res[3] != NULL)
		ft_cleanup(game, FOUND_INVALID_COLOR, 2);
	red = ft_atoi(res[0]);
	green = ft_atoi(res[1]);
	blue = ft_atoi(res[2]);
	printf("red -> %d\n", red);
	printf("green -> %d\n", green);
	printf("blue -> %d\n", blue);
	if (red > 255 || green > 255 || blue > 255
	|| red < 0 || green < 0 || blue < 0)
		ft_cleanup(game, COLOR_OUT_OF_LIMITS, 2);
	
	return (res);
}



