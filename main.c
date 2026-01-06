#include "libft/libft.h"

static void	print_node(void *content)
{
	ft_printf("value -> %d\n", *(int *)(content));
}

static int	contains(void *a, void *b)
{
	return (a != NULL && b != NULL && *(int *)a == *(int *)b);
}

/**
 * @brief
 * Convert str into an int and push it at the end of 'a'
 * Except if:
 * - str is not a digit
 * - str overflowesint limits
 * - 'a' already contains str
 * @return
 * 1 if ok
 */
static int	check_and_push(t_list **a, char *str)
{
	int	*new_value;

	if (ft_is_integer(str))
	{
		new_value = malloc(sizeof(int));
		if (new_value != NULL)
		{
			*new_value = ft_atoi(str);
			if (*new_value != ft_atol(str)
				|| ft_lst_contains_key(*a, new_value, contains))
			{
				free(new_value);
				return (0);
			}
			ft_lst_push_back(a, ft_lst_new(new_value));
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;

	a = NULL;
	if (argc <= 1)
		return (0);
	while (argc-- > 1)
	{
		argv++;
		if (check_and_push(&a, *argv) == 0)
		{
			ft_lst_clear_basic(&a);
			ft_printf_err("Error\n");
			return (1);
		}
	}

	ft_lst_iter(a, print_node);
	ft_lst_clear_basic(&a);
	ft_printf("end\n");
	return (0);
}
