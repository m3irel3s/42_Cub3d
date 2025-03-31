/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000_intro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:37:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/31 15:45:09 by meferraz         ###   ########.fr       */
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

	banner[0] = BBLU "   ____________________________________________________________________   " RS;
	banner[1] = BCYN "  /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  " RS;
	banner[2] = BMAG " ||"+BGRN"      ___       __        _______  ___   __    _  ________  "+BMAG"||" RS;
	banner[3] = BMAG " ||"+BGRN"     / _ \\__ __/ /  ___ /  _/ _ \\/ _ | / /   | |/ / __/ /  "+BMAG"||" RS;
	banner[4] = BMAG " ||"+BGRN"    / , _/ // / _ \\/ -_)/ // // / __ |/ /__  |   / _/_/    "+BMAG"||" RS;
	banner[5] = BMAG " ||"+BGRN"   /_/|_|\\_,_/_.__/\\__/___/____/_/ |_/____/ /_/|_/___(_)   "+BMAG"||" RS;
	banner[6] = BCYN "  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  " RS;
	banner[7] = BBLU "   ____________________________________________________________________   " RS;
	banner[8] = HCYN "      _________    _______________    _________      ________________     " RS;
	banner[9] = HYEL "     /  ______/|  /_____________ /|  /  _____  /|   /  _____________/|    " RS;
	banner[10] = HYEL "    /  /_____|/ |___  _______  / /  /  /___/ / /   /  / _________ | /    " RS;
	banner[11] = HYEL "   /  ______/|  __/ / _____/ / /  /  _____/ / /   /  / /________/|/ /    " RS;
	banner[12] = HYEL "  /  /_____|/ / /  / /____ / / /  /  /____ / /   /  /____________|/ /     " RS;
	banner[13] = HYEL " /__________|/ /__/ /______|/ /  /________/ /   /__________________/       " RS;
	banner[14] = HRED " |__________|/ |__________|/   |________|/     |_________________|        " RS;
	banner[15] = BBLU " ________________________________________________________________________ " RS;
	banner[16] = NULL;
	ft_print_banner_line(banner);
	ft_printf(1, "\n\n%s[ Welcome to Cub3D! ]%s\n", BGRN, RS);
	ft_printf(1, "%sA 3D raycasting adventure - Navigate the maze and find your way out!%s\n\n",
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
