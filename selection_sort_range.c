/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   selection_sort_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:57:27 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/15 21:47:24 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_temp_values(t_list *list, size_t amount)
{
	t_list	*temp_list;
	t_list	*current_node;

	temp_list = NULL;
	current_node = list;
	while (amount-- && current_node != NULL)
	{
		ft_lst_push_front(&temp_list,
			ft_lst_new(new_content(content(current_node))));
		current_node = current_node->next;
	}
	return (temp_list);
}

/**
 * @brief
 * Create a temporary list with all values form 0 to amount
 * Then in a loop until temp list size != 1
 *  - get the lowest value in the temp
 *  - find it in the real list
 *  - rotate to put first
 *  - push to the second list
 *
 * Then put the last value at the top of the first list
 */
static void	push_in_the_second(t_stack *from, t_stack *to, size_t amount)
{
	int			lowest_to_push;
	t_list		*temp_list;
	t_list		*temp_node;

	temp_list = get_temp_values(from->start, amount);
	while (temp_list->next != NULL)
	{
		lowest_to_push = get_lowest_index(temp_list, INT_MAX);
		rotate_shorter_side(&temp_list, '\0', lowest_to_push);
		temp_node = ft_lst_pop_front(&temp_list);
		lowest_to_push = get_index(from->start, content(temp_node));
		ft_lst_clear_basic(&temp_node);
		rotate_shorter_side(&from->start, from->name, lowest_to_push);
		push(&from->start, &to->start, to->name);
	}
	lowest_to_push = get_index(from->start, content(temp_list));
	rotate_shorter_side(&from->start, from->name, lowest_to_push);
	ft_lst_clear_basic(&temp_list);
}

void	selection_sort_range(t_stack *from, t_stack *to, size_t amount)
{
	push_in_the_second(from, to, amount);
	while (amount--)
	{
		push(&to->start, &from->start, from->name);
	}
}
