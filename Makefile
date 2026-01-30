CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS = checker
LIBFT_FOLDER = ./libft/
LIBFT_FILE = $(LIBFT_FOLDER)libft.a

SRC = main.c \
      commands/push.c \
      commands/reverse_rotate.c \
      commands/rotate.c \
      commands/swap.c \
      \
      greedy/greedy_price.c \
      greedy/greedy_push.c \
      \
      lis/lis.c \
      lis/keep_list.c \
      lis/only_keep_lis.c \
      \
      sort/greedy_lis_sort.c \
      sort/group_sort.c \
      sort/selection_sort.c \
      sort/selection_sort_range.c \
      \
      utils/utils.c \
      utils/utils_list.c \
      utils/utils_sorted.c \
      utils/print.c \
      utils/parsing.c \

SRC_BONUS = \
      bonus/bonus.c \
      bonus/bonus_utils.c \
      \
      commands/push.c \
      commands/reverse_rotate.c \
      commands/rotate.c \
      commands/swap.c \
      \
      utils/utils.c \
      utils/utils_list.c \
      utils/utils_sorted.c \
      utils/print.c \
      utils/parsing.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)
OBJS_BONUS := $(SRC_BONUS:%.c=%.o)

$(NAME): libft $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT_FILE)

bonus: libft $(OBJS_BONUS)
	@$(CC) -o $(BONUS) $(OBJS_BONUS) $(LIBFT_FILE)

libft:
	@make -C $(LIBFT_FOLDER) --no-print-directory

debug: CFLAGS = -DDEBUG
debug: all
	./$(NAME) 0 8 4 3 12 2 10 6 14 1 9 5 13 11 7 15

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_FOLDER) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_FOLDER) fclean --no-print-directory

re: fclean all

.SILENT: $(NAME)
.PHONY: all libft debug clean fclean re bonus
