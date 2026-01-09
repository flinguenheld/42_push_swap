/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:57:27 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/09 18:48:36 by flinguen         ###   ########.fr       */
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
static void	three_left_sort_a(t_list **a)
{
	int		start;
	int		middle;
	int		end;

	start = content(*a);
	middle = content((*a)->next);
	end = content((*a)->next->next);
	if (is_sorted(*a, 0))
		return ;
	else if (start < middle && middle > end && start < end)
		return (swap_a(*a), rotate_a(a));
	else if (middle < start && middle < end && end > start)
		return (swap_a(*a));
	else if (end < middle && end < start && middle > start)
		return (reverse_rotate_a(a));
	else if (middle < start && middle < end && end < start)
		return (reverse_rotate_a(a), reverse_rotate_a(a));
	else
		return (swap_a(*a), reverse_rotate_a(a));
}

/**
 * @brief
 * Wrapper for two
 */
static void	two_left_sort_a(t_list **a)
{
	if (!is_sorted(*a, 0))
		swap_a(*a);
}

void	selection_sort(t_list **a)
{
	t_list		*b;
	int			a_size;
	t_point		lowest;

	b = NULL;
	a_size = ft_lst_size(*a);
	while ((*a)->next != NULL)
	{
		if (a_size == 2)
		{
			two_left_sort_a(a);
			break ;
		}
		if (a_size-- == 3)
		{
			three_left_sort_a(a);
			break ;
		}
		lowest = get_lowest(*a, INT_MAX);
		rotate(a, lowest.index, lowest.value);
		push_b(a, &b);
		print_ab(*a, b, "Current");
	}
	while (b != NULL)
		push_a(a, &b);
}
