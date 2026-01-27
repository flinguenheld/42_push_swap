/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:32:25 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/27 16:13:39 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_point	get_lowest_point(t_list *list, int nb_nodes_max, t_list *to_ignore)
{
	int			index;
	t_point		lowest_point;
	t_list		*current_node;

	index = 0;
	current_node = list;
	lowest_point = (t_point){.index = -1, .value = INT_MAX};
	while (current_node != NULL && index < nb_nodes_max)
	{
		if (content(current_node) < lowest_point.value
			&& ft_lst_contains_key(to_ignore,
				current_node->content, are_equal) == 0)
		{
			lowest_point.value = content(current_node);
			lowest_point.index = index;
		}
		current_node = current_node->next;
		index++;
	}
	return (lowest_point);
}

t_point	get_highest_point(t_list *list, int nb_nodes_max, t_list *to_ignore)
{
	int			index;
	t_point		highest_point;
	t_list		*current_node;

	index = 0;
	current_node = list;
	highest_point = (t_point){.index = -1, .value = INT_MIN};
	while (current_node != NULL && index <= nb_nodes_max)
	{
		if (content(current_node) > highest_point.value
			&& !ft_lst_contains_key(to_ignore,
				current_node->content, are_equal))
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

void	rotate_shorter_side(t_stack *from, t_stack *to,
			int index, void *previous)
{
	int	size;
	int	previous_pushed;

	previous_pushed = 0;
	size = ft_lst_size(from->start);
	if (index > size / 2)
	{
		index = size - index;
		while (index--)
		{
			if (are_equal(previous, from->start->content) == 1)
				push(&from->start, &to->start, to->name);
			reverse_rotate(&from->start, from->name);
		}
	}
	else
	{
		while (index--)
		{
			if (are_equal(previous, from->start->content) == 1)
				push(&from->start, &to->start, to->name);
			else
				rotate(&from->start, from->name);
		}
	}
}

void	rotate_shortest_way(t_stack *stack, int index_to)
{
	int	size;
	int	previous_pushed;

	previous_pushed = 0;
	size = ft_lst_size(stack->start);
	if (index_to > size / 2)
	{
		index_to = size - index_to;
		while (index_to--)
			reverse_rotate(&stack->start, stack->name);
	}
	else
	{
		while (index_to--)
			rotate(&stack->start, stack->name);
	}
}
