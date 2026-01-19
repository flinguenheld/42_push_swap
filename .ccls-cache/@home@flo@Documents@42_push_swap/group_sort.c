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

/**
 * @brief
 * Create a list and loop in the stack to get the 'amount' lowest values
 * @return
 * A list with the next group of values to push
 */
static t_list	*get_next_group(t_stack *stack, int group_size)
{
	int		stack_len;
	t_point	lowest_found;
	t_list	*values_gotten;
	int		values_gotten_len;

	values_gotten = NULL;
	values_gotten_len = 0;
	stack_len = ft_lst_size(stack->start);
	while (values_gotten_len < group_size && values_gotten_len <= stack_len)
	{
		lowest_found = get_lowest_point(stack->start, INT_MAX, values_gotten);
		if (lowest_found.index >= 0)
		{
			ft_lst_push_front(&values_gotten,
				ft_lst_new(new_content(lowest_found.value)));
		}
		values_gotten_len++;
	}
	return (values_gotten);
}

/**
 * @brief
 * Loop in 'values' for each one, get the needed amount of steps to find
 * the shortest path
 * @return
 * the point of the closet node in the stack
 */
static t_point	closest_next(t_list *stack, t_list *values)
{
	t_point	closest;
	int		stack_size;
	int		current_index;
	int		current_closet;
	closest = (t_point){.value = INT_MAX, .index = 0};

	if (values->next == NULL)
	{
		return ((t_point){.value = content(values), .index = get_index(stack, content(values))});
	}

	stack_size = ft_lst_size(stack);
	while (values != NULL)
	{
		current_index = get_index(stack, content(values));
		ft_printf("closet check this one: %d  value: %d\n", current_index, content(values));
		if (current_index > stack_size / 2)
			current_index = stack_size - current_index;
		if (current_index < current_closet)
		{
			closest.index = get_index(stack, content(values));
			closest.value = content(values);
			current_closet = current_index;
		}
		values = values->next;
	}

	ft_printf("closest point found: %d  value: %d\n", closest.index, closest.value);
	return (closest);
}


void	rotate_opti(t_stack *from, int index)
{
	int	size;
	int	previous_pushed;

	previous_pushed = 0;
	size = ft_lst_size(from->start);
	if (index > size / 2)
	{
		index = size - index;
		while (index--)
			reverse_rotate(&from->start, from->name);
	}
	else
	{
		while (index--)
			rotate(&from->start, from->name);
	}
}

/**
 * @brief
 * Rotate to check the first node
 * If 'values' contains the node, push it in the second stack and remove it
 * from 'values'.
 * Continue until 'values' is empty
 *
 * CAN BE OPTIMIZE BY CHECKING IF IT'S FASTER TO REVERSE_ROTATE !!!!!!!!!!!!!!
 * CAN BE OPTIMIZE BY CHECKING IF IT'S FASTER TO REVERSE_ROTATE !!!!!!!!!!!!!!
 */
static void	rotate_and_push_to_secondary(t_stack *from, t_stack *to,
											t_list **values)
{
	t_point	next_value;

	while (*values != NULL)
	{
		if (ft_lst_contains_key(*values, from->start->content, are_equal))
		{
			// ft_printf("value to deal with: %d \n", next_value.value);
			push(&from->start, &to->start, to->name);
			ft_lst_remove_if(values, to->start->content, are_equal, free);
		}
		else
		{
			next_value = closest_next(from->start, *values);
			rotate_opti(from, next_value.index);
		}
	}

}

/**
 * LOGIC
 *
 *    - GET NEXT VALUES TO DEAL WITH IN A TEMP LIST
 *    - ROTATE THE STACK TO PUSH THESE VALUES IN THE SECOND STACK
 *    - SORT THESE VALUES IN THE SECOND STACK
 *
 */
void	group_sort(t_stack *from, t_stack *to, int group_size)
{
	t_list	*values_to_push;

	while (from->start != NULL)
	{
		values_to_push = get_next_group(from, group_size);
		print_ab(values_to_push, NULL, "Next group");

		rotate_and_push_to_secondary(from, to, &values_to_push);

		print_ab(from->start, to->start, "group pushed on the right");
		// return;
		// selection_sort_range(to, from, group_size);
		// print_ab(from->start, to->start, "Then sorted ??");
	}
	// while (to->start != NULL)
	// {
	// 	push(&to->start, &from->start, to->name);
	// }
}
