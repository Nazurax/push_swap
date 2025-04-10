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
OBJS_DIR	= objs
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

$(NAME): $(LIBFT_A) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "$(GREEN)[✓] Compilado $(NAME) correctamente.$(RESET)"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "$(YELLOW)[OBJ] Compilado $<$(RESET)"

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

# =============================
#         CLEANING
# =============================

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(BLUE)[clean] Objetos eliminados.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(BLUE)[fclean] Binario eliminado.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
