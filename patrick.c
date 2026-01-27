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
 * Loop in list and check if the current list value is contained in subseq
 * @return
 * The first node found
 * NULL is not found
 */
static t_list	*get_next_subsequence_value(t_list *list, t_list *subseq)
{
	while (list != NULL)
	{
		if (ft_lst_contains_key(subseq, list->content, are_equal))
			return (list);
		list = list->next;
	}
	return (NULL);
}

/**
 * @brief
 * Clear and fill the keeplist
 * The values to keep are values which can be put in the next subsequence pair
 * So:
 *   - get the next subequence pair (left & right)
 *   - loop in the stack until the 'left'
 *       - save values which can fit in the pair
 */
static void	list_values_to_keep(t_stack *a, t_list *subseq, t_list **keeplist)
{
	t_list	*iter;
	t_list	*left;
	t_list	*right;

	iter = a->start;
	ft_lst_clear(keeplist, free);
	left = get_next_subsequence_value(a->start, subseq);
	if (left != NULL)
	{
		right = get_next_subsequence_value(left->next, subseq);
		while (iter != left)
		{
			if (content(iter) > content(left)
				&& (right == NULL || content(iter) < content(right)))
			{
				ft_lst_push_front(keeplist,
					ft_lst_new(new_content(content(iter))));
			}
			iter = iter->next;
		}
	}
}

static void	rot_swap_push(t_stack *a, t_stack *b, t_list **keeplist)
{
	if (ft_lst_contains_key(*keeplist, a->start->content, are_equal))
	{
		if (ft_lst_contains_key(*keeplist, a->start->next->content, are_equal))
			rotate(&a->start, a->name);
		else
			swap(a->start, a->name);
	}
	else
		push(&a->start, &b->start, b->name);
}

static void rot_sort(t_stack *a, t_stack *b, int to_loop, int to_sort)
{
	while (to_loop--)
		reverse_rotate(&a->start, a->name);
	selection_sort_range(a, b, to_sort, 1);
}

static void rot_clear(t_stack *a, t_list **keeplist, int to_loop)
{
	// to_loop = keeplist_len + 1;
	while (to_loop--)
		rotate(&a->start, a->name);
	ft_lst_clear(keeplist, free);
}

void	only_keep_subsequence(t_stack *a, t_stack *b, t_list *subsequence, t_list **keeplist, char keeplist_status)
{
	int	keeplist_len;

	if (is_sorted_circular(a->start) == 1)
		return ;
	keeplist_len = ft_lst_size(*keeplist);
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
		return only_keep_subsequence(a, b, subsequence, keeplist, 0);
	}
	if (keeplist_status == 0)
		list_values_to_keep(a, subsequence, keeplist);
	else
		rot_swap_push(a, b, keeplist);
	only_keep_subsequence(a, b, subsequence, keeplist, 1);
}


void	patrick(t_stack *a, t_stack *b)
{
	t_list	*sub;
	t_list	*keeplist;

	keeplist = NULL;
	sub = longest_sequence(a->start);
	print_ab(sub, NULL, "LONGEST SUB");
	// ft_printf("size %d-------------------------------------------------------\n", ft_lst_size(sub));
	// print_ab(a->start, b->start, "is it ok ?");

	only_keep_subsequence(a, b, sub, &keeplist, 0);
	print_ab(a->start, b->start, "PUSH DONE");
	ft_lst_clear(&keeplist, free);

	ft_lst_clear(&sub, free);
}
