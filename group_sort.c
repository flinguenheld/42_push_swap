/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   group_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:57:04 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/16 23:03:54 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands/commands.h"
#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

static int	push_all_values_lower_than(t_stack *from, t_stack *to, int pivot)
{
	int	len;
	int	amount;

	// possibly do not do the last rotation ?
	amount = 0;
	len = ft_lst_size(from->start) + 1;
	while (len--)
	{
		if (content(from->start) <= pivot)
		{
			push(&from->start, &to->start, to->name);
			amount++;
		}
		rotate(&from->start, from->name);
	}
	print_ab(from->start, to->start, "push all values lower");
	return (0);
}

/**
 * @brief
 * Loop in the stack to fill 'values' with the lowest values
 * @return
 * The amount of added values
 */
static t_list	*get_next_values_to_push(t_stack *stack, int amount)
{
	t_list	*values;
	int		values_len;
	int		stack_len;
	t_point	current_lowest;
	
	values = NULL;
	values_len = 0;
	stack_len = ft_lst_size(stack->start);
	while (amount-- && values_len < stack_len)
	{
		// Get the lowest value in stack which is not already in values
		current_lowest = get_lowest_point(stack->start, INT_MAX, values);
		ft_printf("add this one: %d\n",current_lowest.value);
		ft_lst_push_front(&values, ft_lst_new(new_content(current_lowest.value)));
		values_len++;
	}
	print_ab(values, NULL, "VALUES TO DEAL WITH");

	return (values);
}

/**
 * @brief
 * Rotate to check the first node
 * If 'values' contains the node, push it in the second stack and remove it from
 * 'values'.
 * Continue until 'values' is empty
 */
static void	rotate_and_push_to_secondary(t_stack *from, t_stack *to, t_list **values)
{

	while (1)
	{

		// print_ab(from->start, to->start, "rotate & push");
		// print_ab(*values, NULL, "rotate & push");
		
		if (ft_lst_contains_key(*values, from->start->content, are_equal))
		{
			ft_lst_remove_if(values, from->start->content, are_equal, free);
			push(&from->start, &to->start, to->name);
		}

		if (*values == NULL)
			return;
		rotate(&from->start, from->name);
	}
}

// LOGIC
//
// AS LONG AS THERE ARE MORE THAN 3 VALUES IN THE FIRST STACK :
//
//    - GET THE N NEXT VALUES TO DEAL WITH IN A TEMP LIST
//    - ROTATE THE STACK TO PUSH THESE VALUES IN THE SECOND STACK
//         - (COULD BE OPTIMISED THAT TO CHECK IF REVERSE ROTATION IS SHORTER ??)
//    - SORT THESE VALUES IN THE SECOND STACK

// THEN
//    - SORT VALUES IN THE FIRST STACK (3 MAX)
//    - PUSH ALL VALUES FROM THE SECOND STACK IN THE FIRST ONE
void	group_sort(t_stack *from, t_stack *to)
{
	// Find a value to split

	int	pivot;
	int	amount_pushed;

	pivot = 10;

	int aaaa = 0;
	// while (from->start != NULL)
	while (aaaa < 3)
	{
		t_list *blah = get_next_values_to_push(from, 3);
		print_ab(blah, NULL, "VALUES TO DEAL WITH");

		rotate_and_push_to_secondary(from, to, &blah);
		// while (blah != NULL)
		// {
		// 	t_list *node = ft_lst_pop_back(&blah);
		// 	ft_printf("value: %d\n", content(node));
		// 	ft_lst_delone(node, free);
		// }
		aaaa++;
	}


	return;

	while (1)
	{
		// Push in b all values which are higher than the pivot
		amount_pushed = push_all_values_lower_than(from,to, pivot);
		if (to->start != NULL)
			pivot = content(to->start) + 10;
		else
			exit(1000);

		ft_printf("PIVOT: %d -------------------------------------\n", pivot);

		// print_ab(from->start, to->start, "current");
		// Sort b in the range and in reverse side
		selection_sort_range(to, from, 10, 1);

		if (ft_lst_size(from->start) <= 3)
		{
			print_ab(from->start, to->start, "before last sort");
			// selection_sort(from, to);
			return;
		}

		// If a length is lower than the pivot
				// Sort a
				// Empty b in a
	}
}
