CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
LIBFT_FOLDER = ./libft/
LIBFT_FILE = $(LIBFT_FOLDER)libft.a
TEST = tests/main_test

SRC = main.c \
      parsing.c \
      commands/push.c \
      commands/reverse_rotate.c \
      commands/rotate.c \
      commands/swap.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libft $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT_FILE)

libft:
	make -C $(LIBFT_FOLDER)

test_commands: all
	$(CC) tests/test_commands.c commands/*.c $(LIBFT_FILE) -o $(TEST)
	./$(TEST)

test_no_flag: CFLAGS =
test_no_flag: test

clean:
	@rm -vf $(OBJS)
	make -C $(LIBFT_FOLDER) clean

fclean: clean
	@rm -vf $(NAME)
	@rm -vf $(TEST)
	make -C $(LIBFT_FOLDER) fclean

re: fclean all

.PHONY: all $(NAME) libft test test_no_flag clean fclean re
