CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC =  \
		ft_is/ft_is_integer.c \
		ft_is/ft_isalnum.c \
		ft_is/ft_isalpha.c \
		ft_is/ft_isascii.c \
		ft_is/ft_isdigit.c \
		ft_is/ft_isprint.c \
		ft_is/ft_isspace.c \
		\
		ft_list/ft_lst_clear.c \
		ft_list/ft_lst_contains.c \
		ft_list/ft_lst_delone.c \
		ft_list/ft_lst_iter.c \
		ft_list/ft_lst_last.c \
		ft_list/ft_lst_map.c \
		ft_list/ft_lst_new.c \
		ft_list/ft_lst_pop_back.c \
		ft_list/ft_lst_pop_front.c \
		ft_list/ft_lst_push_back.c \
		ft_list/ft_lst_push_front.c \
		ft_list/ft_lst_rotate_left.c \
		ft_list/ft_lst_rotate_right.c \
		ft_list/ft_lst_size.c \
		ft_list/ft_lst_swap_content.c \
		\
		ft_malloc/ft_calloc.c \
		\
		ft_mem/ft_bzero.c \
		ft_mem/ft_memchr.c \
		ft_mem/ft_memcmp.c \
		ft_mem/ft_memcpy.c \
		ft_mem/ft_memmove.c \
		ft_mem/ft_memrchr.c \
		ft_mem/ft_memset.c \
		ft_mem/ft_swap.c \
		\
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_char.c \
		ft_printf/ft_printf_flags.c \
		ft_printf/ft_printf_hexa.c \
		ft_printf/ft_printf_int.c \
		ft_printf/ft_printf_number.c \
		ft_printf/ft_printf_pointer.c \
		ft_printf/ft_printf_string.c \
		ft_printf/ft_printf_utils.c \
		ft_printf/ft_printf_uint.c \
		\
		ft_put/ft_putchar_fd.c \
		ft_put/ft_putendl_fd.c \
		ft_put/ft_putnbr_fd.c \
		ft_put/ft_putstr_fd.c \
		\
		ft_str/ft_split.c \
		ft_str/ft_strchr.c \
		ft_str/ft_strdup.c \
		ft_str/ft_striter.c \
		ft_str/ft_striteri.c \
		ft_str/ft_strjoin.c \
		ft_str/ft_strlcat.c \
		ft_str/ft_strlcpy.c \
		ft_str/ft_strlen.c \
		ft_str/ft_strmapi.c \
		ft_str/ft_strncmp.c \
		ft_str/ft_strnstr.c \
		ft_str/ft_strrchr.c \
		ft_str/ft_strtrim.c \
		ft_str/ft_substr.c \
		\
		ft_to/ft_atoi.c \
		ft_to/ft_atol.c \
		ft_to/ft_itoa.c \
		ft_to/ft_itohex.c \
		ft_to/ft_ltoa.c \
		ft_to/ft_ltohex.c \
		ft_to/ft_tolower.c \
		ft_to/ft_toupper.c \
		ft_to/ft_u_ul_tobase.c \
		ft_to/ft_utoa.c \
		ft_to/ft_utohex.c \

OBJS := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

test: all
	@make -C tests/ --no-print-directory

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TEST)

re: fclean all

.SILENT: $(OBJS) clean fclean
.PHONY: all test_printf test_list test_is test_no_flag clean fclean re
