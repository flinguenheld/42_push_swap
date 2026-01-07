/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:53:20 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 21:53:21 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands/commands.h"
#include "../libft/libft.h"

// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv Utils vv
int *new_content(int value)
{
	int *content = malloc(sizeof(int));
	*content = value;
	return content;
}

int print_one_line(t_list **a, t_list **b)
{
	int still_one = 0;

	if (*a != NULL)
	{
		ft_printf(" % 10d ", *(int *)(*a)->content);
		*a = (*a)->next;
		still_one = 1;
	}
	else
		ft_printf("          ");

	if (*b != NULL)
	{
		ft_printf(" % 10d ", *(int *)(*b)->content);
		*b = (*b)->next;
		still_one = 1;
	}
	return still_one;
}

void print_both(t_list *a, t_list *b, char *before, char *after)
{
	ft_printf(before);
	t_list *tmp_a = a;
	t_list *tmp_b = b;
	ft_printf("        a             b\n");
	while (print_one_line(&tmp_a, &tmp_b))
		ft_printf("\n");

	ft_printf(after);
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Utils ^^
void test_push()
{
	ft_printf("-------------------------------------------------");
	ft_printf("------------------------------------ Test push --");
	ft_printf("\n");

	t_list *a = NULL;
	ft_lst_push_back(&a, ft_lst_new(new_content(1)));
	ft_lst_push_back(&a, ft_lst_new(new_content(2)));
	ft_lst_push_back(&a, ft_lst_new(new_content(3)));
	ft_lst_push_back(&a, ft_lst_new(new_content(4)));
	ft_lst_push_back(&a, ft_lst_new(new_content(5)));

	t_list *b = NULL;
	ft_lst_push_back(&b, ft_lst_new(new_content(8888888)));
	ft_lst_push_back(&b, ft_lst_new(new_content(9999999)));
	print_both(a, b, "base ---\n", "\n------\n");

	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);

	print_both(a, b, "after ---\n", "\n------\n");

	push_a(&a, &b);
	push_a(&a, &b);
	push_a(&a, &b);
	push_a(&a, &b);
	push_a(&a, &b);

	print_both(a, b, "after ---\n", "\n------\n");
	ft_lst_clear_basic(&a);
	ft_lst_clear_basic(&b);

	ft_printf("Has to print nothing with empty lists:\n");
	push_b(&a, &b);
	push_a(&a, &b);
}

void test_swap()
{
	ft_printf("-------------------------------------------------");
	ft_printf("------------------------------------ Test swap --");
	ft_printf("\n");

	t_list *a = NULL;
	ft_lst_push_back(&a, ft_lst_new(new_content(1)));
	ft_lst_push_back(&a, ft_lst_new(new_content(2)));
	ft_lst_push_back(&a, ft_lst_new(new_content(3)));
	ft_lst_push_back(&a, ft_lst_new(new_content(4)));
	ft_lst_push_back(&a, ft_lst_new(new_content(5)));

	t_list *b = NULL;
	ft_lst_push_back(&b, ft_lst_new(new_content(111)));
	ft_lst_push_back(&b, ft_lst_new(new_content(222)));
	ft_lst_push_back(&b, ft_lst_new(new_content(333)));
	ft_lst_push_back(&b, ft_lst_new(new_content(444)));
	ft_lst_push_back(&b, ft_lst_new(new_content(555)));
	print_both(a, b, "base ---\n", "\n------\n");

	swap_a(a);
	swap_b(b);

	print_both(a, b, "after ---\n", "\n------\n");

	swap_ab(a, b);

	print_both(a, b, "after ---\n", "\n------\n");

	for (int i=0; i<10; i++)
		swap_ab(a, b);

	print_both(a, b, "after ---\n", "\n------\n");
	ft_lst_clear_basic(&a);
	ft_lst_clear_basic(&b);

	ft_printf("Has to print nothing with empty lists:\n");
	swap_a(a);
	swap_b(b);
	swap_ab(a, b);
}

void test_rotate()
{
	ft_printf("-------------------------------------------------");
	ft_printf("---------------------------------- Test rotate --");
	ft_printf("\n");

	t_list *a = NULL;
	ft_lst_push_back(&a, ft_lst_new(new_content(1)));
	ft_lst_push_back(&a, ft_lst_new(new_content(2)));
	ft_lst_push_back(&a, ft_lst_new(new_content(3)));
	ft_lst_push_back(&a, ft_lst_new(new_content(4)));
	ft_lst_push_back(&a, ft_lst_new(new_content(5)));

	t_list *b = NULL;
	ft_lst_push_back(&b, ft_lst_new(new_content(111)));
	ft_lst_push_back(&b, ft_lst_new(new_content(222)));
	ft_lst_push_back(&b, ft_lst_new(new_content(333)));
	ft_lst_push_back(&b, ft_lst_new(new_content(444)));
	ft_lst_push_back(&b, ft_lst_new(new_content(555)));
	print_both(a, b, "base ---\n", "\n------\n");

	rotate_a(&a);
	rotate_b(&b);

	print_both(a, b, "rotate one ---\n", "\n------\n");

	reverse_rotate_a(&a);
	reverse_rotate_b(&b);

	print_both(a, b, "reverse rotate one ---\n", "\n------\n");

	ft_printf("Rotate 10 times ----\n");
	for (int i=0; i<10; i++)
		rotate_ab(&a, &b);
	ft_printf("And reverse rotate 10 times ----\n");
	for (int i=0; i<10; i++)
		reverse_rotate_ab(&a, &b);

	print_both(a, b, "after ---\n", "\n------\n");
	ft_lst_clear_basic(&a);
	ft_lst_clear_basic(&b);

	ft_printf("Has to print nothing with empty lists:\n");
	rotate_a(&a);
	rotate_b(&b);
	rotate_ab(&a, &b);
	reverse_rotate_a(&a);
	reverse_rotate_b(&b);
	reverse_rotate_ab(&a, &b);
}

int	main(void)
{
	ft_printf("--------------------------------------------------------------");
	ft_printf("--------------------------------------------- Test commands --");
	ft_printf("\n");

	test_push();
	test_swap();
	test_rotate();
}
