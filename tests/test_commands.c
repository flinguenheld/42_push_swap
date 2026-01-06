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

int *new_content(int value)
{
	int *content = malloc(sizeof(int));
	*content = value;
	return content;
}

void print_node(void *content)
{
	ft_printf("value -> %d\n", *(int *)(content));
}

size_t max_length(t_list *a, t_list *b)
{
	size_t length_a = ft_lst_size(a);
	size_t length_b = ft_lst_size(b);

	if (length_a >= length_b)
		return length_a;
	else
		return length_b;
}

int print_one(t_list **a, t_list **b)
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
	while (print_one(&tmp_a, &tmp_b))
		ft_printf("\n");

	ft_printf(after);
}

int	main(void)
{
	ft_printf("--------------------------------------------------------------");
	ft_printf("--------------------------------------------- Test commands --");
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
}
