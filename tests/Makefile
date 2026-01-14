CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libunit_tester.exe
LIBUNIT_FOLDER = framework/ 
LIBUNIT_FILE = framework/libunit.a

SRC =	main.c \
		template_tests/00_launcher.c \
		template_tests/01_template_test.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libunit $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBUNIT_FILE)
	./$(NAME) || true

libunit:
	@make -C $(LIBUNIT_FOLDER) --no-print-directory

clean:
	@rm -f $(OBJS)
	@make -C $(LIBUNIT_FOLDER) --no-print-directory clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBUNIT_FOLDER) --no-print-directory fclean

re: fclean all

.SILENT: $(OBJS) $(NAME)
.PHONY: all clean fclean re libunit
