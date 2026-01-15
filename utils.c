/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:32:25 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/15 21:47:24 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (lowest_value_index);
}

int	get_highest_index(t_list *list, int nb_nodes_max)
{
	int			index;
	t_list		*current_node;
	int			highest_value_index;
	int			highest_value_found;

	index = 0;
	current_node = list;
	highest_value_index = 0;
	highest_value_found = INT_MIN;
	while (current_node != NULL && index < nb_nodes_max)
	{
		if (content(current_node) > highest_value_found)
		{
			highest_value_found = content(current_node);
			highest_value_index = index;
		}
		current_node = current_node->next;
		index++;
	}
	return (highest_value_index);
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
		while(index--)
			reverse_rotate(list, who);
	}
	else
	{
		while (index--)
			rotate(list, who);
	}
}
