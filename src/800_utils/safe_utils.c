/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:01:37 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/01 11:38:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_safe_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
	{
		ft_printf(2, "Err malloc failed\n");
		return (NULL);
	}
	return (p);
}
