/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   only_keep_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:06:11 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/28 10:11:54 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lis.h"

static void	rot_swap_push(t_stack *a, t_stack *b, t_lis_utils *utils)
{
	if (ft_lst_contains_key(utils->keeplist, a->start->content, are_equal))
	{
		if (ft_lst_contains_key(utils->keeplist, a->start->next->content,
				are_equal))
			rotate(&a->start, a->name);
		else
			swap(a->start, a->name);
	}
	else
	{
		push(&a->start, &b->start, b->name);
		if (b->start != NULL && content(b->start) > utils->median)
			rotate(&b->start, b->name);
	}
}

static void	rot_sort(t_stack *a, t_stack *b, int to_loop, int to_sort)
{
	while (to_loop--)
		reverse_rotate(&a->start, a->name);
	selection_sort_range(a, b, to_sort, 1);
}

static void	rot_clear(t_stack *a, t_lis_utils *utils, int to_loop)
{
	while (to_loop--)
		rotate(&a->start, a->name);
	ft_lst_clear(&utils->keeplist, free);
	utils->keeplist_status = 0;
}

void	only_keep_lis(t_stack *a, t_stack *b, t_list *lis, t_lis_utils *utils)
{
	int	keeplist_len;

	if (is_sorted_circular(a->start) == 1)
		return ;
	keeplist_len = ft_lst_size(utils->keeplist);
	if (ft_lst_contains_key(lis, a->start->content, are_equal))
	{
		if (keeplist_len == 0)
			rotate(&a->start, a->name);
		else
		{
			if (keeplist_len > 1)
				rot_sort(a, b, keeplist_len - 1, keeplist_len + 1);
			if (is_sorted_circular(a->start))
				return ;
			rot_clear(a, utils, keeplist_len + 1);
		}
		return (only_keep_lis(a, b, lis, utils));
	}
	if (utils->keeplist_status == 0)
		up_keep_list(a, lis, utils);
	else
		rot_swap_push(a, b, utils);
	only_keep_lis(a, b, lis, utils);
}
