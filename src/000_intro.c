/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000_intro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:37:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/31 16:15:06 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_display_infos(void);
static void	ft_print_banner_line(char *banner[]);
static void ft_authors(void);

/**
 * @brief Display the startup banner and information in the terminal.
 */
void	ft_display_startup_banner(void)
{
	char	*title[7];

	title[0] = BGRN " ██████╗ ██╗   ██╗██████╗ ██████╗ ██████╗ " RESET;
	title[1] = BGRN " ██║     ██║   ██║██╔══██╗╚════██╗██╔══██╗" RESET;
	title[2] = BGRN " ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║" RESET;
	title[3] = BGRN " ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║" RESET;
	title[4] = BGRN " ██████╔╝╚██████╔╝██████╔╝██████╔╝██████╔╝" RESET;
	title[5] = BGRN " ╚═════╝  ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ " RESET;
	title[6] = NULL;
	ft_print_banner_line(title);
	ft_printf(1, "\n\n%s[ Welcome to Cub3D! ]%s\n", BGRN, RESET);
	ft_printf(1, "%sA 3D raycasting adventure - Navigate the maze and find your way out!%s\n\n",
		HYEL, RESET);
	ft_display_infos();
	ft_authors();
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
	ft_printf(1, "\n%s+-----------------------------+%s\n", BYEL, RESET);
	ft_printf(1, "%s|        CUBE3D INFO          |%s\n", BMAG, RESET);
	ft_printf(1, "%s+-----------------------------+%s\n\n", BYEL, RESET);
	ft_printf(1, "%sFeatures:%s\n", BBLU, RESET);
	ft_printf(1, " %s- Raycasting engine:%s for rendering 3D environments.\n",
		HGRN, RESET);
	ft_printf(1, " - %sMap paRESETing:%s from .cub files.\n", HGRN, RESET);
	ft_printf(1, " - %sPlayer movement:%s W, A, S, D keys.\n", HGRN, RESET);
	ft_printf(1, " - %sRotation:%s left and right arrow keys.\n\n", HGRN, RESET);
	ft_printf(1, "%sExamples:%s\n", BBLU, RESET);
	ft_printf(1, " %s- Run the game with a .cub map file:%s ./cube3d map.cub\n", HYEL, RESET);
	ft_printf(1, " - %sUse W, A, S, D keys to move and arrow keys to rotate.%s\n\n", HYEL, RESET);
	ft_printf(1, "%sType 'exit' to quit the game.%s\n\n", HCYN, RESET);
}

/**
 * @brief Prints the authors of the program.
 */
void	ft_authors(void)
{
	char	*authors[14];
	int		i;

	authors[0] = BYEL "\n+-------------------------------------------+"RESET;
	authors[1] = BMAG "|                authors                    |"RESET;
	authors[2] = BYEL "+-------------------------------------------+"RESET;
	authors[3] = BGRN "| Cube3D - 42 School Project             |"RESET;
	authors[4] = BYEL "|                                           |"RESET;
	authors[5] = HCYN "| Created by:                               |"RESET;
	authors[6] = BMAG "| > Miguel Meireles                         |"RESET;
	authors[7] = HRED "| <jmeirele@student.42porto.com>            |"RESET;
	authors[8] = BMAG "| > Melanie Reis                            |"RESET;
	authors[9] = HRED "| <meferraz@student.42porto.com>            |"RESET;
	authors[10] = BGRN "|                                           |"RESET;
	authors[11] = HYEL "| April 2025                                |"RESET;
	authors[12] = BYEL "+-------------------------------------------+\n"RESET;
	authors[13] = NULL;
	i = 0;
	while (authors[i] != NULL)
	{
		ft_printf(1, "%s\n", authors[i]);
		i++;
	}
}
