SRC		= src/main.c \
		src/network.c \
		src/logging.c \
		
OBJ		= $(SRC:.c=.o)

NAME	= koala_strike

RM 		= rm -f

CC		= gcc

CFLAGS  = -Wall -Wextra -Werror
CFLAGS += -pedantic
CFLAGS += -I./include

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean: 
		$(RM) $(OBJ)

fclean: 
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re