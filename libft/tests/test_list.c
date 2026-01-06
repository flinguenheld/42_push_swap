/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:14:54 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/04 22:13:00 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

int comparison_int_eq_hundred(void *content)
{
	return (content != NULL && *((int *)content) == 100);
}

int comparison_int_eq_to_key(void *key, void *content)
{
	return (content != NULL && key != NULL &&
		*((int *)content) == *((int *)key));
}

void test_list_comparison()
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("-------------------------------------- TEST COMPARISON ----\n");

	t_list *start = NULL;

	ft_printf("Test empty list --\n");
	if (!ft_lst_contains(start, comparison_int_eq_hundred))
		ft_printf("Do not contains\n");

	ft_printf("\n");
	ft_printf("Fill and test --\n");
	for (int i=0; i<110; i++)
	{
		ft_lst_push_back(&start, ft_lst_new(new_content(i)));
		switch (ft_lst_contains(start, comparison_int_eq_hundred))
		{
			case 1: 
				ft_printf("iteration: %d -> The list does contain 100\n", i);
				break;
			case 0:
				// ft_printf("iteration: %d -> The list does NOT contain 100\n", i);
				break;
		}
	}

	ft_lst_clear_basic(&start);
}

void test_list_comparison_key()
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("---------------------------------- TEST COMPARISON KEY ----\n");

	t_list *start = NULL;

	int *value_to_compare = new_content(555);

	ft_printf("Test empty list --\n");
	if (!ft_lst_contains_key(start, value_to_compare, comparison_int_eq_to_key))
		ft_printf("Do not contains %d\n", *value_to_compare);

	ft_printf("\n");
	ft_printf("Fill and test --\n");
	for (int i=0; i<560; i++)
	{
		ft_lst_push_back(&start, ft_lst_new(new_content(i)));
		switch (ft_lst_contains_key(start, value_to_compare, comparison_int_eq_to_key))
		{
			case 1: 
				ft_printf("iteration: %d -> The list does contain %d\n", i, *value_to_compare);
				break;
			case 0:
				// ft_printf("iteration: %d -> The list does NOT contain %d\n", i, *value_to_compare);
				break;
		}
	}

	ft_lst_clear_basic(&start);
	free(value_to_compare);
}

void test_list_push_back()
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("--------------------------------------- TEST PUSH BACK ----\n");

	t_list *start = NULL;
	ft_lst_push_back(&start, ft_lst_new(new_content(1)));
	ft_lst_push_back(&start, ft_lst_new(new_content(2)));
	ft_lst_push_back(&start, ft_lst_new(new_content(3)));
	ft_lst_push_back(&start, ft_lst_new(new_content(4)));
	ft_lst_push_back(&start, ft_lst_new(new_content(5)));

	ft_lst_iter(start, print_node);
	ft_lst_clear_basic(&start);
}

void test_list_push_front()
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("-------------------------------------- TEST PUSH FRONT ----\n");

	t_list *start = NULL;
	ft_lst_push_front(&start, ft_lst_new(new_content(1)));
	ft_lst_push_front(&start, ft_lst_new(new_content(2)));
	ft_lst_push_front(&start, ft_lst_new(new_content(3)));
	ft_lst_push_front(&start, ft_lst_new(new_content(4)));
	ft_lst_push_front(&start, ft_lst_new(new_content(5)));

	ft_lst_iter(start, print_node);
	ft_lst_clear_basic(&start);
}

void test_list_pop_back()
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("---------------------------------------- TEST POP BACK ----\n");

	t_list *node_aaa = ft_lst_new(new_content(1));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(2)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(3)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(4)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(5)));

	ft_printf("before pop --\n");
	ft_lst_iter(node_aaa, print_node);

	ft_printf("\n");
	ft_printf("Pop and print --\n");
	while (node_aaa != NULL)
	{
		t_list *last = ft_lst_pop_back(&node_aaa);
		print_node(last->content);
		free(last);
	}
}

void test_list_pop_front()
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("--------------------------------------- TEST POP FRONT ----\n");

	t_list *node_aaa = ft_lst_new(new_content(1));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(222)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(3)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(444)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(5)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(666)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(7)));

	ft_printf("before pop --\n");
	ft_lst_iter(node_aaa, print_node);

	ft_printf("\n");
	ft_printf("Pop and print --\n");
	while (node_aaa != NULL)
	{
		t_list *first = ft_lst_pop_front(&node_aaa);
		print_node(first->content);
		free(first);
	}
}

void test_list_rotate()
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("--------------------------------------- TEST POP FRONT ----\n");

	t_list *node_aaa = ft_lst_new(new_content(1));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(222)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(3)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(444)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(5)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(666)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(7)));
	ft_lst_push_back(&node_aaa, ft_lst_new(new_content(888)));

	ft_printf("Original --\n");
	ft_lst_iter(node_aaa, print_node);

	ft_printf("\n");
	ft_printf("Rotate one left --\n");
	ft_lst_rotate_left(&node_aaa);
	ft_lst_iter(node_aaa, print_node);

	ft_printf("\n");
	ft_printf("Rotate one right --\n");
	ft_lst_rotate_right(&node_aaa);
	ft_lst_iter(node_aaa, print_node);

	ft_printf("\n");
	ft_printf("Rotate 50 left --\n");
	for (int i=0; i< 50; i++)
		ft_lst_rotate_left(&node_aaa);
	ft_lst_iter(node_aaa, print_node);

	ft_printf("\n");
	ft_printf("Rotate 50 right --\n");
	for (int i=0; i< 50; i++)
		ft_lst_rotate_right(&node_aaa);
	ft_lst_iter(node_aaa, print_node);
}

void test_list_swap()
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("-------------------------------------------- TEST SWAP ----\n");

	t_list *node_aaa = ft_lst_new(new_content(1));
	t_list *node_bbb = ft_lst_new(new_content(2));
	t_list *node_ccc = ft_lst_new(new_content(3));
	t_list *node_ddd = ft_lst_new(new_content(4));
	t_list *node_eee = ft_lst_new(new_content(5));

	ft_lst_push_back(&node_aaa, node_bbb);
	ft_lst_push_back(&node_aaa, node_ccc);
	ft_lst_push_back(&node_aaa, node_ddd);
	ft_lst_push_back(&node_aaa, node_eee);

	ft_printf("before swap --\n");
	ft_lst_iter(node_aaa, print_node);

	ft_lst_swap_content(node_aaa, node_eee);
	ft_lst_swap_content(node_bbb, node_ddd);

	ft_printf("\n");
	ft_printf("after swap --\n");
	ft_lst_iter(node_aaa, print_node);

	ft_lst_clear_basic(&node_aaa);
}

int main()
{
	ft_printf("LIST TESTS --\n");
	// ------------------------------------------------------------------------
	// ------------------------------------------------------- TEST LISTS -----
	test_list_push_back();
	test_list_push_front();

	test_list_swap();
	test_list_pop_back();
	test_list_pop_front();
	test_list_rotate();

	test_list_comparison();
	test_list_comparison_key();
	return 0;
}
