/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:53:20 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/14 18:10:53 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define SUCCESS 0
# define FAILURE 1
# define TRUE 0
# define FALSE 1
# define ERROR -1

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define FOV 0.90

//============================================================================//
//                              ERROR MESSAGES                                //
//============================================================================//


/* PARSING ERRORS */
# define INVALID_ARGUMENTS "Error\nInvalid arguments given\n"
# define INVALID_MAP_NAME "Error\nInvalid map name given\n"
# define INVALID_MAP_GRID "Error\nCouldn't find the map grid\n"
# define INVALID_ELEMENT_FOUND "Error\nFound an element that was not needed\n"
# define INVALID_TAG_FOUND "Error\nFound an invalid tag\n"
# define FOUND_DUPLICATE_TAG "Error\nFound a duplicated tag\n"
# define FOUND_INVALID_N_HEADERS "Error\nFound invalid number of headers\n"
# define FOUND_INVALID_VALUE "Error\nFound invalid value for tag\n"
# define ERROR_SPLITTING_COLOR "Error\nError splitting the color\n"
# define FOUND_INVALID_COLOR "Error\nColor wasn't given like the subject required\n"
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
# define INVALID_FD_OPEN "Error\nError openning the file descriptor\n"

/* GAME ERRORS */
# define STRUCT_INIT_FAILED "Error\nFailed the initialization of structs\n"
# define MLX_INIT_FAIL "Error\nFailed to allocated memory for MLX\n"


#endif
