NAME = cub3d

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g 
RM = rm -f

# Libft
LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

# Minilibx
MLX = mlx/

# Detect OS and set flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LINUX = -ldl -lglfw -pthread -lm
	INC = -I include/
	LIB_LINUX = mlx/libmlx42.a 
	CLIBS = $(INC) $(LIB_LINUX) $(LINUX)
endif
ifeq ($(UNAME_S), Darwin)
	CLIBS = mlx/libmlx42.a -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"
endif

# Sources and objects
MAIN = cub3d init
PARSING = parsing
UTILS = utils logs map_utils list_ops parse_utils color cast_utils move_utils moves
RAYING = casting fov mini_map

SRCS = $(addsuffix .c, $(addprefix src/main/, $(MAIN))) \
	   $(addsuffix .c, $(addprefix src/parsing/, $(PARSING))) \
	   $(addsuffix .c, $(addprefix src/utils/, $(UTILS))) \
	   $(addsuffix .c, $(addprefix src/raying/, $(RAYING))) \
	  
OBJS = $(SRCS:.c=.o)


# Rules
all: $(NAME)
	-@$(MAKE) -C $(MLX) 

$(NAME): $(OBJS)
	-@$(MAKE) -C $(LIBFT_PATH)
	-@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(CLIBS)


%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH)  clean
	@make -C $(MLX) clean


fclean: clean
	-@$(RM) $(NAME) $(LIBFT) $(NAME).dSYM

re:		fclean all

.PHONY:	all clean libft fclean re

git:
	@git add .
	@git commit -m "$(COMMIT)"
	@echo "\n$(GREEN)$(NAME) Committed!$(DEFAULT)💯"

#COLORS
RED 	= 	\033[1;31m
GREEN 	= 	\033[1;32m
YELLOW 	= 	\033[1;33m
DEFAULT = 	\033[0m

COMMIT = $(shell date "+%d %B %T")

# valgrind
summary:
	valgrind --leak-check=summary --trace-children=yes --track-fds=yes ./$(NAME)

valgrind:
	valgrind --leak-check=full --trace-children=yes --track-fds=yes ./$(NAME)
