/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:57:27 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/17 11:33:38 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/**
 * @brief
 * Specific case when only three values left in 'a'
 *    1 1    2 2    3 3
 *    2 3    1 3    1 2
 *    3 2    3 1    2 1
 */
// static void	three_left_sort_a(t_list **a)
static int	three_left_sort_a(t_stack *stack)
{
	int		start;
	int		middle;
	int		end;

	start = content(stack->start);
	middle = content((stack->start)->next);
	end = content((stack->start)->next->next);
	if (is_sorted(stack->start, 0))
		return (0);
	else if (start < middle && middle > end && start < end)
		return (swap(stack->start, stack->name),
			rotate(&stack->start, stack->name));
	else if (middle < start && middle < end && end > start)
		return (swap(stack->start, stack->name));
	else if (end < middle && end < start && middle > start)
		return (reverse_rotate(&stack->start, stack->name));
	else if (middle < start && middle < end && end < start)
		return (reverse_rotate(&stack->start, stack->name),
			reverse_rotate(&stack->start, stack->name));
	else
		return (swap(stack->start, stack->name),
			reverse_rotate(&stack->start, stack->name));
}

/**
 * @brief
 * Wrapper for two
 */
static void	two_left_sort_a(t_stack *stack)
{
	if (!is_sorted(stack->start, 0))
		swap(stack->start, stack->name);
}

void	selection_sort(t_stack *from, t_stack *to)
{
	int		a_size;
	t_point	lowest;

	a_size = ft_lst_size(from->start);
	while (from->start->next != NULL)
	{
		if (a_size == 2)
		{
			two_left_sort_a(from);
			break ;
		}
		if (a_size-- == 3)
		{
			three_left_sort_a(from);
			break ;
		}
		lowest = get_lowest_point(from->start, INT_MAX);
		rotate_shorter_side(&from->start, from->name, lowest.index);
		push(&from->start, &to->start, to->name);
	}
	while (to->start != NULL)
		push(&to->start, &from->start, from->name);
}
