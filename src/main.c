/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:22 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/31 19:38:48 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	(void)argv;
	game = NULL;
	if (argc != 2)
		return (ft_putstr_fd("Invalid arguments given\n", 2), FAILURE);
	game = ft_init_structs();
	(void)game;
	return (SUCCESS);
}
