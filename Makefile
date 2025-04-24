# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:57:53 by meferraz          #+#    #+#              #
#    Updated: 2025/04/24 11:57:40 by jmeirele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                              CUBE3D PROJECT                                  #
#==============================================================================#

NAME        = cub3d

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

BUILD_PATH       = .build
SRC_PATH         = src
INIT_PATH        = ${SRC_PATH}/100_init
PARSE_PATH       = ${SRC_PATH}/200_parse
INIT_GAME_PATH   = ${SRC_PATH}/300_init_game
RAYCAST_PATH     = ${SRC_PATH}/430_raycasting
DRAW_PATH        = ${SRC_PATH}/440_draw
TEXTURE_PATH     = ${SRC_PATH}/410_textures
RENDER_PATH      = ${SRC_PATH}/420_rendering
EVENTS_PATH      = ${SRC_PATH}/500_events
UTILS_PATH       = ${SRC_PATH}/600_utils
CLEANUP_PATH     = ${SRC_PATH}/700_cleanup

INC_PATH         = inc
LIBFT_PATH       = 42_Libft

HEADERS     = $(addprefix $(INC_PATH)/, ansi.h cub3d.h macros.h prototypes.h types.h)

SRCS        = ${SRC_PATH}/main.c \
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

# Valgrind options
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

val: deps $(NAME)
	@printf "${BLUE}${BOLD}Running Valgrind...${RESET}\n"
	@valgrind $(V_ARGS) ./$(NAME)

vgdb: deps $(NAME)
	@printf "${BLUE}${BOLD}Running Valgrind with GDB...${RESET}\n"
	@valgrind --vgdb-error=0 $(V_ARGS) ./$(NAME)

# gdb: all
# 	@printf "${BLUE}${BOLD}Launching GDB...${RESET}\n"
# 	@gdb -tui -q ./$(NAME) -x .gdbinit

ARGS        = maps/valid_maps/test.cub

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
	valgrind ${V_ARGS} ./${NAME} maps/valid_maps/test.cub

#------------------------------------------------------------------------------#
#                                CLEANING RULES                                #
#------------------------------------------------------------------------------#

clean:
	@printf "${YELLOW}${BOLD}${CLEAN} Cleaning object files...${RESET}\n"
	@$(RM) $(OBJS) $(BUILD_PATH)
	@if [ -d $(LIBFT_PATH) ]; then \
		$(MAKE) -C $(LIBFT_PATH) clean; \
	fi
	@if [ -d $(MINILIBX_PATH) ]; then \
		$(MAKE) -C $(MINILIBX_PATH) clean; \
	fi
	@printf "${GREEN}${BOLD}${CHECK} Object files removed${RESET}\n"

fclean: clean
	@printf "${YELLOW}${BOLD}${CLEAN} Removing all build artifacts...${RESET}\n"
	@$(RM) $(NAME)
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
