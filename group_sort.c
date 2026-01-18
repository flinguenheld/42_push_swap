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
 * Create a new list and does 'amount' times:
 *   - Take the lowest value from stack which is not in the new list
 *   - Clone this value in the new list
 * @return
 * A list with the next values to deal with
 */
static t_list	*get_next_values_to_push(t_stack *stack, int amount)
{
	int		stack_len;
	t_point	lowest_found;
	t_list	*values_gotten;
	int		values_gotten_len;

	values_gotten = NULL;
	values_gotten_len = 0;
	stack_len = ft_lst_size(stack->start);
	while (amount-- && values_gotten_len < stack_len)
	{
		lowest_found = get_lowest_point(stack->start, INT_MAX, values_gotten);
		ft_lst_push_front(&values_gotten,
			ft_lst_new(new_content(lowest_found.value)));
		values_gotten_len++;
	}
	return (values_gotten);
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
	while (1)
	{
		if (ft_lst_contains_key(*values, from->start->content, are_equal))
		{
			ft_lst_remove_if(values, from->start->content, are_equal, free);
			push(&from->start, &to->start, to->name);
		}
		if (*values == NULL)
			return ;
		rotate(&from->start, from->name);
	}
}

/**
 * LOGIC
 *
 * AS LONG AS THERE ARE MORE THAN 3 VALUES IN THE FIRST STACK :
 *
 *    - GET THE N NEXT VALUES TO DEAL WITH IN A TEMP LIST
 *    - ROTATE THE STACK TO PUSH THESE VALUES IN THE SECOND STACK
 *         - (COULD BE OPTIMISED THAT TO CHECK IF REVERSE ROTATION IS SHORTER ??)
 *    - SORT THESE VALUES IN THE SECOND STACK
 *
 * THEN
 *    - SORT VALUES IN THE FIRST STACK (3 MAX)
 *    - PUSH ALL VALUES FROM THE SECOND STACK IN THE FIRST ONE
 */
void	group_sort(t_stack *from, t_stack *to, int group_size)
{
	t_list	*values_to_push;

	while (from->start != NULL)
	{
		values_to_push = get_next_values_to_push(from, group_size);
		// print_ab(values_to_push, NULL, "VALUES TO DEAL WITH");
		rotate_and_push_to_secondary(from, to, &values_to_push);
		selection_sort_range(to, from, group_size);
		print_ab(from->start, to->start, "HERE ??");
	}
	while (to->start != NULL)
	{
		push(&to->start, &from->start, to->name);
	}
}
