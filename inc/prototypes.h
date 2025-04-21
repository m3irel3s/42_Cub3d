/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:54:47 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/21 17:34:29 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

//============================================================================//
//                             ⬤  INITIALIZATION                             //
//============================================================================//

/* 100_init/init.c */
t_game	*ft_init_structs(void);

//============================================================================//
//                                 ⬤  PARSING                                //
//============================================================================//

/* 200_parse/parse.c */
void	ft_parse(t_game *game, char **argv);

/* 200_parse/file_path.c */
void	ft_parse_file_path(t_game *game);

/* 200_parse/cub_file.c */
void	ft_set_cub_file(t_game *game);

/* 200_parse/headers_colors.c */
void	ft_check_and_set_headers_colors(t_game *game, t_headers *headers);

/* 200_parse/headers_paths.c */
void	ft_check_headers_textures(t_game *game, t_headers *headers);

/* 200_parse/headers.c */
void	ft_parse_headers(t_game *game);

/* 200_parse/headers_2.c */
void	ft_check_and_set_headers_tags(t_game *game, t_headers *headers);
void	ft_check_headers_values(t_game *game, t_headers *headers);
t_tag	ft_compare_tags(char *str);
int		ft_count_headers(t_game *game);

/* 200_parse/parse_utils.c */
int		ft_check_valid_map_chars(char c);
int		ft_get_grid_start_index(t_game *game);
int		ft_get_grid_last_index(t_game *game);
int		ft_is_empty_line(char *str);
int		ft_count_occurs(char *str, char c);

/* 200_parse/map_grid.c */
void	ft_parse_map_grid(t_game *game);

/* 200_parse/map_utils.c */
void	ft_validate_map_chars(t_game *game);
void	ft_set_player_values(t_game *game);

/* 200_parse/map_closure.c */
void	ft_check_map_closure(t_game *game);

//============================================================================//
//                            ⬤  GAME INITIALIZATION                         //
//============================================================================//

/* 300_init_game/init_game.c */
void	ft_init_game(t_game *game);

/* 300_init_game/init_player.c */
void	ft_init_player(t_game *game);

//============================================================================//
//                              ⬤  RAYCASTING                                //
//============================================================================//

/* 300_raycasting/raycasting.c */
void	ft_cast_rays(t_game *game);

/* 300_raycasting/init_raycasting.c */
void	ft_init_ray(t_game *game, int x, t_ray *ray);

/* 300_raycasting/dda_raycasting.c */
void	ft_perform_dda(t_game *game, t_ray *ray);

/* 300_raycasting/draw_raycasting.c */
void	ft_calc_wall(t_game *game, t_ray *ray);

//============================================================================//
//                                ⬤  DRAWING                                 //
//============================================================================//

/* 400_draw/draw.c */
void	ft_draw_textured_wall(t_game *game, int x, t_ray *ray);
void	ft_mlx_pixel_put_to_image(t_game *game, int x, int y, int color);

//============================================================================//
//                              ⬤  RENDERING                                 //
//============================================================================//

/* 600_rendering/render.c */
int		ft_render_next_frame(t_game *game);
int		ft_darken_rgb_color3(int color, double factor, int times);

/* 600_rendering/render_utils.c */
void	ft_set_floor_n_ceiling(t_game *game);

//============================================================================//
//                               ⬤  EVENTS                                   //
//============================================================================//

/* 700_events/events.c */
int		ft_handle_key(int key, t_game *game);

/* 700_events/movements.c */
void	ft_move_forward(t_game *game, double move_speed);
void	ft_move_backward(t_game *game, double move_speed);
void	ft_move_left(t_game *game, double move_speed);
void	ft_move_right(t_game *game, double move_speed);

/* 700_events/rotations.c */
void	ft_rotate_left(t_game *game, double rot_speed);
void	ft_rotate_right(t_game *game, double rot_speed);

//============================================================================//
//                               ⬤  TEXTURES                                 //
//============================================================================//

/* 500_textures/textures.c */
void	ft_load_textures(t_game *game);

//============================================================================//
//                                 ⬤  UTILS                                  //
//============================================================================//

/* 800_utils/utils.c */
int		ft_is_space(char c);
int		ft_array_len(char **arr);

/* 800_utils/safe_utils.c */
void	*ft_safe_malloc(size_t size);
int		ft_valid_fd(t_game *game, char *path);

//============================================================================//
//                              ⬤  CLEANUP                                   //
//============================================================================//

/* 900_cleanup/free.c */
void	ft_cleanup(t_game *game, char *msg, int fd);

/* 900_cleanup/free_parse.c */
void	ft_free_parse(t_game *game);

/* 900_cleanup/free_utils.c */
void	ft_free(void *ptr);
void	ft_free_arr(char **arr);

/* 900_cleanup/quit_game.c */
int		ft_quit_game(t_game *game);

#endif
