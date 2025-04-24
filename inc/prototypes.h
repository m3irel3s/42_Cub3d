/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:54:47 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/24 16:58:13 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

//============================================================================//
// ⬤  100_INIT: Project Core Initialization                                   //
//============================================================================//

/* init.c */
t_game		*ft_init_structs(void);

//============================================================================//
// ⬤  200_PARSE: Parsing .cub file, headers, and map                         //
//============================================================================//

/* parse.c */
void		ft_parse(t_game *game, char **argv);

/* file_path.c */
void		ft_parse_file_path(t_game *game);

/* cub_file.c */
void		ft_set_cub_file(t_game *game);

/* headers.c */
void		ft_parse_headers(t_game *game);

/* headers_2.c */
void		ft_check_and_set_headers_tags(t_game *game, t_headers *headers);
void		ft_check_headers_values(t_game *game, t_headers *headers);
t_tag		ft_compare_tags(char *str);
int			ft_count_headers(t_game *game);

/* headers_colors.c */
void		ft_check_and_set_headers_colors(t_game *game, t_headers *headers);

/* headers_paths.c */
void		ft_check_headers_textures(t_game *game, t_headers *headers);

/* parse_utils.c */
int			ft_check_valid_map_chars(char c);
int			ft_get_grid_start_index(t_game *game);
int			ft_get_grid_last_index(t_game *game);
int			ft_is_empty_line(char *str);
int			ft_count_occurs(char *str, char c);

/* map_grid.c */
void		ft_parse_map_grid(t_game *game);

/* map_utils.c */
void		ft_validate_map_chars(t_game *game);
void		ft_set_player_values(t_game *game);

/* map_closure.c */
void		ft_check_map_closure(t_game *game);

//============================================================================//
// ⬤  300_INIT_GAME: Setup Game Components and Player                        //
//============================================================================//

/* init_game.c */
void		ft_init_game(t_game *game);

/* init_player.c */
void		ft_init_player(t_game *game);

/* init_gates.c */
void		ft_init_gates(t_game *game);

//============================================================================//
// ⬤  430_RAYCASTING: Raycasting Engine                                      //
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
// ⬤  440_DRAW: Draw Elements to Screen                                      //
//============================================================================//

/* draw.c */
void		ft_draw_textured_wall(t_game *game, int x, t_ray *ray);
int			ft_compute_fog(double perp_wall_dist);
void		ft_mlx_pixel_put_to_image(t_game *game, int x, int y, int color);
/* draw_gate.c */
void		ft_draw_gate(t_game *game, int x, t_ray *ray);

/* draw_minimap.c */
void		ft_draw_grid(t_game *game);
void		ft_draw_player(t_game *game);

/* draw_minimap_utils.c */
void		ft_draw_cell(t_game *game, int map_x, int map_y, t_cell type);

//============================================================================//
// ⬤  420_RENDERING: Render Logic                                            //
//============================================================================//

/* render_frame.c */
int			ft_render_next_frame(t_game *game);
void		ft_clear_image(t_game *game, int ceiling_color, int floor_color);

/* render_gradient.c */
void		ft_clear_ceiling(t_game *game, int ceiling_color);
void		ft_clear_floor(t_game *game, int floor_color);

/* render_utils.c */
void		ft_set_floor_n_ceiling(t_game *game);

/* display_door_animation.c */
void		ft_update_gates(t_game *game);

/* display_minimap_bonus.c */
void		ft_display_minimap(t_game *game);

/* color_utils.c */
int			ft_rgb_to_hex(int r, int g, int b);
int			ft_darken_rgb_color3(int color, double factor, int times);

/* gradient_utils.c */
int			ft_gradient_step(int y, int start_y, int is_ceiling);

//============================================================================//
// ⬤  500_EVENTS: User Input & Event Handling                                //
//============================================================================//

/* events.c */
int			ft_handle_key(int key, t_game *game);
int			ft_handle_key_release(int key, t_game *game);

/* movements.c */
void		ft_move_forward(t_game *game, double move_speed);
void		ft_move_backward(t_game *game, double move_speed);
void		ft_move_left(t_game *game, double move_speed);
void		ft_move_right(t_game *game, double move_speed);

/* rotations.c */
void		ft_rotate(t_game *game, double angle_rad);

/* door_animation.c */
void		ft_handle_gate_animation(t_game *game);

/* door_colision.c */
bool		ft_handle_door_collision(t_game *game, double new_x, double new_y);
int			ft_find_gate_index(t_game *game, int x, int y);

/* mouse_move.c */
int			ft_mouse_move_handler(int x, int y, t_game *game);

//============================================================================//
// ⬤  410_TEXTURES: Texture Management                                       //
//============================================================================//

/* textures.c */
void		ft_load_textures(t_game *game);

/* textures_gates.c */
void		ft_load_gate_textures(t_game *game);

/* textures_intro.c */
void		ft_load_and_init_intro_textures(t_game *game);

//============================================================================//
// ⬤  600_UTILS: Helper Functions                                            //
//============================================================================//

/* utils.c */
int			ft_is_space(char c);
int			ft_array_len(char **arr);
int			ft_get_time_ms(void);

/* safe_utils.c */
void		*ft_safe_malloc(size_t size);
int			ft_valid_fd(t_game *game, char *path);

//============================================================================//
// ⬤  700_CLEANUP: Memory Management & Exit                                  //
//============================================================================//

/* free.c */
void		ft_cleanup(t_game *game, char *msg, int fd, int status);

/* free_parse.c */
void		ft_free_parse(t_game *game);

/* free_utils.c */
void		ft_free(void *ptr);
void		ft_free_arr(char **arr);

/* quit_game.c */
int			ft_quit_game(t_game *game);

#endif
