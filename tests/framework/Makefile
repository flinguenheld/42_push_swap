CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libunit.a

SRC =	libunit.c \
		counter.c \
		print.c \
		print_utils.c \
		utils.c \
		utils_list.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

test: all
	@make -C tests/ --no-print-directory

clean:
	@rm -f $(OBJS)
	@make -C tests/ --no-print-directory clean

fclean: clean
	@rm -f $(NAME)
	@make -C tests/ --no-print-directory fclean

re: fclean all

.PHONY: all clean fclean re test
