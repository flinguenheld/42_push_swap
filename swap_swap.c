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

int	content(t_list *node)
{
	return (*(int *)node->content);
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

void	replace_b(t_list **b)
{
	// Swap the two firsts
	while (content(*b) < content((*b)->next))
	{
		swap_b(*b);
	}
	// Rotate
	// Again until next < current

	// Reverse rotations

	
}


void	swap_swap(t_list **a, t_list **b, int blah)
{
	print_ab(*a, *b, "swap swap");
	if (is_sorteddddd(*a, 0) && *b == NULL)
		return;

	if (blah == 0)
	{
		if ((*a)->next == NULL)
		{
			swap_swap(a, b, 1);
			return;
		}
		else
		{
			if (content(*a) > content((*a)->next))
			{
				// if (*b != NULL && (*b)->next != NULL)
				// 	ft_printf("on b: %d  %d \n", content(*b), content((*b)->next));
				if (*b != NULL && (*b)->next != NULL
					&& content(*b) < content((*b)->next))
				{
					swap_ab(*a, *b);
				}
				else
				{
					swap_a(*a);
				}

				// HERE, TURN B TO PLACE THE NEW MEMBER !!!
				while (!is_sorteddddd(*b, 1))
				{
					print_ab(*a, *b, "rotate");
					reverse_rotate_b(b);
					
				}
			}
			else
			{
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
