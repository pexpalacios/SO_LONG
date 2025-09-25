NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g3

SRC = src/main.c src/check_map.c src/make_map.c src/movement.c \
	src/parse_map.c src/check_valid.c src/xmp_loaders.c src/extras.c src/close_game.c \
		src/structs.c src/structs_tile.c
OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = includes/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBINCL	= -L libft/ -laux

MLX_PATH = includes/mlx
MLX = $(MLX_PATH)/libmlx_Linux.a
MLXFLAGS = -L mlx/ -lmlx -lXext -lX11

RESET	= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
BLUE	= \033[1;34m

###############################################################

all:$(NAME) 

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@cc $(CFLAGS) $(OBJ) -o $(NAME) $(LIBINCL) $(MLXFLAGS)				
	@echo "$(GREEN) _____ _____       __    _____ _____ _____ "
	@echo "|   __|     |     |  |  |     |   | |   __|"
	@echo "|__   |  |  |     |  |__|  |  | | | |  |  |"
	@echo "|_____|_____|_____|_____|_____|_|___|_____|"
	@echo "            |_____|                        "
	@echo "$(BLUE)                              by penpalac$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) all -s

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c
	@cc $(CFLAGS) -I LIBFT/src -I mlx -I src  -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[Objects removed]$(RESET)"

fclean:clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)
	@echo "$(RED)[Project removed]$(RESET)"

re:fclean all

.PHONY:	all clean fclean re LIBFT
