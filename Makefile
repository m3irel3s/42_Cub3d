# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:57:53 by meferraz          #+#    #+#              #
#    Updated: 2025/04/25 15:07:14 by jmeirele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                              CUBE3D PROJECT                                  #
#==============================================================================#

NAME        = cub3d
NAME_BONUS  = cub3d_bonus

#------------------------------------------------------------------------------#
#                            CUBE3D PROJECT HEADER                             #
#------------------------------------------------------------------------------#

define HEADER
$(BOLD)$(BYEL)
$(BRED)╔════════════════════════════════════════════════╗
$(BRED)║  $(BRED)██████╗ $(BYEL)██╗   ██╗ $(BRED)██████╗  $(BYEL)██████╗  $(BRED)██████╗   $(BRED)║
$(BRED)║  $(BYEL)██╔══   $(BRED)██║   ██║ $(BYEL)██╔══██╗ $(BRED)╚════██╗ $(BYEL)██╔══██╗  $(BRED)║
$(BRED)║  $(BRED)██║     $(BYEL)██║   ██║ $(BRED)██████╔╝ $(BYEL) █████╔╝ $(BRED)██║  ██║  $(BRED)║
$(BRED)║  $(BYEL)██║     $(BRED)██║   ██║ $(BYEL)██╔══██╗ $(BRED) ╚═══██╗ $(BYEL)██║  ██║  $(BRED)║
$(BRED)║  $(BRED)██████╗ $(BYEL)╚██████╔╝ $(BRED)██████╔╝ $(BYEL)██████╔╝ $(BRED)██████╔╝  $(BRED)║
$(BRED)║  $(BYEL)╚═════╝ $(BRED) ╚═════╝  $(BYEL)╚═════╝  $(BRED)╚═════╝  $(BYEL)╚═════╝   $(BRED)║
$(BRED)╚════════════════════════════════════════════════╝

     Cub3D - Unleash the 3D Maze Experience!
$(RESET)
endef
export HEADER

define HEADER_BONUS
$(BOLD)$(BYEL)
$(BRED) ╔════════════════════════════════════════════════╗
$(BRED) ║  $(BRED)██████╗ $(BYEL)██╗   ██╗ $(BRED)██████╗  $(BYEL)██████╗  $(BRED)██████╗   $(BRED)║
$(BRED) ║  $(BYEL)██╔══   $(BRED)██║   ██║ $(BYEL)██╔══██╗ $(BRED)╚════██╗ $(BYEL)██╔══██╗  $(BRED)║
$(BRED) ║  $(BRED)██║     $(BYEL)██║   ██║ $(BRED)██████╔╝ $(BYEL) █████╔╝ $(BRED)██║  ██║  $(BRED)║
$(BRED) ║  $(BYEL)██║     $(BRED)██║   ██║ $(BYEL)██╔══██╗ $(BRED) ╚═══██╗ $(BYEL)██║  ██║  $(BRED)║
$(BRED) ║  $(BRED)██████╗ $(BYEL)╚██████╔╝ $(BRED)██████╔╝ $(BYEL)██████╔╝ $(BRED)██████╔╝  $(BRED)║
$(BRED) ║  $(BYEL)╚═════╝ $(BRED) ╚═════╝  $(BYEL)╚═════╝  $(BRED)╚═════╝  $(BYEL)╚═════╝   $(BRED)║
$(BRED) ╚════════════════════════════════════════════════╝
$(BRED)╔═══════════════════════════════════════════════════╗
$(BRED)║  $(BRED)██████╗  $(BYEL) ██████╗  $(BRED)███╗   ██╗ $(BYEL)██╗   ██╗ $(BRED)███████╗ $(BRED)║
$(BRED)║  $(BYEL)██╔══██╗ $(BRED)██╔═══██╗ $(BYEL)████╗  ██║ $(BRED)██║   ██║ $(BYEL)██╔════╝ $(BRED)║
$(BRED)║  $(BRED)██████╔╝ $(BYEL)██║   ██║ $(BRED)██╔██╗ ██║ $(BYEL)██║   ██║ $(BRED)███████╗ $(BRED)║
$(BRED)║  $(BYEL)██╔══██╗ $(BRED)██║   ██║ $(BYEL)██║╚██╗██║ $(BRED)██║   ██║ $(BYEL)╚════██║ $(BRED)║
$(BRED)║  $(BRED)██████╔╝ $(BYEL)╚██████╔╝ $(BRED)██║ ╚████║ $(BYEL)╚██████╔╝ $(BRED)███████║ $(BRED)║
$(BRED)║  $(BYEL)╚═════╝   $(BRED)╚═════╝  $(BYEL)╚═╝  ╚═══╝  $(BRED)╚═════╝  $(BYEL)╚══════╝ $(BRED)║
$(BRED)╚═══════════════════════════════════════════════════╝

     Cub3D BONUS - Unleash the 3D Maze Experience!
