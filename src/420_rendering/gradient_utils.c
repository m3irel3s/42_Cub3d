/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:44:06 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 10:59:10 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	ft_ceiling_gradient_step(int y, int start_y);
static int	ft_floor_gradient_step(int y);

/**
 * @brief Compute the number of times to darken the color of a gradient.
 * @param y The y-coordinate of the gradient.
 * @param start_y The y-coordinate of the start of the gradient.
 * @param is_ceiling Whether the gradient is for the ceiling (1) or
 * the floor (0).
 * @return The number of times to darken the color.
 *
 * This function computes the number of times to darken the color of a gradient
 * based on the y-coordinate of the gradient and the y-coordinate of the start of
 * the gradient. The number of times to darken the color is computed such that
 * the color is darker closer to the start of the gradient and lighter closer to
 * the end of the gradient.
 */
int	ft_gradient_step(int y, int start_y, int is_ceiling)
{
	if (is_ceiling)
		return (ft_ceiling_gradient_step(y, start_y));
	return (ft_floor_gradient_step(y));
}

/**
 * @brief Compute the number of times to darken the color of
 * the ceiling gradient.
 * @param y The y-coordinate of the gradient.
 * @param start_y The y-coordinate of the start of the ceiling gradient.
 * @return The number of times to darken the color.
 *
 * This function computes the number of times to darken the color of the ceiling
 * gradient based on the y-coordinate of the gradient and the y-coordinate of the
 * start of the ceiling gradient. The number of times to darken the color is
 * computed such that the color is darker closer to the start of the gradient
 * and lighter closer to the end of the gradient. If the y-coordinate is above
 * the start of the ceiling gradient, the function returns
 * MAX_DARKENING_STEPS.
 */
static int	ft_ceiling_gradient_step(int y, int start_y)
{
	int	diff;
	int	steps;

	if (y < start_y)
	{
		diff = start_y - y;
		steps = MAX_DARKENING_STEPS - ((diff + 9) / 10);
		if (steps < 0)
			steps = 0;
		return (steps);
	}
	return (MAX_DARKENING_STEPS);
}

/**
 * @brief Compute the number of times to darken the color of the floor gradient.
 * @param y The y-coordinate of the gradient.
 * @return The number of times to darken the color.
 *
 * This function computes the number of times to darken the color of the floor
 * gradient based on the y-coordinate of the gradient. The number of times to
 * darken the color is computed such that the color is darker closer to the end
 * of the gradient and lighter closer to the start of the gradient. If the
 * y-coordinate is below the end of the floor gradient, the function returns 0.
 */
static int	ft_floor_gradient_step(int y)
{
	int	diff;
	int	steps;

	if (y < FLOOR_GRADIENT_END)
	{
		diff = FLOOR_GRADIENT_END - y;
		steps = (diff + 9) / 10;
		if (steps > MAX_DARKENING_STEPS)
			steps = MAX_DARKENING_STEPS;
		return (steps);
	}
	return (0);
}
