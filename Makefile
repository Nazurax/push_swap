NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c push_swap.c rotaters.c rotaters_2.c pushers.c swapers.c \
      stack_utils.c utils.c utils_2.c input_parser.c small_sort.c \
      small_sort_2.c error_handling.c optimize.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
