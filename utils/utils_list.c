/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:20:32 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/27 20:22:27 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	are_equal(void *a, void *b)
{
	return (a != NULL && b != NULL && *(int *)a == *(int *)b);
}

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

t_list	*lowest_node(t_list *lst, char reverse)
{
	t_list	*lowest;

	lowest = lst;
	while (lst != NULL)
	{
		if (!reverse && content(lst) < content(lowest))
			lowest = lst;
		else if (reverse && content(lst) > content(lowest))
			lowest = lst;
		lst = lst->next;
	}
	return (lowest);
}
