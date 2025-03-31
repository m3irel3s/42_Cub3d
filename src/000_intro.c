/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000_intro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:37:43 by meferraz          #+#    #+#             */
/*   Updated: 2025/03/31 16:54:06 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_display_infos(void);
static void	ft_print_banner_line(char *banner[]);
static void	ft_authors(void);
static void	ft_print_color_line(int width, const char *left, const char *right, char fill);

/**
 * @brief Display the startup banner and information in the terminal.
 */
void	ft_display_startup_banner(void)
{
	char	*title[9];

	title[0] = BBLU "╔═════════════════════════════════════════════╗" RESET;
	title[1] = BBLU "║" BMAG "   ██████╗██╗   ██╗██████╗ ██████╗██████╗ " BBLU "   ║" RESET;
	title[2] = BBLU "║" BMAG "  ██╔════╝██║   ██║██╔══██╗╚════██║██╔══██╗" BBLU "  ║" RESET;
	title[3] = BBLU "║" BMAG "  ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║" BBLU "  ║" RESET;
	title[4] = BBLU "║" BMAG "  ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║" BBLU "  ║" RESET;
	title[5] = BBLU "║" BMAG "  ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝" BBLU "  ║" RESET;
	title[6] = BBLU "║" BMAG "   ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ " BBLU "  ║" RESET;
	title[7] = BBLU "╚═════════════════════════════════════════════╝" RESET;
	title[8] = NULL;

	ft_print_banner_line(title);
	ft_printf(1, "\n");
	ft_print_color_line(58, BBLU "║" RESET, BBLU "║" RESET, 32);
	ft_printf(1, BBLU "║" RESET HCYN "  ➤ " RESET BGRN "Welcome to " HYEL "Cub3D" BGRN "!"
		HCYN " %-37s " BBLU "║\n" RESET, " ");
	ft_printf(1, BBLU "║" RESET HCYN "  ➤ " RESET HYEL "Navigate " HMAG "3D mazes " HGRN
		"with raycasting technology!" HCYN "%-7s " BBLU "║\n" RESET, " ");
	ft_print_color_line(58, BBLU "║" RESET, BBLU "║" RESET, 32);
	ft_printf(1, "\n");
	ft_display_infos();
	ft_authors();
}

/**
 * @brief Helper function to print formatted lines with borders
*/
static void	ft_print_color_line(int width, const char *left, const char *right, char fill)
{
	ft_printf(1, "%s", left);
	while (width-- > 2)
		ft_printf(1, "%s", fill);
	ft_printf(1, "%s\n", right);
}

/**
 * @brief Helper function to print a banner line with a given format
 */
static void	ft_print_banner_line(char *banner[])
{
	int	i;

	i = 0;
	while (banner[i])
	{
		ft_printf(1, "%s\n", banner[i]);
		i++;
	}
}

/**
 * @brief Displays information about the Cube3D implementation
 */
static void	ft_display_infos(void)
{
	ft_print_color_line(58, BBLU "╔" RESET, BBLU "╗" RESET, 61);
	ft_printf(1, BBLU "║" RESET BMAG "   CUB3D FEATURES & CONTROLS"
		HCYN " %28s " BBLU "║\n" RESET, " ");
	ft_print_color_line(58, BBLU "╠" RESET, BBLU "╣" RESET, 45);

	ft_printf(1, BBLU "║" RESET HGRN "  • " RESET "Raycasting Engine:"
		HYEL " %-36s " BBLU "║\n" RESET, "Advanced 3D rendering");
	ft_printf(1, BBLU "║" RESET HGRN "  • " RESET "Map Parsing:"
		HYEL " %-42s " BBLU "║\n" RESET, ".cub file format support");
	ft_printf(1, BBLU "║" RESET HGRN "  • " RESET "Movement:"
		HYEL " %-44s " BBLU "║\n" RESET, "W/A/S/D keys");
	ft_printf(1, BBLU "║" RESET HGRN "  • " RESET "Rotation:"
		HYEL " %-43s " BBLU "║\n" RESET, "←/→ arrow keys");
	ft_printf(1, BBLU "║" RESET HGRN "  • " RESET "Actions:"
		HYEL " %-43s " BBLU "║\n" RESET, "ESC to exit | M: Map toggle");

	ft_print_color_line(58, BBLU "╠" RESET, BBLU "╣" RESET, 45);
	ft_printf(1, BBLU "║" RESET HCYN "  ➤ " RESET "Usage: " HYEL "./cub3D "
		HMAG "<mapfile.cub>" HCYN "%-25s " BBLU "║\n" RESET, " ");
	ft_print_color_line(58, BBLU "╚" RESET, BBLU "╝" RESET, 61);
	ft_printf(1, "\n");
}

/**
 * @brief Prints the authors of the program in a stylized box
 */
void	ft_authors(void)
{
	char	*authors[14];

	authors[0] = BBLU "╔═════════════════════════════════════════════════════════╗" RESET;
	authors[1] = BBLU "║" BMAG "                     DEVELOPERS                      " BBLU "║" RESET;
	authors[2] = BBLU "╠═════════════════════════════════════════════════════════╣" RESET;
	authors[3] = BBLU "║" HCYN "  • " HYEL "Miguel Meireles" HRED " <jmeirele@student.42porto.com> " HCYN "%-7s " BBLU "║" RESET;
	authors[4] = BBLU "║" HCYN "  • " HYEL "Melanie Reis   " HRED " <meferraz@student.42porto.com> " HCYN "%-7s " BBLU "║" RESET;
	authors[5] = BBLU "╠═════════════════════════════════════════════════════════╣" RESET;
	authors[6] = BBLU "║" HMAG "        42 Porto " HCYN "•" HYEL " 2025 " HCYN "•"
		HMAG " 🦄 Magic Powered          " BBLU "║" RESET;
	authors[7] = BBLU "╚═════════════════════════════════════════════════════════╝" RESET;
	authors[8] = NULL;

	ft_printf(1, "\n");
	ft_print_banner_line(authors);
	ft_printf(1, "\n");
}
