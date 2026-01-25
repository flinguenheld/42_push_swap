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

/**
 * @brief
 * Find the first subsequence which is higher than 'value'
 * The subsequence has to be sorted
 * @return
 * The first node of the pair
 * NULL if the value is already higher than any subsequence value
 */
// t_list	*get_next_sub(t_list *subseq, int value)
// {
// 	while (subseq != NULL)
// 	{
// 		if (value > content(subseq)
// 			&& (subseq->next == NULL || value < content(subseq->next)))
// 			return (subseq);
// 		subseq = subseq->next;
// 	}
// 	return (NULL);
// }

t_list	*get_next_sub(t_list *list, t_list *subseq)
{
	while (list != NULL)
	{
		if (ft_lst_contains_key(subseq, list->content, are_equal))
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_list *list_values_to_keep(t_stack *a, t_list *subsequences)
{
	// Get the next pair
	t_list *iter;
	t_list *brand_new_list;
	t_list *left;
	t_list *right;

	iter = a->start;
	brand_new_list = NULL;
	left = get_next_sub(a->start, subsequences);
	if (left != NULL)
	{
		ft_printf("next pair is: %d\n", content(left));
		right = get_next_sub(left->next, subsequences);
		while (iter != left)
		{
			if (content(iter) > content(left)
				&& (right == NULL || content(iter) < content(right)))
			{
				ft_lst_push_front(&brand_new_list,
					ft_lst_new(new_content(content(iter))));
			}
			iter = iter->next;
		}
	}
	return (brand_new_list);
}

void	special_to_rename(t_stack *a, t_stack *b, t_list *subsequence, t_list *to_keep)
{
	

}

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
	t_list *values_to_keep;
	values_to_keep = NULL;
	// Rotate the stack as long as it's not sorted
	while (!is_sorted_tolerance(a->start, 1))
	{

		while (values_to_keep != NULL)
		{
			if (!ft_lst_contains_key(subsequence, a->start, are_equal)
			&& !ft_lst_contains_key(values_to_keep, a->start, are_equal))
			{
				push(&a->start, &b->start, b->name);
			}

		}
		
		if (!ft_lst_contains_key(subsequence, a->start->content, &are_equal))
		{
			// Get the next pair
			// Now loop util the next pair
			// Create a new list with the values that can be in the pair
			// And move to this pair
			// Then empty the list by putting them in the order
			values_to_keep = list_values_to_keep(a, subsequence);
			if (values_to_keep != NULL)
			{
				ft_printf("values to keep !!\n");
				print_list(values_to_keep, " | ");
			}
			else
			{
				ft_printf("nothing to keep\n");
			}

			ft_lst_clear(&values_to_keep, free);

			// push_or_swap(a, b, subsequence);
			push(&a->start, &b->start, b->name);
		}
		else
		{
			rotate(&a->start, a->name);
		}
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
