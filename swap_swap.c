/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:36:49 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/08 16:36:49 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "commands/commands.h"
#include "commands/commands.h"
#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

int	content(t_list *node)
{
	return (*(int *)node->content);
}

static int	get_highest_position(t_list *b)
{
	int			index;
	int			highest;
	int			position;
	t_list		*current_node;

	index = 0;
	position = 0;
	highest = INT_MIN;
	current_node = b;
	while (current_node != NULL)
	{
		if (content(current_node) >= highest)
		{
			highest = content(current_node);
			position = index;
		}
		current_node = current_node->next;
		index++;
	}
	return (position);
}

static int	get_turn_position(t_list *b, int to)
{
	int			index;
	int			highest;
	int			position;
	t_list		*current_node;

	index = 0;
	position = 0;
	highest = INT_MIN;
	current_node = b;
	while (current_node != NULL && content(current_node) > to)
	{
		position = index;
		current_node = current_node->next;
		index++;
	}
	return (position);
}

int	is_sorteddddd(t_list *node, int reverse)
{
	if (node == NULL || node->next == NULL)
		return (1);
	if (!reverse && *(int *)node->content > *(int *)(node->next->content))
		return (0);
	if (reverse && *(int *)node->content < *(int *)(node->next->content))
		return (0);
	return (is_sorteddddd(node->next, reverse));
}

void	prepare_b(t_list **b, int to)
{
	// if (*b == NULL)
	// 	return;
	// while (content(*b) > to)
	// 	rotate_b(b);

	int	size;
	int	position;

	if (*b == NULL)
		return;
	position = get_turn_position(*b, to);
	if (position > size / 2)
	{
		position = size - position;
		while (position-- > 0)
			reverse_rotate_b(b);
	}
	else
	{
		while (position-- > 0)
			rotate_b(b);
	}
}

void	turn_turn_b(t_list **b)
{
	int	size;
	int	highest_postion;

	if (*b == NULL || (*b)->next == NULL)
		return;
	size = ft_lst_size(*b);
	highest_postion = get_highest_position(*b);

	if (highest_postion > size / 2)
	{
		highest_postion = size - highest_postion;
		while (highest_postion--)
			reverse_rotate_b(b);
	}
	else
	{
		while (highest_postion--)
			rotate_b(b);
	}
}



void	swap_swap(t_list **a, t_list **b, int blah)
{
	// print_ab(*a, *b, "swap swap");
	if (is_sorteddddd(*a, 0) && *b == NULL)
		return;

	if (blah == 0)
	{
		if ((*a)->next == NULL)
		{

			turn_turn_b(b);
			// print_ab(*a, *b, "Ready to fill the other side");
			swap_swap(a, b, 1);
			return;
		}
		else
		{
			if (content(*a) > content((*a)->next))
			{
				// if (*b != NULL && (*b)->next != NULL)
				// 	ft_printf("on b: %d  %d \n", content(*b), content((*b)->next));
				// if (*b != NULL && (*b)->next != NULL
				// 	&& content(*b) < content((*b)->next))
				// {
				// 	swap_ab(*a, *b);
				// }
				// else
				// {
					swap_a(*a);
				// }

				// HERE, TURN B TO PLACE THE NEW MEMBER !!!
				// while (!is_sorteddddd(*b, 1))
				// {
				// 	print_ab(*a, *b, "rotate");
				// 	reverse_rotate_b(b);
					
				// }
			}
			else
			{
				prepare_b(b, content(*a));
				push_b(a, b);
			}
		}
		swap_swap(a, b, blah);
	}
	else
	{
		if (*b != NULL && (*b)->next != NULL
			&& content(*b) < content((*b)->next))
		{
			swap_b(*b);
		}else
		{
			push_a(a, b);
			
		}
		swap_swap(a, b, blah);
	}
}
