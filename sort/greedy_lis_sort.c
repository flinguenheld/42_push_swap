/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   greedy_lis_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:38:22 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/28 07:56:23 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lis/lis.h"
#include "../greedy/greedy_push.h"

/**
 * @brief
 * Loop in the list to get the lowest value which is higher than 'min'
 */
static int	get_lowest(t_list *iter, int min)
{
	int	current;

	current = INT_MAX;
	while (iter != NULL)
	{
		if (content(iter) < current && content(iter) > min)
			current = content(iter);
		iter = iter->next;
	}
	return (current);
}

/**
 * @brief
 * Find the value which is in the middle of the list
 */
static int	get_median(t_list *lst)
{
	int		len;
	int		to_loop;
	int		current;

	current = INT_MIN;
	len = ft_lst_size(lst);
	to_loop = len / 2;
	while (to_loop--)
		current = get_lowest(lst, current);
	return (current);
}

void	greedy_lis(t_stack *a, t_stack *b)
{
	t_list		*lis;
	t_lis_utils	utils;

	utils = (t_lis_utils){.keeplist = NULL,
		.keeplist_status = 0,
		.median = get_median(a->start)};
	lis = get_lis(a->start);
	only_keep_lis(a, b, lis, &utils);
	ft_lst_clear(&utils.keeplist, free);
	ft_lst_clear(&lis, free);
	greedy_push(a, b);
	rotate_shortest_way(a, get_index(a->start,
			content(lowest_node(a->start, 0))));
}
