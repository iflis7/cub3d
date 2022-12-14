NAME = cub3d

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g 
RM = rm -f

# Detect OS and set flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LINUX = -ldl -lglfw -pthread -lm
	INC = -I include/
	LIB_LINUX = mlx/libmlx42.a 
	CLIBS = $(INC) $(LIB_LINUX) $(LINUX)
endif
ifeq ($(UNAME_S),Darwin)
	CLIBS = -L. -lmlx OpenGL -framework AppKit
endif

# Sources and objects
MAIN = cub3d
PARSING = parsing
# UTILS = utils logs

SRCS = $(addsuffix .c, $(addprefix src/main/, $(MAIN))) \
	  $(addsuffix .c, $(addprefix src/parsing/, $(PARSING))) 
#   $(addsuffix .c, $(addprefix src/utils/, $(UTILS))) \

OBJS = $(SRCS:.c=.o)


# Rules
all: 	$(NAME)
	@echo "BOOM 💥💥💥💥💥 $(NAME) Compiled! 💯 $(DEFAULT)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(CLIBS)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

# $^ $(LIBFT)
# @$(MAKE) -C $(LIBFT_PATH)
	-@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)Object files deleted!$(DEFAULT)💯"
# @make -C $(LIBFT_PATH)  clean

fclean:	clean
	@$(RM) $(NAME) 
#  $(LIBFT) 

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