/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:38:34 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/10 22:32:06 by meferraz         ###   ########.fr       */
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
