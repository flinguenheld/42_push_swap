/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   group_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:57:04 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/17 11:33:39 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands/commands.h"
#include "libft/libft.h"
#include "push_swap.h"

static int	push_all_values_lower_than(t_stack *from, t_stack *to, int pivot)
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
	print_ab(from->start, to->start, "push all values lower");
	return (0);
}

static int	compare_value(void *a, void *b)
{
	return (*(int *)a == *(int *)b);
}

/**
 * @brief
 * Loop in the stack to fill 'values' with the lowest values
 * @return
 * The amount of added values
 */
int	next_pivot(t_stack *stack, int amount)
{
	t_stack	values;
	int		values_len;
	int		stack_len;
	
	values_len = 0;
	stack_len = ft_lst_size(stack->start);
	values = (t_stack){.start = NULL, .name = '\0'};
	while (amount-- && values_len < stack_len)
	{
		// Get the lowest value in stack which is not already in values


	}


	return 0;
}

void	group_sort(t_stack *from, t_stack *to)
{
	// Find a value to split

	int	pivot;
	int	amount_pushed;

	pivot = 10;

	while (1)
	{
		// Push in b all values which are higher than the pivot
		amount_pushed = push_all_values_lower_than(from,to, pivot);
		if (to->start != NULL)
			pivot = content(to->start) + 10;
		else
			exit(1000);

		ft_printf("PIVOT: %d -------------------------------------\n", pivot);

		// print_ab(from->start, to->start, "current");
		// Sort b in the range and in reverse side
		selection_sort_range(to, from, 10, 1);

		if (ft_lst_size(from->start) <= 3)
		{
			print_ab(from->start, to->start, "before last sort");
			// selection_sort(from, to);
			return;
		}

		// If a length is lower than the pivot
				// Sort a
				// Empty b in a
	}
}
