/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:54:47 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/01 16:27:33 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

//============================================================================//
//                             INITIALIZATION                                 //
//============================================================================//
/* init.c */
t_game		*ft_init_structs(void);

//============================================================================//
//                                 PARSING                                    //
//============================================================================//
/* parse.c */
void		ft_parse(t_game *game, char **argv);

/* map_name.c */
void		ft_parse_map_name(t_game *game);

/* cub_file.c */
void		ft_set_cub_file(t_game *game);

/* map_grid.c */

/* map_elements.c */
void		ft_set_map_elements(t_game *game);

/* parse_utils.c */
int			ft_check_valid_map_chars(char c);
int			ft_set_grid_start_index(t_game *game);

//============================================================================//
//                                  UTILS                                     //
//============================================================================//
/* utils.c */
int			ft_is_space(char c);

/* safe_utils.c */
void		*ft_safe_malloc(size_t size);

//============================================================================//
//                                CLEANUP                                     //
//============================================================================//
/* free.c */
void		ft_cleanup(t_game *game, char *msg, int fd);

/* free_utils.c */
void		ft_free(void *ptr);
void		ft_free_arr(char **arr);

#endif
