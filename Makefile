CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS =

NAME = push_swap
LIBFT_FOLDER = ./libft/
LIBFT_FILE = $(LIBFT_FOLDER)libft.a

SRC = main.c \
      commands/push.c \
      commands/reverse_rotate.c \
      commands/rotate.c \
      commands/swap.c \
      greedy_push/greedy_push.c \
      group_sort.c \
      lis/lis.c \
      lis/keep_list.c \
      lis/only_keep_lis.c \
      parsing.c \
      patrick.c \
      print.c \
      selection_sort.c \
      selection_sort_range.c \
      utils/utils.c \
      utils/utils_list.c \
      utils/utils_sorted.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libft $(OBJS)
	$(CC) -g -o $(NAME) $(OBJS) $(LIBFT_FILE)

libft:
	@make -C $(LIBFT_FOLDER) --no-print-directory

debug: CFLAGS = -DDEBUG
debug: all
	./$(NAME) 0 8 4 3 12 2 10 6 14 1 9 5 13 11 7 15
	# ./$(NAME) 0 1 2 5 3
	# ./$(NAME) 1 10 5 2 3 8
	# ./$(NAME) 65 67 8 1 0 87 10 2 3 5 7 
	# ./$(NAME) 10 2 6 8 19 1 0 9 15 5 7 55 33 124 -54

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
