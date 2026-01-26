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

t_list	*lowest_node(t_list *lst)
{
	t_list	*lowest;

	lowest = lst;
	while (lst != NULL)
	{
		if (content(lst) < content(lowest))
			lowest = lst;
		lst = lst->next;
	}
	return (lowest);
}

int	is_sorted_circular(t_list *lst)
{
	t_list	*lowest;
	t_list	*current;
	t_list	*next;

	if (lst == NULL || lst->next == NULL)
		return (1);
	lowest = lowest_node(lst);
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
