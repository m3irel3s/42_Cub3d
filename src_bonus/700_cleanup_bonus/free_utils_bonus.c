/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:38:34 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

/**
 * Frees a pointer if it is not NULL.
 *
 * This function checks if the given pointer is not NULL and frees the
 * allocated memory pointed to by the pointer. It is a safe wrapper around
 * the standard `free` function to ensure that only valid pointers are freed.
 *
 * @param ptr - the pointer to the memory to free
 */

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

/**
 * Frees a 2D array of strings.
 *
 * @param arr - the 2D array of strings to free
 */
void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		ft_free(arr[i++]);
	ft_free(arr);
}
