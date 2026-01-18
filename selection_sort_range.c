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


// /**
//  * @brief
//  * Clone the 'amount' first values from list in a brand new stack
//  * @return
//  * A stack filled of amount values
//  */
// static t_stack	clone_current_values(t_list *list, size_t amount)
// {
// 	t_stack	temp_stack;
// 	t_list	*current_node;

// 	temp_stack = (t_stack){.start = NULL, .name = '\0'};
// 	current_node = list;
// 	while (amount-- && current_node != NULL)
// 	{
// 		ft_lst_push_front(&temp_stack.start,
// 			ft_lst_new(new_content(content(current_node))));
// 		current_node = current_node->next;
// 	}
// 	return (temp_stack);
// }

/**
 * @brief
 * Get the lowest value in temp
 * Remove it
 * @return
 * The lowest value or the highest if reverse
 */
static t_point	pop_lowest_from_temp(t_stack *temp, char reverse)
{
	t_point		popped_point;

	if (reverse)
		popped_point = get_highest_point(temp->start, INT_MAX, NULL);
	else
		popped_point = get_lowest_point(temp->start, INT_MAX, NULL);
	ft_lst_remove_if(&temp->start, &popped_point.value, are_equal, free);
	return (popped_point);
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
	t_point		to_push;
	t_list		*temp_stack;
	t_list		*temp_node;
	int			amount_pushed;
	int			index;

	amount_pushed = 0;
	// temp_stack = clone_current_values(from->start, amount);
	temp_stack = get_only_values_to_sort(from, amount);
	print_ab(temp_stack, NULL, "Values to sort");

	return 0;
	// while (temp_stack->next != NULL && temp_stack->next->next != NULL)
	while (amount >= 2)
	{
		// to_push = pop_lowest_from_temp(&temp_stack, 1);
		temp_node = ft_lst_pop_back(&temp_stack);
		index = get_index(from->start, content(temp_node));
		ft_lst_delone(temp_node, free);

		rotate_shorter_side(&from->start, from->name, index);

		push(&from->start, &to->start, to->name);
		print_ab(from->start, to->start, "current");
		print_ab(temp_stack, NULL, "popped");

		amount_pushed++;
		amount--;
	}

	ft_lst_clear(&temp_stack, free);

	// to_push.value = get_index(from->start, content(temp_stack.start));
	// rotate_shorter_side(&from->start, from->name, to_push.value);
	// ft_lst_clear(&temp_stack.start, free);

	return (amount_pushed);
}

static int	nth_value(t_list *list, int index)
{
	while (list != NULL)
	{
		if (index == 0)
			return (content(list));
		list = list->next;
		index--;
	}
	return (-1);
}

void	selection_sort_range(t_stack *from, t_stack *to,
								size_t amount, int reverse)
{
	int	nb_to_get_back;

	// Save the third value
	// int antepenultimate;

	// antepenultimate = nth_value(from->start, amount - 3);
	// ft_printf("antepenultimate %d\n", antepenultimate);
	nb_to_get_back = push_values_in_the_second_stack_in_order(
			from, to, amount, reverse);

	// while (nb_to_get_back--)
	// 	push(&to->start, &from->start, from->name);
}
