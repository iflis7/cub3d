NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I includes
RM			= rm -f
AR			= ar rcs
HEADER = $(addsuffix .h, $(addprefix includes/, ))

SRCS_PATH = src/

FTIS = alnum alpha ascii digit print metachar \

FTSKIP = space spacenl char chars
FTLST = add_back add_front clear delone iter last map new size
FTMATH = abs nbrlen hexlen baselen power
FTMEM = bzero calloc memcpy memchr memcmp memcpy memmove memset
FTPUT = char_fd endl_fd nbr_fd str_fd
FTSTR = chr ncmp dup join lcat 	lcpy len mapi ncmp nstr rchr trim _chr_num \
		join_free
FTSUB = ft_substr ft_split
FTTO = ft_tolower ft_toupper ft_atoi ft_itoa ft_char_to_base
FTLEN = ft_intlen
TOOLS = get_next_line
TEST = play

SRCS = $(addsuffix .c, $(addprefix $(SRCS_PATH)is/ft_is, $(FTIS))) \
	$(addsuffix .c, $(addprefix $(SRCS_PATH)lst/ft_lst, $(FTLST))) \
	$(addsuffix .c, $(addprefix $(SRCS_PATH)mem/ft_, $(FTMEM))) \
	$(addsuffix .c, $(addprefix $(SRCS_PATH)put/ft_put, $(FTPUT))) \
	$(addsuffix .c, $(addprefix $(SRCS_PATH)str/ft_str, $(FTSTR))) \
	$(addsuffix .c, $(addprefix $(SRCS_PATH)sub/, $(FTSUB))) \
	$(addsuffix .c, $(addprefix $(SRCS_PATH)to/, $(FTTO))) \
	$(addsuffix .c, $(addprefix $(SRCS_PATH)len/, $(FTLEN))) \
	$(addsuffix .c, $(addprefix $(SRCS_PATH)tools/, $(TOOLS))) \
	$(addsuffix .c, $(addprefix $(/libft), $(TEST))) \

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

$(FORMAT): $(OBJS)
	$(shell c_formatter_42 $(SRCS) $(BONUS_SRCS))
	$(shell norminette $(SRCS) $(BONUS_SRCS))

$(NAME):	$(OBJS)
			-@$(AR) $(NAME) $(OBJS) $(FORMAT)

all:		$(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
			-@$(AR) $(NAME) $(OBJ) $(BONUS_OBJS)

clean:
			-@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			-@$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
