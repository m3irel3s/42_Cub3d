/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:38:34 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/01 11:43:19 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		ft_free(arr[i++]);
	ft_free(arr);
}