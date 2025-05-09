/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:53:20 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/23 18:35:59 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

//============================================================================//
// ⬤  GENERAL CONSTANTS                                                      //
//============================================================================//

# define SUCCESS 0
# define FAILURE 1
# define TRUE 0
# define FALSE 1
# define ERROR -1

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define FOV 0.90

//============================================================================//
// ⬤  PLATFORM KEYS MACROS                                                   //
//============================================================================//

# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_A 0
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# elif __linux__
#  define KEY_ESC XK_Escape
#  define KEY_W XK_w
#  define KEY_S XK_s
#  define KEY_A XK_a
#  define KEY_D XK_d
#  define KEY_LEFT XK_Left
#  define KEY_RIGHT XK_Right
# endif

//============================================================================//
// ⬤  ERROR MESSAGES                                                         //
//============================================================================//

/* PARSING ERRORS */
# define INVALID_ARGUMENTS "Error\nInvalid arguments given\n"
# define INVALID_FILE_NAME "Error\nInvalid file name given\n"
# define INVALID_MAP_GRID "Error\nCouldn't find the map grid\n"
# define INVALID_ELEMENT_FOUND "Error\nFound an element that was not needed\n"
# define INVALID_TAG_FOUND "Error\nFound an invalid tag\n"
# define FOUND_DUPLICATE_TAG "Error\nFound a duplicated tag\n"
# define FOUND_INVALID_N_HEADERS "Error\nFound invalid number of headers\n"
# define FOUND_INVALID_VALUE "Error\nFound invalid value for tag\n"
# define ERROR_SPLITTING_COLOR "Error\nError splitting the color\n"
# define FOUND_INVALID_COLOR "Error\nColor wasn't given like the subject \
required\n"
# define COLOR_OUT_OF_LIMITS "Error\nColor number was out of limits\n"
# define INVALID_COLOR_NUMBER "Error\nInvalid color number\n"
# define FOUND_TAB_IN_MAP "Error\nFound a tab in map grid\n"
# define FOUND_INVALID_CHAR_MAP "Error\nFound an invalid char in map\n"
# define FOUND_EMPTY_LINE_INSI_MAP "Error\nFound empty line inside map\n"
# define COULDNT_FIND_MAP_START "Error\nCouldn't find the map start\n"
# define INVALID_MAP_SIZE "Error\nInvalid map size\n"
# define FOUND_MORE_PLAYERS "Error\nFound more than 1 player\n"
# define PLAYER_NOT_FOUND "Error\nPlayer not found\n"
# define FOUND_SPACE_INSI_MAP "Error\nFound a space inside map\n"
# define FOUND_UNCLOSED_MAP "Error\nPlayer is not surrounded by walls\n"

/* Texture Errors */
# define ERR_TEXTURE "Error\nLoading texture"
# define ERR_TEXTURE_ADDR "Error\nGetting texture address"

/* Safe Functions */
# define INVALID_FD_OPEN "Error\nError openning the file descriptor\n"
# define MALLOC_FAILED "Error\nError allocation memory\n"

/* Quit Game */
# define QUIT_GAME_MSG "Thank you for playing!\nExiting game...\n"

/* GAME ERRORS */
# define STRUCT_INIT_FAILED "Error\nFailed the initialization of structs\n"
# define MLX_INIT_FAIL "Error\nFailed to allocated memory for MLX\n"

//============================================================================//
// ⬤  RENDERING HELPERS                                                      //
//============================================================================//

# define MAX_BRIGHTNESS 0
# define MAX_DARKENING_STEPS 18
# define DARKEN_FACTOR 0.9

#endif
