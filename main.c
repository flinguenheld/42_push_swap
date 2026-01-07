/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:31 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/07 19:46:07 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"
#include "commands/commands.h"
#include <limits.h>

// Who is the lowest ?
static int get_lowest_position(t_list *a)
{
	int i;
	int position;
	int lowest;
	t_list *current_node;

	i = 0;
	lowest = INT_MAX;
	current_node = a;
	while (current_node != NULL)
	{
		if (*(int *)current_node->content < lowest)
		{
			lowest = *(int *)current_node->content;
			position = i;
		}
		current_node = current_node->next;
		i++;
	}
	return (position);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	while (argc-- > 1)
	{
		argv++;
		if (check_and_push_argv(&a, *argv) == 0)
		{
			ft_lst_clear_basic(&a);
			ft_printf_err("Error\n");
			return (1);
		}
	}
	print_ab(a, b, "Original --\n", "\n");

	while (a->next != NULL)
	{
		int to_rotate = get_lowest_position(a);

		while (to_rotate--)
			rotate_a(&a);
		push_b(&a, &b);
	}
	while (b != NULL)
	{
		push_a(&a, &b);
	}

	print_ab(a, b, "Sorted --\n", "\n");

	// --
	ft_lst_clear_basic(&a);
	return (0);
}
