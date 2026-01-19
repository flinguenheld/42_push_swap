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

#include "commands/commands.h"
#include "libft/libft.h"
#include "push_swap.h"

/**
 * @brief
 * Create a new list and does 'amount' times:
 *   - Take the lowest value from stack which is not in the new list
 *   - Clone this value in the new list
 * @return
 * A list with the next values to deal with
 */
static t_list	*get_group(t_stack *stack, int group_size)
{
	int		stack_len;
	t_point	lowest_fnd;
	t_list	*values_gotten;
	int		values_gotten_len;

	stack_len = ft_lst_size(stack->start);
	values_gotten = NULL;
	values_gotten_len = 0;
	while (values_gotten_len < group_size && values_gotten_len < stack_len)
	{
		lowest_fnd = get_lowest_point(stack->start, group_size, values_gotten);
		if (lowest_fnd.index >= 0)
		{
			ft_lst_push_front(&values_gotten,
				ft_lst_new(new_content(lowest_fnd.value)));
		}
		values_gotten_len++;
	}
	return (values_gotten);
}

/**
 * @brief
 * Empties the group one by one
 * Get the index of the popped group value in the stack from
 * Smartly rotate the stack
 * Push the value into the second stack
 * Stops until the pantenultimate value
 * Free the last group value
 * @return
 * The number of pushed values
 */
static int	push_group(t_stack *from, t_stack *to, t_list **group)
{
	int		index;
	int		counter;
	t_list	*current_node;

	counter = 0;
	while (*group != NULL)
	{
		current_node = ft_lst_pop_front(group);
		index = get_index(from->start, content(current_node));
		rotate_shortest_way(from, index);
		if (*group != NULL)
		{
			push(&from->start, &to->start, to->name);
			counter++;
		}
		ft_lst_clear(&current_node, free);
	}
	return (counter);
}

/**
 * @brief
 * Steps:
 *    - Clone the values in a temporary list and in order (high to low)
 *    - Until the group list is empty:
 *            - Pop front
 *            - Push the value in the other list
 *    - Once there only one left, push back values
 */
void	selection_sort_range(t_stack *from, t_stack *to, size_t range)
{
	t_list	*group;
	int		nb_pushed_values;

	group = get_group(from, range);
	print_ab(from->start, to->start, "sort in range - group");
	print_ab(NULL, group, "group to sort");
	nb_pushed_values = push_group(from, to, &group);
	print_ab(from->start, to->start, "sort in range");
	while (nb_pushed_values--)
		push(&to->start, &from->start, from->name);
}
