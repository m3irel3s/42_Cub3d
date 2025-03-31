/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000_intro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:37:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/31 15:25:02 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

static void	ft_display_infos(void);
static void	ft_print_banner_line(char *banner[]);

/**
 * @brief Display the startup banner and information in the terminal.
 */
void	ft_display_startup_banner(void)
{
	char	*banner[17];

	banner[0] = BBLU " /******************************************/ "RS;
	banner[1] = BMAG " /                                          / "RS;
	banner[2] = BGRN " /       ███╗   ███╗██╗███╗   ██╗██╗        / "RS;
	banner[3] = HYEL " /       ████╗ ████║██║████╗  ██║██║        / "RS;
	banner[4] = HCYN " /       ██╔████╔██║██║██╔██╗ ██║██║        / "RS;
	banner[5] = HRED " /       ██║╚██╔╝██║██║██║╚██╗██║██║        / "RS;
	banner[6] = HMAG " /       ██║ ╚═╝ ██║██║██║ ╚████║██║        / "RS;
	banner[7] = BYEL " /                                          / "RS;
	banner[8] = HMAG " /   ███████╗██╗  ██╗███████╗██╗    ██╗     / "RS;
	banner[9] = HRED " /   ██╔════╝██║  ██║██╔════╝██║    ██║     / "RS;
	banner[10] = HCYN " /   ███████╗███████║█████╗  ██║    ██║     / "RS;
	banner[11] = HYEL " /   ╚════██║██╔══██║██╔══╝  ██║    ██║     / "RS;
	banner[12] = BGRN " /   ███████║██║  ██║███████╗██████╗██████╗ / "RS;
	banner[13] = BMAG " /   ╚══════╝╚═╝  ╚═╝╚══════╝╚═════╝╚═════╝ / "RS;
	banner[14] = HYEL " /                                          / "RS;
	banner[15] = BBLU " /******************************************/ "RS;
	banner[16] = NULL;
	ft_print_banner_line(banner);
	ft_printf(1, "\n\n%s[ Welcome to Cube3D! ]%s\n", BGRN, RS);
	ft_printf(1, "%sA 3D game implementation using raycasting for 42 School.%s\n\n",
		HYEL, RS);
	ft_display_infos();
}

/**
 * @brief Helper function to print each line of the banner.
 */
static void	ft_print_banner_line(char *banner[])
{
	int	i;

	i = 0;
	while (banner[i] != NULL)
	{
		ft_printf(1, "%s\n", banner[i]);
		i++;
	}
}

/**
 * @brief Displays information about the Cube3D implementation.
 *
 * This function displays a banner with information about the
 * Cube3D game, including features and examples.
 *
 * @return void
 */
static void	ft_display_infos(void)
{
	ft_printf(1, "\n%s+-----------------------------+%s\n", BYEL, RS);
	ft_printf(1, "%s|        CUBE3D INFO          |%s\n", BMAG, RS);
	ft_printf(1, "%s+-----------------------------+%s\n\n", BYEL, RS);
	ft_printf(1, "%sFeatures:%s\n", BBLU, RS);
	ft_printf(1, " %s- Raycasting engine:%s for rendering 3D environments.\n",
		HGRN, RS);
	ft_printf(1, " - %sMap parsing:%s from .cub files.\n", HGRN, RS);
	ft_printf(1, " - %sPlayer movement:%s W, A, S, D keys.\n", HGRN, RS);
	ft_printf(1, " - %sRotation:%s left and right arrow keys.\n\n", HGRN, RS);
	ft_printf(1, "%sExamples:%s\n", BBLU, RS);
	ft_printf(1, " %s- Run the game with a .cub map file:%s ./cube3d map.cub\n", HYEL, RS);
	ft_printf(1, " - %sUse W, A, S, D keys to move and arrow keys to rotate.%s\n\n", HYEL, RS);
	ft_printf(1, "%sType 'exit' to quit the game.%s\n\n", HCYN, RS);
}

/**
 * @brief Prints the authors of the program.
 */
int	ft_authors(void)
{
	char	*authors[14];
	int		i;

	authors[0] = BYEL "\n+-------------------------------------------+"RS;
	authors[1] = BMAG "|                AUTHORS                    |"RS;
	authors[2] = BYEL "+-------------------------------------------+"RS;
	authors[3] = BGRN "| Cube3D - 42 School Project             |"RS;
	authors[4] = BYEL "|                                           |"RS;
	authors[5] = HCYN "| Created by:                               |"RS;
	authors[6] = BMAG "| > Miguel Meireles                         |"RS;
	authors[7] = HRED "| <jmeirele@student.42porto.com>            |"RS;
	authors[8] = BMAG "| > Melanie Reis                            |"RS;
	authors[9] = HRED "| <meferraz@student.42porto.com>            |"RS;
	authors[10] = BGRN "|                                           |"RS;
	authors[11] = HYEL "| April 2025                                |"RS;
	authors[12] = BYEL "+-------------------------------------------+\n"RS;
	authors[13] = NULL;
	i = 0;
	while (authors[i] != NULL)
	{
		ft_printf(1, "%s\n", authors[i]);
		i++;
	}
	return (0);
}
