/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   only_keep_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:06:11 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/27 14:06:12 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lis.h"

static void	rot_swap_push(t_stack *a, t_stack *b, t_keeplist *keeplist)
{
	if (ft_lst_contains_key(keeplist->list, a->start->content, are_equal))
	{
		if (ft_lst_contains_key(keeplist->list, a->start->next->content,
				are_equal))
			rotate(&a->start, a->name);
		else
			swap(a->start, a->name);
	}
	else
		push(&a->start, &b->start, b->name);
}

static void	rot_sort(t_stack *a, t_stack *b, int to_loop, int to_sort)
{
	while (to_loop--)
		reverse_rotate(&a->start, a->name);
	selection_sort_range(a, b, to_sort, 1);
}

static void	rot_clear(t_stack *a, t_keeplist *keeplist, int to_loop)
{
	while (to_loop--)
		rotate(&a->start, a->name);
	ft_lst_clear(&keeplist->list, free);
	keeplist->status = 1;
}

void	only_keep_subsequence(t_stack *a, t_stack *b, t_list *subsequence,
						t_keeplist *keeplist)
{
	int	keeplist_len;

	if (is_sorted_circular(a->start) == 1)
		return ;
	keeplist_len = ft_lst_size(keeplist->list);
	if (ft_lst_contains_key(subsequence, a->start->content, are_equal))
	{
		if (keeplist_len == 0)
			rotate(&a->start, a->name);
		else
		{
			if (keeplist_len > 1)
				rot_sort(a, b, keeplist_len - 1, keeplist_len + 1);
			if (is_sorted_circular(a->start))
				return ;
			rot_clear(a, keeplist, keeplist_len + 1);
		}
		return (only_keep_subsequence(a, b, subsequence, keeplist));
	}
	if (keeplist->status == 0)
		up_keep_list(a, subsequence, keeplist);
	else
		rot_swap_push(a, b, keeplist);
	only_keep_subsequence(a, b, subsequence, keeplist);
}
