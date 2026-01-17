/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:32:25 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/17 11:33:38 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_point	get_lowest_point(t_list *list, int nb_nodes_max)
{
	int			index;
	t_point		lowest_point;
	t_list		*current_node;

	index = 0;
	current_node = list;
	lowest_point = (t_point){.index = 0, .value = INT_MAX};
	while (current_node != NULL && index < nb_nodes_max)
	{
		if (content(current_node) < lowest_point.value)
		{
			lowest_point.value = content(current_node);
			lowest_point.index = index;
		}
		current_node = current_node->next;
		index++;
	}
	return (lowest_point);
}

t_point	get_highest_point(t_list *list, int nb_nodes_max)
{
	int			index;
	t_point		highest_point;
	t_list		*current_node;

	index = 0;
	current_node = list;
	highest_point = (t_point){.index = 0, .value = INT_MIN};
	while (current_node != NULL && index < nb_nodes_max)
	{
		if (content(current_node) > highest_point.value)
		{
			highest_point.value = content(current_node);
			highest_point.index = index;
		}
		current_node = current_node->next;
		index++;
	}
	return (highest_point);
}

int	get_index(t_list *list, int to_find)
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

void	rotate_shorter_side(t_list **list, char who, int index)
{
	int	size;

	size = ft_lst_size(*list);
	if (index > size / 2)
	{
		index = size - index;
		while (index--)
			reverse_rotate(list, who);
	}
	else
	{
		while (index--)
			rotate(list, who);
	}
}
