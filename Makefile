# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:57:53 by meferraz          #+#    #+#              #
#    Updated: 2025/03/31 16:29:28 by meferraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                              CUBE3D PROJECT                                  #
#==============================================================================#

NAME        = cub3D

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

#------------------------------------------------------------------------------#
#                             NAMES AND PATHS                                  #
#------------------------------------------------------------------------------#

BUILD_PATH  = .build
SRC_PATH    = src
INC_PATH    = inc
LIBFT_PATH  = 42_Libft

HEADERS     = $(addprefix $(INC_PATH)/, ansi.h cub3d.h macros.h prototypes.h types.h)

SRCS        = $(SRC_PATH)/000_intro.c \
			$(SRC_PATH)/100_main.c

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
	MINILIBX_PATH := lib/minilibx_opengl_20191021
	MLXFLAGS := -L$(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit
else
	MINILIBX_PATH := lib/minilibx-linux
	MLXFLAGS := -L$(MINILIBX_PATH) -lmlx_Linux -lXext -lX11 -lm
endif

LIBFT_ARC  = $(LIBFT_PATH)/libft.a
MLX_ARC    = $(MINILIBX_PATH)/libmlx.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft
LIBFT_INC   = -I$(LIBFT_PATH) -I$(MINILIBX_PATH)

MAKE_LIBFT  = $(MAKE) -C $(LIBFT_PATH)

# Valgrind options
V_ARGS      = --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --suppressions=readline.supp

#------------------------------------------------------------------------------#
#                                    RULES                                     #
#------------------------------------------------------------------------------#

all: deps $(NAME)
	@printf "\n${GREEN}${BOLD}${CHECK} Build completed successfully!${RESET}\n"

$(NAME): $(OBJS) $(LIBFT_ARC) $(MLX_ARC)| $(BUILD_PATH)
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

$(LIBFT_ARC):
	@printf "${CYAN}${BOLD}${BUILD} Building Libft...${RESET}\n"
	@$(MAKE_LIBFT)
	@printf "${GREEN}${CHECK} Libft compiled at ${WHITE}$(LIBFT_ARC)${RESET}\n"

$(MLX_ARC):
	@printf "${CYAN}${BOLD}${BUILD} Building MinilibX...${RESET}\n"
	@$(MAKE) -C $(MINILIBX_PATH)
	@printf "${GREEN}${CHECK} MinilibX compiled at ${WHITE}$(MINILIBX)${RESET}\n"
	@printf "${GREEN}${BOLD}${CHECK} MinilibX ready${RESET}\n"

deps: check_tools
	@if [ ! -d "$(LIBFT_PATH)" ]; then \
		$(MAKE) get_libft; \
	else \
		printf "${GREEN}${BOLD}${ROCKET} ${WHITE}$(LIBFT_ARC) found${RESET}\n"; \
	fi

get_libft:
	@printf "${CYAN}${BOLD}${BOOK} Cloning Libft...${RESET}\n"
	@git clone https://github.com/m3irel3s/42_Libft $(LIBFT_PATH) || (printf "${RED}${BOLD}${CROSS} Failed to clone Libft${RESET}\n" && exit 1)
	@printf "${GREEN}${BOLD}${CHECK} Libft downloaded${RESET}\n"

#------------------------------------------------------------------------------#
#                                TESTING RULES                                 #
#------------------------------------------------------------------------------#

val: deps $(NAME)
	@printf "${BLUE}${BOLD}Running Valgrind...${RESET}\n"
	@valgrind $(V_ARGS) ./$(NAME)

vgdb: deps $(NAME)
	@printf "${BLUE}${BOLD}Running Valgrind with GDB...${RESET}\n"
	@valgrind --vgdb-error=0 $(V_ARGS) ./$(NAME)

gdb: all
	@printf "${BLUE}${BOLD}Launching GDB...${RESET}\n"
	@gdb -tui -q ./$(NAME) -x .gdbinit

test: all
	@printf "${BLUE}${BOLD}Testing cube3d...${RESET}\n"
	@./$(NAME)

#------------------------------------------------------------------------------#
#                                CLEANING RULES                                #
#------------------------------------------------------------------------------#

clean:
	@printf "${YELLOW}${BOLD}${CLEAN} Cleaning object files...${RESET}\n"
	@$(RM) $(OBJS) $(BUILD_PATH)
	@printf "${GREEN}${BOLD}${CHECK} Object files removed${RESET}\n"

fclean: clean
	@printf "${YELLOW}${BOLD}${CLEAN} Removing all build artifacts...${RESET}\n"
	@$(RM) $(NAME) $(LIBFT_PATH)
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
