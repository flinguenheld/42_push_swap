CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS =

NAME = push_swap
LIBFT_FOLDER = ./libft/
LIBFT_FILE = $(LIBFT_FOLDER)libft.a

SRC = main.c \
      parsing.c \
      print.c \
      utils.c \
      utils_list.c \
      selection_sort.c \
      sort_ten.c \
      commands/push.c \
      commands/reverse_rotate.c \
      commands/rotate.c \
      commands/swap.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libft $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT_FILE)

libft:
	@make -C $(LIBFT_FOLDER) --no-print-directory

debug: CFLAGS = -DDEBUG
debug: all
	./$(NAME) 7 -222 3 4 55 1 10 8

test: all
	@make -C tests/ --no-print-directory

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_FOLDER) clean --no-print-directory
	@make -C tests/ clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TEST)
	@make -C $(LIBFT_FOLDER) fclean --no-print-directory
	@make -C tests/ fclean --no-print-directory

re: fclean all

.SILENT: $(NAME)
.PHONY: all libft debug test test_dev test_no_flag clean fclean re
