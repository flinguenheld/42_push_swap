/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:32:25 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/09 18:48:36 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

int	content(t_list *node)
{
	return (*(int *)node->content);
}

int	is_sorted(t_list *node, int reverse)
{
	if (node == NULL || node->next == NULL)
		return (1);
	if (!reverse && *(int *)node->content > *(int *)(node->next->content))
		return (0);
	if (reverse && *(int *)node->content < *(int *)(node->next->content))
		return (0);
	return (is_sorted(node->next, reverse));
}

t_point	get_lowest(t_list *list, int nb_nodes_max)
{
	int			index;
	t_list		*current_node;
	t_point		lowest_found;

	if (list == NULL)
		return ((t_point){.value = 0, .index = 0});
	index = 0;
	current_node = list;
	lowest_found = (t_point){.value = INT_MAX, .index = 0};
	while (current_node != NULL && index < nb_nodes_max)
	{
		if (content(current_node) <= lowest_found.value)
		{
			lowest_found.value = content(current_node);
			lowest_found.index = index;
		}
		current_node = current_node->next;
		index++;
	}
	return (lowest_found);
}

int	get_lowest_index(t_list *list, int nb_nodes_max)
{
	int			index;
	t_list		*current_node;
	int			lowest_value_index;
	int			lowest_value_found;

	index = 0;
	current_node = list;
	lowest_value_index = 0;
	lowest_value_found = INT_MAX;
	// while (current_node != NULL && index < nb_nodes_max)
	while (current_node != NULL && index < nb_nodes_max)
	{
		if (content(current_node) < lowest_value_found)
		{
			lowest_value_found = content(current_node);
			lowest_value_index = index;
		}
		current_node = current_node->next;
		index++;
	}
	ft_printf("Lowest value index found: %d   and the value -> %d \n", lowest_value_index, lowest_value_found);
	return (lowest_value_index);
}

// TODO SIMPLIFY THAT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// TODO SIMPLIFY THAT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void	rotate_shorter_side(t_list **list, char who, int index, int value_in_first)
{
	if (index > ft_lst_size(*list) / 2)
	{
		while (content(*list) != value_in_first)
			reverse_rotate(list, who);
	}
	else
	{
		while (content(*list) != value_in_first)
			rotate(list, who);
	}
}

void	rotate_shorter_side_NEW(t_list **list, char who, int index)
{
	int	size;

	size = ft_lst_size(*list);
	if (index > size / 2)
	{
		index = size - index;
		while(index--)
			reverse_rotate(list, who);
	}
	else
	{
		while (index--)
			rotate(list, who);
	}
}
