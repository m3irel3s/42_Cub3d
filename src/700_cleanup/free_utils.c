/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:38:34 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/22 11:05:27 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
