/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   selection_sort_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:57:27 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/17 11:33:38 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Create a new list and does 'amount' times:
 *   - Take the lowest value from stack which is not in the new list
 *   - Clone this value in the new list
 * @return
 * A list with the next values to deal with
 */
static t_list	*get_only_values_to_sort(t_stack *stack, int amount)
{
	int		stack_len;
	t_point	lowest_found;
	t_list	*values_gotten;
	int		values_gotten_len;

	values_gotten = NULL;
	values_gotten_len = 0;
	stack_len = ft_lst_size(stack->start);
	while (amount > 0 && values_gotten_len <= stack_len)
	{
		lowest_found = get_lowest_point(stack->start, amount, values_gotten);
		ft_lst_push_front(&values_gotten,
			ft_lst_new(new_content(lowest_found.value)));
		values_gotten_len++;
		amount--;
	}
	return (values_gotten);
}

static void	pop_back_temp_and_rotate(t_stack *stack, t_list *temp_stack,
									int reverse)
{
	t_list	*temp_node;
	int		index;

	if (reverse)
		temp_node = ft_lst_pop_back(&temp_stack);
	else
		temp_node = ft_lst_pop_front(&temp_stack);
	index = get_index(stack->start, content(temp_node));
	ft_lst_delone(temp_node, free);
	rotate_shorter_side(&stack->start, stack->name, index);
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
	t_list		*temp;
	int			amount_pushed;

	amount_pushed = 0;
	temp = get_only_values_to_sort(from, amount);
	while (temp->next != NULL)
	{
		pop_back_temp_and_rotate(from, temp, reverse);
		push(&from->start, &to->start, to->name);
		amount_pushed++;
	}
	pop_back_temp_and_rotate(from, temp, reverse);
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
