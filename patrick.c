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

void	blah(t_stack *a, t_stack *b, t_list *subsequence, t_list *keeplist)
{
	
}

void	only_keep_subsequence(t_stack *a, t_stack *b, t_list *subsequence, t_list *keeplist, char keeplist_status)
{
	int	keeplist_len;
	int	to_loop;

	ft_printf("here we are to analyse %d\n", content(a->start));
	print_ab(a->start, b->start, "in progress");
	print_list(subsequence, " ");

	keeplist_len = ft_lst_size(keeplist);
	if (ft_lst_contains_key(subsequence, a->start->content, are_equal))
	{
		ft_printf("Yep it is in subsequence\n");
		if (keeplist_len == 0)
			rotate(&a->start, a->name);
		else
		{
			if (keeplist_len > 1)
			{
				to_loop = keeplist_len - 1;
				while (to_loop--)
					reverse_rotate(&a->start, a->name);
				selection_sort_range(a, b, keeplist_len + 1);
			}
			if (is_sorted_tolerance(a->start, 1))
				return ;
			to_loop = keeplist_len + 1;
			while (to_loop--)
				rotate(&a->start, a->name);
			ft_lst_clear(&keeplist, free);
		}
		return only_keep_subsequence(a, b, subsequence, keeplist, 0);
	}

	if (keeplist_status == 0)
	{
		keeplist = list_values_to_keep(a, subsequence);
	}
	else
	{
		if (ft_lst_contains_key(keeplist, a->start->content, are_equal))
		{
			if (ft_lst_contains_key(keeplist, a->start->next->content, are_equal))
			{
				rotate(&a->start, a->name);
			}
			else
			{
				swap(a->start, a->name);
			}
			
		}
		else
			push(&a->start, &b->start, b->name);
	}
	only_keep_subsequence(a, b, subsequence, keeplist, 1);
}


void	patrick(t_stack *a, t_stack *b)
{
	t_list	*sub;
	t_list	*keeplist;

	sub = longest_sequence(a->start);
	print_ab(sub, NULL, "LONGEST SUB");
	ft_printf("size %d-------------------------------------------------------\n", ft_lst_size(sub));
	// print_ab(a->start, b->start, "is it ok ?");

	only_keep_subsequence(a, b, sub, keeplist, 0);
	print_ab(a->start, b->start, "PUSH DONE");

	ft_lst_clear(&sub, free);
}
