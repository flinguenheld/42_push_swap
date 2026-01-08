/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   lowest_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:57:27 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/07 23:02:34 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Get the positions of the two lowests values
 */
static t_lowests	get_lowest_position(t_list *a)
{
	int			i;
	int			lowest;
	t_list		*current_node;
	t_lowests	positions;

	i = 0;
	lowest = INT_MAX;
	current_node = a;
	positions.first = 0;
	positions.second = 0;
	while (current_node != NULL)
	{
		if (*(int *)current_node->content < lowest)
		{
			positions.second = positions.first;
			positions.first = i;
			lowest = *(int *)current_node->content;
		}
		current_node = current_node->next;
		i++;
	}
	return (positions);
}

void	selection_sort(t_list **a)
{
	t_list		*b;
	t_lowests	lowests;

	b = NULL;
	while ((*a)->next != NULL)
	{
		lowests = get_lowest_position(*a);
		if (lowests.first == 1 && lowests.second == 0)
			swap_a((*a));
		else if (lowests.first > ft_lst_size(*a) / 2)
		{
			lowests.first = ft_lst_size(*a) - lowests.first;
			while (lowests.first--)
				reverse_rotate_a(a);
		}
		else
			while (lowests.first--)
				rotate_a(a);
		if (ft_lst_size((*a)) == 2)
			break ;
		push_b(a, &b);
	}
	while (b != NULL)
		push_a(a, &b);
}
