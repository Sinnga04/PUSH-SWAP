NAME    := push_swap
CFLAGS  := -Wall -Wextra -Werror

 
SRCS    := operation.c moves.c moves2.c stack.c sort_algo.c parsing.c

OBJS    := $(SRCS:%.c=%.o)

CC      := gcc
LIBFT_DIR   := ./libft

LIBFT   := $(LIBFT_DIR)/libft.a
all: libft $(NAME)

libft:
	@make -sC $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC)  $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@make -sC $(LIBFT_DIR) fclean

fclean: clean
	@rm -rf $(NAME)
	@make -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft
