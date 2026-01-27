/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:12:41 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/27 20:22:27 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_sorted(t_list *node, int reverse)
{
	if (node == NULL || node->next == NULL)
		return (1);
	if (!reverse && *(int *)node->content > *(int *)(node->next->content))
		return (0);
	if (reverse && *(int *)node->content < *(int *)(node->next->content))
		return (0);
	return (is_sorted(node->next, reverse));
}

int	is_sorted_circular(t_list *lst)
{
	t_list	*lowest;
	t_list	*current;
	t_list	*next;

	if (lst == NULL || lst->next == NULL)
		return (1);
	lowest = lowest_node(lst, 0);
	current = lowest;
	while (1)
	{
		next = current->next;
		if (next == NULL)
			next = lst;
		if (next == lowest)
			return (1);
		if (content(current) > content(next))
			return (0);
		current = next;
	}
	return (1);
}
