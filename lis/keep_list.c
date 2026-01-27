/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   keep_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:14:46 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/27 14:14:47 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lis.h"

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
void	up_keep_list(t_stack *a, t_list *subseq, t_keeplist *keeplist)
{
	t_list	*iter;
	t_list	*left;
	t_list	*right;

	iter = a->start;
	ft_lst_clear(&keeplist->list, free);
	left = get_next_subsequence_value(a->start, subseq);
	if (left != NULL)
	{
		right = get_next_subsequence_value(left->next, subseq);
		while (iter != left)
		{
			if (content(iter) > content(left)
				&& (right == NULL || content(iter) < content(right)))
			{
				ft_lst_push_front(&keeplist->list,
					ft_lst_new(new_content(content(iter))));
			}
			iter = iter->next;
		}
	}
	keeplist->status = 1;
}
