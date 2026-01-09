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

#include "push_swap.h"

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

void	rotate(t_list **list, int index, int value_in_first)
{
	if (index > ft_lst_size(*list) / 2)
	{
		while (content(*list) != value_in_first)
			reverse_rotate_a(list);
	}
	else
	{
		while (content(*list) != value_in_first)
			rotate_a(list);
	}
}
