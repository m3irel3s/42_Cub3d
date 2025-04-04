/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:53:20 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/04 20:30:13 by jmeirele         ###   ########.fr       */
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

//============================================================================//
//                              ERROR MESSAGES                                //
//============================================================================//

# define INVALID_MAP_NAME "Error\nInvalid map name given\n"
# define INVALID_MAP_GRID "Error\nCouldn't find the map grid\n"
# define INVALID_ELEMENT_FOUND "Error\nFound an element that was not needed\n"
# define INVALID_TAG_FOUND "Error\nFound an invalid tag\n"
# define FOUND_DUPLICATE_TAG "Error\nFound a duplicated tag\n"
# define FOUND_INVALID_N_HEADERS "Error\nFound invalid number of headers\n"
# define FOUND_INVALID_VALUE "Error\nFound invalid value for tag\n"
# define FOUND_INVALID_COLOR "Error\nColor wasn't given like the subject required\n"
# define COLOR_OUT_OF_LIMITS "Error\nColor number was out of limits\n"
# define INVALID_COLOR_NUMBER "Error\nInvalid color number\n"


#endif
