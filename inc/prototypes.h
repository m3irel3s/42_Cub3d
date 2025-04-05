/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:54:47 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/05 12:39:20 by meferraz         ###   ########.fr       */
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

/* parse_map_name.c */
void		ft_parse_map_name(t_game *game);

/* cub_file.c */
void		ft_set_cub_file(t_game *game);

/* map_colors.c */
void ft_check_and_set_headers_colors(t_game *game, t_headers *headers);

/* map_headers.c */
void		ft_parse_map_headers(t_game *game);

/* map_headers_2.c */
void		ft_check_and_set_map_tags(t_game *game, t_headers *headers);
void		ft_check_map_values(t_game *game, t_headers *headers);
t_tag		ft_compare_tags(char *str);
int			ft_count_headers(t_game *game);

/* parse_utils.c */
int			ft_check_valid_map_chars(char c);
int			ft_set_grid_start_index(t_game *game);
int			ft_is_empty_line(char *str);
int			ft_count_occurs(char *str, char c);

/* map_grid.c */

//============================================================================//
//                               RAYCASTING                                   //
//============================================================================//
/* raycasting.c */
void		ft_cast_rays(t_game *game);
/* init_raycasting.c */
void		ft_init_ray(t_game *game, int x, t_ray *ray);
/* dda_raycasting.c */
void		ft_perform_dda(t_game *game, t_ray *ray);
/* draw_raycasting.c */
void		ft_calc_wall(t_game *game, t_ray *ray);

//============================================================================//
//                                DRAWING                                     //
//============================================================================//
/* draw.c */
void		ft_draw_textured_wall(t_game *game, int x, t_ray *ray);
void		ft_mlx_pixel_put_to_image(t_game *game, int x, int y, int color);

//============================================================================//
//                              RENDERING                                     //
//============================================================================//
/* render.c */
int			ft_render_next_frame(t_game *game);

/* render_utils.c */
void		ft_set_floor_n_ceiling(t_game *game);

//============================================================================//
//                                EVENTS                                      //
//============================================================================//
/* events.c */
int			ft_handle_key(int key, t_game *game);
/* movements.c */
void		ft_move_forward(t_game *game, double move_speed);
void		ft_move_backward(t_game *game, double move_speed);
void		ft_move_left(t_game *game, double move_speed);
void		ft_move_right(t_game *game, double move_speed);
/* rotations.c */
void		ft_rotate_left(t_game *game, double rot_speed);
void		ft_rotate_right(t_game *game, double rot_speed);

//============================================================================//
//                              TEXTURES                                      //
//============================================================================//
/* textures.c */
void		ft_load_textures(t_game *game);

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
