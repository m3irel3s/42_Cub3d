/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:04:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

/**
 * Clamps a given color value between 0 and 255.
 *
 * @param value The value to be clamped.
 *
 * @return The clamped value.
 */
static int	ft_clamp_color(int value)
{
	if (value < 0)
		return (0);
	if (value > 255)
		return (255);
	return (value);
}

/**
 * Darkens a given RGB color by a given factor, repeated a specified number
 * of times.
 *
 * @param color The color to be darkened.
 * @param factor The factor to darken by.
 * @param times The number of times to darken.
 *
 * @return The darkened color.
 */
int	ft_darken_rgb_color3(int color, double factor, int times)
{
	int	r;
	int	g;
	int	b;
	int	j;

	if (factor < 0 || factor > 1)
		return (color);
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	j = 0;
	while (j < times)
	{
		r *= factor;
		g *= factor;
		b *= factor;
		j++;
	}
	return ((r << 16) | (g << 8) | b);
}

/**
 * Converts a given RGB color to its hexadecimal representation.
 *
 * @param r The red component of the color.
 * @param g The green component of the color.
 * @param b The blue component of the color.
 *
 * @return The hexadecimal representation of the color.
 */
int	ft_rgb_to_hex(int r, int g, int b)
{
	return ((ft_clamp_color(r) << 16)
		| (ft_clamp_color(g) << 8)
		| ft_clamp_color(b));
}
