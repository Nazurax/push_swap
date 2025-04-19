# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 10:19:18 by alortiz-          #+#    #+#              #
#    Updated: 2025/01/17 10:19:24 by alortiz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================
#         VARIABLES
# =============================

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar crs
RM			= rm -rf

SRCS		= ft_printf.c			\
			  ft_putc.c		\
			  ft_putu.c		\
			  ft_utoa_base.c	\
			  bzero_p.c		\
			  calloc_p.c		\
			  ft_strlen.c		\
			  ft_puthex.c		\
			  ft_utoa.c		\
			  ft_puts.c		\
			  ft_putp.c		\
			  ft_handlezero.c	\
			  ft_putid.c		\
			  ft_putstr_fd.c

OBJS_DIR	= objs
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

# === COLORS ===
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;36m
RESET		= \033[0m

# =============================
#         COMPILATION
# =============================

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)[✓] $(NAME) creado correctamente.$(RESET)"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)[OBJ] Compilado $<$(RESET)"

# =============================
#         CLEANING
# =============================

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(BLUE)[clean] Objetos eliminados.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)[fclean] $(NAME) eliminado.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
