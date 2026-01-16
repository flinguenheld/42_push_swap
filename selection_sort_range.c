/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   selection_sort_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:57:27 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/16 23:03:54 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

/**
 * @brief
 * Clone the 'amount' first values from list in a brand new stack
 * @return
 * A stack filled of amount values
 */
static t_stack	clone_current_values(t_list *list, size_t amount)
{
	t_stack	temp_stack;
	t_list	*current_node;

	temp_stack = (t_stack){.start = NULL, .name = '\0'};
	current_node = list;
	while (amount-- && current_node != NULL)
	{
		ft_lst_push_front(&temp_stack.start,
			ft_lst_new(new_content(content(current_node))));
		current_node = current_node->next;
	}
	return (temp_stack);
}

/**
 * @brief
 * Get the lowest value in temp
 * Remove it
 * @return
 * The lowest value or the highest if reverse
 */
static int	pop_lowest(t_stack *temp, char reverse)
{
	t_list		*popped_node;
	int			popped_value;
	int			popped_index;

	if (reverse)
		popped_index = get_highest_index(temp->start, INT_MAX);
	else
		popped_index = get_lowest_index(temp->start, INT_MAX);
	rotate_shorter_side(&temp->start, temp->name, popped_index);
	popped_node = ft_lst_pop_front(&temp->start);
	popped_value = content(popped_node);
	ft_lst_clear_basic(&popped_node);
	return (popped_value);
}

/**
 * @brief
 * Create a temporary stack with all values form index 0 to amount
 * Then in a loop until temp list size != 1
 *  - get the lowest value in the temp
 *  - find it in the real list
 *  - rotate to put first
 *  - push to the second list
 *
 * Then put the last value at the top of the first list
 * @return
 * Amount of pushed values
 */
static int	push_values_in_the_second_stack_in_order(t_stack *from,
					t_stack *to, size_t amount, int reverse)
{
	int			value_to_push;
	int			index_to_push;
	t_stack		temp_stack;
	t_list		*temp_node;
	int			amount_pushed;

	amount_pushed = 0;
	temp_stack = clone_current_values(from->start, amount);
	while (temp_stack.start->next != NULL)
	{
		value_to_push = pop_lowest(&temp_stack, 1);
		index_to_push = get_index(from->start, value_to_push);
		rotate_shorter_side(&from->start, from->name, index_to_push);
		push(&from->start, &to->start, to->name);
		amount_pushed++;
	}
	value_to_push = get_index(from->start, content(temp_stack.start));
	rotate_shorter_side(&from->start, from->name, value_to_push);
	ft_lst_clear_basic(&temp_stack.start);
	return (amount_pushed);
}

void	selection_sort_range(t_stack *from, t_stack *to,
								size_t amount, int reverse)
{
	int	nb_to_get_back;

	nb_to_get_back = push_values_in_the_second_stack_in_order(
			from, to, amount, reverse);
	while (nb_to_get_back--)
		push(&to->start, &from->start, from->name);
}
