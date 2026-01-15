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

#include "commands/commands.h"
#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * @brief
 * Specific case when only three values left in 'list'
 *    1 1    2 2    3 3
 *    2 3    1 3    1 2
 *    3 2    3 1    2 1
 */
static int	three_left_sort(t_list **list, char who)
{
	int		start;
	int		middle;
	int		end;

	start = content(*list);
	middle = content((*list)->next);
	end = content((*list)->next->next);
	if (is_sorted(*list, 0))
		return (0);
	else if (start < middle && middle > end && start < end)
		return (swap(*list, who), rotate(list, who));
	else if (middle < start && middle < end && end > start)
		return (swap(*list, who));
	else if (end < middle && end < start && middle > start)
		return (reverse_rotate(list, who));
	else if (middle < start && middle < end && end < start)
		return (reverse_rotate(list, who), reverse_rotate(list, who));
	else
		return (swap(*list, who), reverse_rotate(list, who));
}

/**
 * @brief
 * Wrapper for two
 */
static void	two_left_sort(t_list **list, char who)
{
	if (!is_sorted(*list, 0))
		swap(*list, who);
}

// PUT THAT IN UTILS ???????????????????????????????????
static int	*new_content(int v)
{
	int *blah = malloc(sizeof(int));
	*blah = v;
	return blah;
}

static t_list	*get_temp_values(t_list *list, size_t amount)
{
	t_list	*temp_list;
	t_list	*current_node;

	temp_list = NULL;
	current_node = list;
	while (amount-- && current_node != NULL)
	{
		ft_printf("add this value: %d\n", content(current_node));
		ft_lst_push_front(&temp_list, ft_lst_new(new_content(content(current_node))));
		current_node = current_node->next;
	}
	return (temp_list);
}

int	get_position(t_list *list, int to_find)
{
	int			index;
	t_list		*current_node;

	index = 0;
	current_node = list;
	while (current_node != NULL)
	{
		if (content(current_node) == to_find)
			return (index);
		current_node = current_node->next;
		index++;
	}
	return (-1);
}

void	first_part(t_list **list, t_list **temp_list, char who, char temp, size_t amount)
{
	int			real_amount;
	int			a_size;
	int			amount_in_temp;
	int			lowest;
	int			value_after;
	t_list		*temp_only_values_to_sort;
	t_list		*temp_node;

	// GET ALL VALUES IN ANOTHER TEMP LIST
	temp_only_values_to_sort = get_temp_values(*list, amount);
		ft_printf("------------------------------------------------------ %d\n", ft_lst_size(temp_only_values_to_sort));
	while (temp_only_values_to_sort != NULL)
	{
		// Remove the lowest value from blablah
		lowest = get_lowest_index(temp_only_values_to_sort, INT_MAX);
		ft_printf("lowest: %d\n", lowest);
		rotate_shorter_side_NEW(&temp_only_values_to_sort, '\0', lowest);
		temp_node = ft_lst_pop_front(&temp_only_values_to_sort);

		// Push the lowest value from temp_list to list
		ft_printf("deal with this value: %d\n", content(temp_node));
		lowest = get_position(*list, content(temp_node));
		ft_lst_clear_basic(&temp_node);
		ft_printf("lowest position in the real list: %d\n", lowest);
		rotate_shorter_side_NEW(list, who, lowest);
		push(list, temp_list, who);
	}
	// Use the shortcut with three to sort

	// Get back all values

}

void	selection_sort(t_list **list, t_list **temp_list, char who, char temp, size_t amount)
{
	int			real_amount;
	int			a_size;
	int			amount_in_temp;
	int			lowest;
	int			value_after;
	t_list		*blah_blah;

	// GET ALL VALUES IN ANOTHER TEMP LIST
	first_part(list, temp_list, who, temp, amount);

	while (amount--)
	{
		push(temp_list, list, 'b');
	}

}
