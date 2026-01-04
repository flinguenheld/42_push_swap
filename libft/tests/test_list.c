/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:14:54 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/04 12:20:47 by flinguen         ###   ########.fr       */
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
	ft_printf("MAIN TEST --\n");
	// ------------------------------------------------------------------------
	// ------------------------------------------------------- TEST LISTS -----
	test_list_swap();
	test_list_pop_back();
	test_list_pop_front();
	test_list_rotate();

	return 0;
}
