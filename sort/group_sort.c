/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   group_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:57:04 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/28 07:56:23 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

/**
 * @brief
 * Create a list and loop in the stack to get the 'group_size' lowest values
 * Clone each nodes in the new list
 * @return
 * A list with the next group of values to push
 */
static t_list	*get_next_group(t_stack *stack, int group_size)
{
	int		stack_len;
	t_point	lowest_found;
	t_list	*values_gotten;
	int		values_gotten_len;

	stack_len = ft_lst_size(stack->start);
	values_gotten = NULL;
	values_gotten_len = 0;
	while (values_gotten_len < group_size && values_gotten_len < stack_len)
	{
		lowest_found = get_lowest_point(stack->start, INT_MAX, values_gotten);
		if (lowest_found.index >= 0)
		{
			ft_lst_push_back(&values_gotten,
				ft_lst_new(new_content(lowest_found.value)));
		}
		values_gotten_len++;
	}
	return (values_gotten);
}

/**
 * @brief
 * Loop in 'group' and for each value:
 *  - get the needed amount of steps
 *  - only save the shortest path
 *
 * It can be we rotation or reverse rotation
 * @return
 * the point of the closet node in the stack
 */
static t_point	closest_next_value(t_list *stack, t_list *group)
{
	t_point	closest;
	int		stack_size;
	int		current_index;
	int		shortest_path_found;

	shortest_path_found = INT_MAX;
	stack_size = ft_lst_size(stack);
	closest = (t_point){.value = content(group),
		.index = get_index(stack, content(group))};
	while (group != NULL)
	{
		current_index = get_index(stack, content(group));
		if (current_index > stack_size / 2)
			current_index = stack_size - current_index;
		if (current_index < shortest_path_found)
		{
			closest.index = get_index(stack, content(group));
			closest.value = content(group);
			shortest_path_found = current_index;
		}
		group = group->next;
	}
	return (closest);
}

/**
 * @brief
 * Empties the given group of values to push values from the real stack
 * Try to reduce the amount of steps by getting the closest next value
 * to push.
 * Use rotatation and reverse rotation to do it.
 */
static int	push_group(t_stack *from, t_stack *to, t_list **values)
{
	t_point	next_value;
	int		amount_pushed;

	amount_pushed = 0;
	while (*values != NULL)
	{
		if (ft_lst_contains_key(*values, from->start->content, are_equal))
		{
			push(&from->start, &to->start, to->name);
			ft_lst_remove_if(values, to->start->content, are_equal, free);
			amount_pushed++;
		}
		else
		{
			next_value = closest_next_value(from->start, *values);
			rotate_shortest_way(from, next_value.index);
		}
	}
	return (amount_pushed);
}

/**
 * @brief
 * Steps:
 *    - Clone the lowest values which are in the stack in a temporary list
 *    - Then push these values one by one in the second stack
 *           - Smartly rotate to reduce the amount of steps
 *           - Push the stack & empties the temporary list
 *
 *    - Sort the freshly pushed values in the secondary stack
 *    - Repeat until the first stack len is low
 *
 *    - Then use the regular selection sort for the last group
 *    - Finally push back all sorted values from the secondary stack
 */
void	group_sort(t_stack *from, t_stack *to, int group_size)
{
	t_list	*values_to_push;
	int		amount_pushed;

	print_ab(from->start, to->start, "group sort");
	while (ft_lst_size(from->start) > group_size)
	{
		values_to_push = get_next_group(from, group_size);
		print_ab(values_to_push, NULL, "Next group");
		amount_pushed = push_group(from, to, &values_to_push);
		print_ab(from->start, to->start, "group pushed on the right");
		selection_sort_range(to, from, amount_pushed, 0);
	}
	print_ab(from->start, to->start, "last group ?");
	selection_sort(from, to);
	while (to->start != NULL)
		push(&to->start, &from->start, to->name);
}
