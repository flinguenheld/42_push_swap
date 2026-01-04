#include "libft/libft.h"

/**
 * @brief
 * Check if all argv values are integers. 
 * And if there is at least one value.
 * @return
 * 1 if ok
 */
int	are_arguments_ok(int argc, char **argv)
{
	if (argc <= 0)
		return (0);
	while (argc--)
	{
		if (!ft_is_integer(*argv))
			return (0);
		argv++;
	}
	return (1);
}

/**
 * @brief
 * Malloc a int to set the value 
 */
int *new_content(int value)
{
	int	*content;

	content = malloc(sizeof(int));
	*content = value;
	return (content);
}

void print_node(void *content)
{
	ft_printf("value -> %d\n", *(int *)(content));
}

int	main(int argc, char **argv)
{
	t_list	*a;

	a = NULL;
	ft_printf("value of argc: %d\n", argc);
	if (are_arguments_ok(--argc, ++argv) == 0)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	// Build A
	while (argc--)
	{
		ft_lst_push_back(&a, ft_lst_new(new_content(ft_atoi(*argv))));
		argv++;
	}

	ft_lst_iter(a, print_node);
	ft_lst_clear_basic(&a);

	ft_printf("end\n");
}
