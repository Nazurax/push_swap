# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 18:15:55 by alortiz-          #+#    #+#              #
#    Updated: 2025/02/22 05:04:00 by alortiz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================
#         VARIABLES
# =============================

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
ARFLAGS		= rcs

# === LIBFT ===
LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

# === DIRECTORIES ===
SRCS_DIR	= srcs
INCLUDES	= -I includes -I $(LIBFT_DIR)

# === SOURCE FILES ===
SRCS		= $(SRCS_DIR)/main.c \
			  $(SRCS_DIR)/push_swap.c \
			  $(SRCS_DIR)/sort/quick_sort.c \
			  $(SRCS_DIR)/sort/radix_sort.c \
			  $(SRCS_DIR)/sort/small_sort.c \
			  $(SRCS_DIR)/ops/push.c \
			  $(SRCS_DIR)/ops/swap.c \
			  $(SRCS_DIR)/ops/rotate.c \
			  $(SRCS_DIR)/ops/reverse_rotate.c \
			  $(SRCS_DIR)/utils/parse_input.c \
			  $(SRCS_DIR)/utils/bubble_sort.c \
			  $(SRCS_DIR)/utils/normalize.c \
			  $(SRCS_DIR)/utils/errors.c \
			  $(SRCS_DIR)/utils/ft_atoi.c

OBJS		= $(SRCS:.c=.o)

# =============================
#         COMPILATION
# =============================

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

# =============================
#         CLEANING
# =============================

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
