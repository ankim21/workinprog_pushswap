NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS :=    parsing.c \
parsing_ll.c \

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re