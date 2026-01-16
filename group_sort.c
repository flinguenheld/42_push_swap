/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   group_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:57:04 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/16 23:03:54 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands/commands.h"
#include "libft/libft.h"
#include "push_swap.h"

static int	loop_and_push_to(t_stack *from, t_stack *to, int pivot)
{
	int	len;
	int	amount;

	// possibly do not do the last rotation ?
	amount = 0;
	len = ft_lst_size(from->start) + 1;
	while (len--)
	{
		if (content(from->start) <= pivot)
		{
			push(&from->start, &to->start, to->name);
			amount++;
		}
		rotate(&from->start, from->name);
	}
	// print_ab(from->start, to->start, "loop and push to done");
	return (0);
}

void	group_sort(t_stack *from, t_stack *to)
{
	// Find a value to split

	int	pivot;
	int	amount_pushed;

	pivot = 8;

	while (1)
	{
		// Push in b all values which are higher than the pivot
		amount_pushed = loop_and_push_to(from,to, pivot);
		if (to->start != NULL)
			pivot = content(to->start) + 8;
		else
			exit(1000);

		ft_printf("PIVOT: %d -------------------------------------\n", pivot);

		// print_ab(from->start, to->start, "current");
		// Sort b in the range and in reverse side
		selection_sort_range(to, from, 10, 1);

		if (ft_lst_size(from->start) <= 10)
		{
			// print_ab(from->start, to->start, "amount sorted");
			selection_sort(from, to);
			return;
		}

		// If a length is lower than the pivot
				// Sort a
				// Empty b in a
	}
}
