NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c push_swap.c operations.c operations1.c operations2.c radix_sort.c \
      stack_utils.c utils.c input_parser.c small_sort.c ft_atoi.c error_handling.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
