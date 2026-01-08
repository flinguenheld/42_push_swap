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

#include "commands/commands.h"
#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

static int	get_lowest(t_list *a, int exclude, int nb_nodes)
{
	int			index;
	int			lowest;
	t_list		*current_node;
	int			position;

	index = 0;
	position = 0;
	lowest = INT_MAX;
	current_node = a;
	while (current_node != NULL && index < nb_nodes)
	{
		if (index != exclude && *(int *)current_node->content <= lowest)
		{
			lowest = *(int *)current_node->content;
			position = index;
		}
		current_node = current_node->next;
		index++;
	}
	return (position);
}
/**
 * @brief
 * Get the positions of the two lowests values
 */
static t_lowests	get_lowest_position(t_list *a)
{
	t_lowests	positions;

	positions.first = get_lowest(a, -1, INT_MAX);
	positions.second = get_lowest(a, positions.first, INT_MAX);
	return (positions);
}

static void	three(t_list **a)
{
	t_lowests	lowests;

	lowests = get_lowest_position(*a);
	// ft_printf("lowest: %d %d\n", lowests.first, lowests.second);

	if (lowests.first == 0 && lowests.second == 1)
	{
	}
	else if (lowests.first == 0 && lowests.second == 2)
	{
		swap_a(*a);
		rotate_a(a);
	}
	else if (lowests.first == 1 && lowests.second == 0)
	{
		swap_a(*a);
	}
	else if (lowests.first == 1 && lowests.second == 2)
	{
		rotate_a(a);
	}
	else if (lowests.first == 2 && lowests.second == 0)
	{
		swap_a(*a);
		rotate_a(a);
	}
	else
	{
		rotate_a(a);
	}
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
		if (ft_lst_size((*a)) == 3)
		{
			three(a);
			break;
		}
		if (ft_lst_size((*a)) == 2)
			break ;
		push_b(a, &b);
		print_ab(*a, b, "Current");
	}
	while (b != NULL)
		push_a(a, &b);
}

int		is_sorted(t_list *a, int amount)
{
	int		index;
	t_list	*node;

	node = a;
	while (amount-- > 1)
	{
		if (node == NULL || node->next == NULL)
			return (0);
		if (*(int *)node->content > *(int *)(node->next->content))
			return (0);
		else
			node = node->next;
	}
	return (1);
}

void	swap_push_only_sort(t_list **a, t_list **b, int amount)
{
	int	done;

	done = 0;
	while (done < amount)
	{
		if (*(int *)(*a)->content > *(int *)(*b)->content)
		{
			swap_a(*a);
		}
		push_b(a, b);

		// if (*(int *)(*a)->content == amount)
	}
}


