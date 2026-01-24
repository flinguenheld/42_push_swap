/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   patrick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:38:22 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/22 16:38:23 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands/commands.h"
#include "libft/libft.h"
#include "push_swap.h"

// Rotate the stack as long as it's not sorted


void	only_keep_subsequence(t_stack *a, t_stack *b, t_list *subsequence)
{
	// --- Look a the first node
	// --- Is it in the subsequence ?
	// ---   Yes -> rotate
	// ---   No -> get the price to swap it ?
	//          -> push b
	// --- Rotate
	// --- Is list sorted ?
	// --- Clear subsequence

	while (!is_sorted_tolerance(a->start, 1))
	{
		if (!ft_lst_contains_key(subsequence, a->start->content, &are_equal))
		{
			push(&a->start, &b->start, b->name);
		}
		rotate(&a->start, a->name);
	}
	
}


void	patrick(t_stack *a, t_stack *b)
{
	t_list	*sub;

	sub = longest_sequence(a->start);
	print_ab(sub, NULL, "LONGEST SUB");
	ft_printf("size %d-------------------------------------------------------\n", ft_lst_size(sub));
	// print_ab(a->start, b->start, "is it ok ?");

	only_keep_subsequence(a, b, sub);
	print_ab(a->start, b->start, "PUSH DONE");

	ft_lst_clear(&sub, free);
}
