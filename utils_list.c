/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:20:32 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/17 11:33:39 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	content(t_list *node)
{
	return (*(int *)node->content);
}

int	*new_content(int value)
{
	int	*new_content;

	new_content = malloc(sizeof(int));
	*new_content = value;
	return (new_content);
}

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

int	is_sorted_tolerance(t_list *node, char tolerance)
{
	if (node == NULL || node->next == NULL)
		return (1);
	if (*(int *)node->content > *(int *)(node->next->content))
	{
		if (tolerance == 0)
			return (0);
		tolerance--;
	}
	return (is_sorted(node->next, tolerance));
}