$(RESET)
endef
export HEADER_BONUS

#------------------------------------------------------------------------------#
#                                COLORS & STYLES                               #
#------------------------------------------------------------------------------#

RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
CYAN        = \033[0;36m
WHITE       = \033[0;37m
RESET       = \033[0m
BOLD        = \033[1m
DIM         = \033[2m
CHECK       = ✔️
CROSS       = ❌
CLEAN       = 🧹
BUILD       = 🔨
ROCKET      = 🚀
BOOK        = 📚

# Fire-inspired colors for the header
BRED        = \033[1;31m
BYEL        = \033[1;33m

#------------------------------------------------------------------------------#
#                             NAMES AND PATHS                                  #
#------------------------------------------------------------------------------#

LIBFT_PATH       = 42_Libft

#------------------------------------------------------------------------------#
#                              MANDATORY PART                                  #
#------------------------------------------------------------------------------#

BUILD_PATH       = .build
SRC_PATH         = src
INIT_PATH        = ${SRC_PATH}/100_init
PARSE_PATH       = ${SRC_PATH}/200_parse
INIT_GAME_PATH   = ${SRC_PATH}/300_init_game
TEXTURE_PATH     = ${SRC_PATH}/410_textures
RENDER_PATH      = ${SRC_PATH}/420_rendering
RAYCAST_PATH     = ${SRC_PATH}/430_raycasting
DRAW_PATH        = ${SRC_PATH}/440_draw
EVENTS_PATH      = ${SRC_PATH}/500_events
UTILS_PATH       = ${SRC_PATH}/600_utils
CLEANUP_PATH     = ${SRC_PATH}/700_cleanup

INC_PATH         = inc

HEADERS     = $(addprefix $(INC_PATH)/, ansi.h cub3d.h macros.h prototypes.h types.h)

SRCS          = ${SRC_PATH}/main.c \
				${INIT_PATH}/init.c \
				${PARSE_PATH}/parse.c \
				${PARSE_PATH}/file_path.c \
				${PARSE_PATH}/cub_file.c \
				${PARSE_PATH}/headers.c \
				${PARSE_PATH}/headers_2.c \
				${PARSE_PATH}/headers_colors.c \
				${PARSE_PATH}/headers_paths.c \
				${PARSE_PATH}/parse_utils.c \
				${PARSE_PATH}/map_grid.c \
				${PARSE_PATH}/map_utils.c \
				${PARSE_PATH}/map_closure.c \
				${INIT_GAME_PATH}/init_game.c \
				${INIT_GAME_PATH}/init_player.c \
				${RAYCAST_PATH}/raycasting.c \
				${RAYCAST_PATH}/init_raycasting.c \
				${RAYCAST_PATH}/dda_raycasting.c \
				${RAYCAST_PATH}/draw_raycasting.c \
				${DRAW_PATH}/draw.c \
				${TEXTURE_PATH}/textures.c \
				${RENDER_PATH}/render_frame.c \
				${RENDER_PATH}/render_utils.c \
				${RENDER_PATH}/render_gradient.c \
				${RENDER_PATH}/color_utils.c \
				${RENDER_PATH}/gradient_utils.c \
				${EVENTS_PATH}/events.c \
				${EVENTS_PATH}/rotations.c \
				${EVENTS_PATH}/movements.c \
				${UTILS_PATH}/utils.c \
				${UTILS_PATH}/safe_utils.c \
				${CLEANUP_PATH}/free.c \
				${CLEANUP_PATH}/free_parse.c \
				${CLEANUP_PATH}/free_utils.c \
				${CLEANUP_PATH}/quit_game.c \

OBJS        = $(SRCS:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)

#------------------------------------------------------------------------------#
#                                 BONUS PART                                   #
#------------------------------------------------------------------------------#

BUILD_PATH_BONUS       = .build_bonus
SRC_PATH_BONUS         = src_bonus
INIT_PATH_BONUS        = ${SRC_PATH_BONUS}/100_init_bonus
PARSE_PATH_BONUS       = ${SRC_PATH_BONUS}/200_parse_bonus
INIT_GAME_PATH_BONUS   = ${SRC_PATH_BONUS}/300_init_game_bonus
TEXTURE_PATH_BONUS     = ${SRC_PATH_BONUS}/410_textures_bonus
RENDER_PATH_BONUS      = ${SRC_PATH_BONUS}/420_rendering_bonus
RAYCAST_PATH_BONUS     = ${SRC_PATH_BONUS}/430_raycasting_bonus
DRAW_PATH_BONUS        = ${SRC_PATH_BONUS}/440_draw_bonus
EVENTS_PATH_BONUS      = ${SRC_PATH_BONUS}/500_events_bonus
UTILS_PATH_BONUS       = ${SRC_PATH_BONUS}/600_utils_bonus
CLEANUP_PATH_BONUS     = ${SRC_PATH_BONUS}/700_cleanup_bonus

INC_PATH_BONUS         = inc_bonus

HEADERS_BONUS     = $(addprefix $(INC_PATH_BONUS)/, ansi_bonus.h cub3d_bonus.h macros_bonus.h prototypes_bonus.h types_bonus.h)

SRCS_BONUS    = ${SRC_PATH_BONUS}/main_bonus.c \
				${INIT_PATH_BONUS}/init_bonus.c \
				${PARSE_PATH_BONUS}/parse_bonus.c \
				${PARSE_PATH_BONUS}/file_path_bonus.c \
				${PARSE_PATH_BONUS}/cub_file_bonus.c \
				${PARSE_PATH_BONUS}/headers_bonus.c \
				${PARSE_PATH_BONUS}/headers_2_bonus.c \
				${PARSE_PATH_BONUS}/headers_colors_bonus.c \
				${PARSE_PATH_BONUS}/headers_paths_bonus.c \
				${PARSE_PATH_BONUS}/parse_utils_bonus.c \
				${PARSE_PATH_BONUS}/map_grid_bonus.c \
				${PARSE_PATH_BONUS}/map_utils_bonus.c \
				${PARSE_PATH_BONUS}/map_closure_bonus.c \
				${INIT_GAME_PATH_BONUS}/init_game_bonus.c \
				${INIT_GAME_PATH_BONUS}/init_gates_bonus.c \
				${INIT_GAME_PATH_BONUS}/init_player_bonus.c \
				${RAYCAST_PATH_BONUS}/raycasting_bonus.c \
				${RAYCAST_PATH_BONUS}/init_raycasting_bonus.c \
				${RAYCAST_PATH_BONUS}/dda_raycasting_bonus.c \
				${RAYCAST_PATH_BONUS}/draw_raycasting_bonus.c \
				${DRAW_PATH_BONUS}/draw_bonus.c \
				${DRAW_PATH_BONUS}/draw_gate_bonus.c \
				${DRAW_PATH_BONUS}/draw_minimap_bonus.c \
				${DRAW_PATH_BONUS}/draw_minimap_utils_bonus.c \
				${TEXTURE_PATH_BONUS}/textures_bonus.c \
				${TEXTURE_PATH_BONUS}/textures_gates_bonus.c \
				${TEXTURE_PATH_BONUS}/textures_intro_bonus.c \
				${RENDER_PATH_BONUS}/render_frame_bonus.c \
				${RENDER_PATH_BONUS}/render_utils_bonus.c \
				${RENDER_PATH_BONUS}/display_minimap_bonus_bonus.c \
				${RENDER_PATH_BONUS}/display_gates_bonus.c \
				${RENDER_PATH_BONUS}/render_gradient_bonus.c \
				${RENDER_PATH_BONUS}/color_utils_bonus.c \
				${RENDER_PATH_BONUS}/gradient_utils_bonus.c \
				${EVENTS_PATH_BONUS}/events_bonus.c \
				${EVENTS_PATH_BONUS}/rotations_bonus.c \
				${EVENTS_PATH_BONUS}/movements_bonus.c \
				${EVENTS_PATH_BONUS}/try_moves_bonus.c \
				${EVENTS_PATH_BONUS}/player_moves_bonus.c \
				${EVENTS_PATH_BONUS}/door_animation_bonus.c \
				${EVENTS_PATH_BONUS}/door_colision_bonus.c \
				${EVENTS_PATH_BONUS}/mouse_move_bonus.c \
				${UTILS_PATH_BONUS}/utils_bonus.c \
				${UTILS_PATH_BONUS}/safe_utils_bonus.c \
				${CLEANUP_PATH_BONUS}/free_bonus.c \
				${CLEANUP_PATH_BONUS}/free_parse_bonus.c \
				${CLEANUP_PATH_BONUS}/free_utils_bonus.c \
				${CLEANUP_PATH_BONUS}/quit_game_bonus.c \

OBJS_BONUS        = $(SRCS_BONUS:$(SRC_PATH_BONUS)/%.c=$(BUILD_PATH_BONUS)/%.o)

#------------------------------------------------------------------------------#
#                             FLAGS & COMMANDS                                 #
#------------------------------------------------------------------------------#

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -fr
MKDIR       = mkdir -p
INCLUDES    = -I$(INC_PATH)
LDFLAGS     = -L$(LIBFT_PATH) -lft

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	MINILIBX_PATH := lib/minilibx
	MLXFLAGS := -L$(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit
else
	MINILIBX_PATH := lib/minilibx
	MLXFLAGS := -L$(MINILIBX_PATH) -lmlx_Linux -lXext -lX11 -lm
endif

LIBFT_ARC  = $(LIBFT_PATH)/libft.a
MLX_ARC    = $(MINILIBX_PATH)/libmlx.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft
LIBFT_INC   = -I$(LIBFT_PATH) -I$(MINILIBX_PATH)

MAKE_LIBFT  = $(MAKE) -C $(LIBFT_PATH)

V_ARGS      = --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes

#------------------------------------------------------------------------------#
#                                    RULES                                     #
#------------------------------------------------------------------------------#

all: deps $(NAME)
	@echo "$$HEADER"
	@printf "${GREEN}${BOLD}${CHECK} Cub3D ready!${RESET}\n"

$(NAME): $(OBJS) $(LIBFT_ARC) $(MLX_ARC) | $(BUILD_PATH)
	@printf "${CYAN}${DIM}Linking cub3d...${RESET}\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(MLXFLAGS) -o $@
	@printf "${GREEN}${BOLD}${CHECK} Cube3D compiled!${RESET}\n"

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS) | $(BUILD_PATH)
	@$(MKDIR) $(@D)
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-35s${RESET}\r" "$(notdir $<)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_PATH):
	@printf "${BLUE}${BOLD}${BUILD} Creating build directory...${RESET}\n"
	@$(MKDIR) $(BUILD_PATH)
	@printf "${GREEN}${CHECK} Build directory ready${RESET}\n"
	@if [ ! -f $(BUILD_PATH)/.banner_done ]; then \
		echo "$$HEADER"; \
		touch $(BUILD_PATH)/.banner_done; \
	fi

#------------------------------------------------------------------------------#
#                                    BONUS                                     #
#------------------------------------------------------------------------------#

bonus: deps $(NAME_BONUS)
	@echo "$$HEADER_BONUS"
	@printf "${GREEN}${BOLD}${CHECK} Cub3D BONUS ready!${RESET}\n"

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_ARC) $(MLX_ARC) | $(BUILD_PATH_BONUS)
	@printf "${CYAN}${DIM}Linking cub3d_bonus...${RESET}\n"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) $(MLXFLAGS) -o $@
	@printf "${GREEN}${BOLD}${CHECK} Cube3D BONUS compiled!${RESET}\n"

$(BUILD_PATH_BONUS)/%.o: $(SRC_PATH_BONUS)/%.c $(HEADERS_BONUS) | $(BUILD_PATH_BONUS)
	@$(MKDIR) $(@D)
	@printf "${CYAN}${DIM}Compiling BONUS: ${WHITE}%-35s${RESET}\r" "$(notdir $<)"
	@$(CC) $(CFLAGS) -I$(INC_PATH_BONUS) -c $< -o $@

$(BUILD_PATH_BONUS):
	@printf "${BLUE}${BOLD}${BUILD} Creating bonus build directory...${RESET}\n"
	@$(MKDIR) $(BUILD_PATH_BONUS)
	@printf "${GREEN}${CHECK} Bonus build directory ready${RESET}\n"

#------------------------------------------------------------------------------#
#                                BUILD LIBS                                    #
#------------------------------------------------------------------------------#

$(LIBFT_ARC):
	@printf "${CYAN}${BOLD}${BUILD} Building Libft...${RESET}\n"
	@$(MAKE_LIBFT)
	@printf "${GREEN}${CHECK} Libft compiled at ${WHITE}$(LIBFT_ARC)${RESET}\n"

$(MLX_ARC):
	@printf "${CYAN}${BOLD}${BUILD} Building MinilibX...${RESET}\n"
	@$(MAKE) -C $(MINILIBX_PATH)
	@printf "${GREEN}${CHECK} MinilibX compiled at ${WHITE}$(MLX_ARC)${RESET}\n"
	@printf "${GREEN}${BOLD}${CHECK} MinilibX ready${RESET}\n"

deps: check_tools
	@if [ ! -d "$(LIBFT_PATH)" ]; then \
		$(MAKE) get_libft; \
	fi
	@if [ ! -d "$(MINILIBX_PATH)" ]; then \
		$(MAKE) get_minilibx; \
	fi

#------------------------------------------------------------------------------#
#                             GET EXTERNAL LIBS                                #
#------------------------------------------------------------------------------#

get_libft:
	@printf "${CYAN}${BOLD}${BOOK} Cloning Libft...${RESET}\n"
	@git clone https://github.com/m3irel3s/42_Libft $(LIBFT_PATH) || (printf "${RED}${BOLD}${CROSS} Failed to clone Libft${RESET}\n" && exit 1)
	@printf "${GREEN}${BOLD}${CHECK} Libft downloaded${RESET}\n"

get_minilibx:
	@printf "${CYAN}${BOLD}${BOOK} Cloning MinilibX...${RESET}\n"
	@if [ "$(UNAME_S)" = "Darwin" ]; then \
		git clone https://github.com/melaniereis/minilibx_opengl_20191021.git $(MINILIBX_PATH) || (printf "${RED}${BOLD}${CROSS} Failed to clone MinilibX${RESET}\n" && exit 1); \
		printf "${GREEN}${BOLD}${CHECK} MinilibX downloaded${RESET}\n"; \
		printf "${GREEN}${BOLD}${CHECK} MinilibX ready${RESET}\n"; \
	else \
		git clone https://github.com/melaniereis/minilibx-linux.git $(MINILIBX_PATH) || (printf "${RED}${BOLD}${CROSS} Failed to clone MinilibX${RESET}\n" && exit 1); \
		printf "${GREEN}${BOLD}${CHECK} MinilibX downloaded${RESET}\n"; \
		printf "${GREEN}${BOLD}${CHECK} MinilibX ready${RESET}\n"; \
	fi

#------------------------------------------------------------------------------#
#                                TESTING RULES                                 #
#------------------------------------------------------------------------------#

ARGS        = maps/valid_maps/test.cub

val: deps $(NAME)
	@printf "${BLUE}${BOLD}Running Valgrind...${RESET}\n"
	@valgrind $(V_ARGS) ./$(NAME) {ARGS}

gdb: all $(NAME)
	tmux split-window -h "gdb --tui --args ./$(NAME) $(ARGS)"
	tmux resize-pane -L 5
	make get_log

get_log:
	rm -f gdb.txt
	touch gdb.txt
	@if command -v lnav; then \
		lnav gdb.txt; \
	else \
		tail -f gdb.txt; \
	fi

test: all
	@printf "${BLUE}${BOLD}Testing cube3d...${RESET}\n"
	@./$(NAME)

#------------------------------------------------------------------------------#
#                                 MAPPING TEST                                 #
#------------------------------------------------------------------------------#

test1: all
	valgrind ${V_ARGS} ./${NAME} maps/valid_maps/tst.cub

#------------------------------------------------------------------------------#
#                                CLEANING RULES                                #
#------------------------------------------------------------------------------#

clean:
	@printf "${YELLOW}${BOLD}${CLEAN} Cleaning object files...${RESET}\n"
	@$(RM) $(OBJS) $(BUILD_PATH) $(OBJS_BONUS) $(BUILD_PATH_BONUS)
	@if [ -d $(LIBFT_PATH) ]; then \
		$(MAKE) -C $(LIBFT_PATH) clean; \
	fi
	@if [ -d $(MINILIBX_PATH) ]; then \
		$(MAKE) -C $(MINILIBX_PATH) clean; \
	fi
	@printf "${GREEN}${BOLD}${CHECK} Object files removed${RESET}\n"

fclean: clean
	@printf "${YELLOW}${BOLD}${CLEAN} Removing all build artifacts...${RESET}\n"
	@$(RM) $(NAME) $(NAME_BONUS)
	@if [ -d $(LIBFT_PATH) ]; then \
		$(RM) $(LIBFT_PATH) $(MINILIBX_PATH); \
	fi
	@printf "${GREEN}${BOLD}${CHECK} Full cleanup completed${RESET}\n"

re: fclean all
	@printf "${GREEN}${BOLD}${ROCKET} Rebuild finished${RESET}\n"

#------------------------------------------------------------------------------#
#                                NORMINETTE                                    #
#------------------------------------------------------------------------------#

norm:
	@printf "${BLUE}${BOLD}Checking Norminette...${RESET}\n"
	@command -v norminette >/dev/null || (printf "${RED}${BOLD}${CROSS} Norminette not found${RESET}\n" && exit 1)
	@FILES=$$(find . -name "*.c" -o -name "*.h"); \
	if [ -n "$$FILES" ]; then (norminette $$FILES | awk '/Error:/ {print "$(RED)$(BOLD)" $$0 "$(RESET)"; errors++} /: OK!/ {print "$(GREEN)" $$0 "$(RESET)"} END {if (errors) print "$(RED)$(BOLD)$(CROSS) " errors " errors found$(RESET)"; else print "$(GREEN)$(BOLD)$(CHECK) No errors found$(RESET)"}') ; \
	else (printf "${YELLOW}${BOLD}⚠️ No files to check${RESET}\n"); fi

#------------------------------------------------------------------------------#
#                                UTILITY RULES                                 #
#------------------------------------------------------------------------------#

check_tools:
	@command -v git >/dev/null || (printf "${RED}${BOLD}${CROSS} Git not found${RESET}\n" && exit 1)
	@command -v $(CC) >/dev/null || (printf "${RED}${BOLD}${CROSS} Compiler $(CC) not found${RESET}\n" && exit 1)

.PHONY: all clean fclean re norm check_tools deps get_libft val vgdb gdb test
