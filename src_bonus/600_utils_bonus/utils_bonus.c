/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:13:47 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/23 22:26:56 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Checks if a character is a whitespace.
 *
 * This function takes a single character as input and checks if it is a
 * whitespace. If the character is a whitespace, the function returns 1;
 * otherwise, it returns 0.
 *
 * @param c The character to check.
 * @return 1 if the character is a whitespace, 0 otherwise.
 */
int	ft_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

/**
 * @brief Counts the number of strings in a NULL-terminated array of strings.
 *
 * This function takes a NULL-terminated array of strings as input and
 * returns the number of strings in the array.
 *
 * @param arr The array of strings to count.
 * @return The number of strings in the array.
 */
int	ft_array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/**
 * @brief Returns the current time in milliseconds.
 *
 * This function uses the gettimeofday function to get the current time in
 * seconds and microseconds. It then multiplies the seconds by 1000 and adds
 * the microseconds divided by 1000 to return the current time in milliseconds.
 *
 * @return The current time in milliseconds.
 */
int	ft_get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
