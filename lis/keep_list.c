/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   keep_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:14:46 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/28 07:51:53 by flinguen         ###   ########.fr       */
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
static t_list	*get_next_lis_value(t_list *list, t_list *subseq)
{
	while (list != NULL)
	{
		if (ft_lst_contains_key(subseq, list->content, are_equal))
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	up_keep_list(t_stack *a, t_list *subseq, t_lis_utils *utils)
{
	t_list	*iter;
	t_list	*left;
	t_list	*right;

	iter = a->start;
	ft_lst_clear(&utils->keeplist, free);
	left = get_next_lis_value(a->start, subseq);
	if (left != NULL)
	{
		right = get_next_lis_value(left->next, subseq);
		while (iter != left)
		{
			if (content(iter) > content(left)
				&& (right == NULL || content(iter) < content(right)))
			{
				ft_lst_push_front(&utils->keeplist,
					ft_lst_new(new_content(content(iter))));
			}
			iter = iter->next;
		}
	}
	utils->keeplist_status = 1;
}
