NAME = cub3d

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

SRCS_PATH = src/
# LIBFT = include/libft/libft.a
# LIBFT_PATH = include/libft/

MAIN = cub3d
PARSING = parsing
# UTILS = utils logs ops_handling pipes 

SRCS = $(addsuffix .c, $(addprefix src/main/, $(MAIN))) \
	  $(addsuffix .c, $(addprefix src/parsing/, $(PARSING))) \
	#   $(addsuffix .c, $(addprefix src/utils/, $(UTILS))) \

OBJS = $(SRCS:c=o)


all: 	$(NAME)
	@echo "BOOM 💥💥💥💥💥 $(NAME) Compiled! 💯 $(DEFAULT)"


$(NAME): $(OBJS)
	-@$(MAKE) -C $(LIBFT_PATH)
	-@$(CC) $(CFLAGS)  -o $@  -L. -lmlx -framework OpenGL -framework AppKit
# $^ $(LIBFT)
	-@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH)  clean
	@echo "$(YELLOW)Object files deleted!$(DEFAULT)💯"

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
