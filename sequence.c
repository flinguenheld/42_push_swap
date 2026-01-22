/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:29:02 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/22 20:29:02 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Loop in the list and clone all nodes which are in order
 * -> 5 7 15 22 100 ...
 * -> 54 33 5 2 ...
 * @return
 * The list with cloned values
 */
static t_list	*get_sequence(t_list *list, char reverse)
{
	t_list	*ordered_values;

	ordered_values = NULL;
	while (list != NULL)
	{
		if (ordered_values == NULL
			|| (reverse && content(list) > content(ordered_values))
			|| (!reverse && content(list) < content(ordered_values)))
		{
			ft_lst_push_front(&ordered_values,
				ft_lst_new(new_content(content(list))));
		}
		list = list->next;
	}
	return (ordered_values);
}

/**
 * @brief
 * With the given list (which has been rotated),
 *  - get the current sequence
 *  - compare with the max and update if needed
 */
static void	get_n_compare(t_list *list, t_list **current_max, int reverse)
{
	t_list	*current;

	current = get_sequence(list, reverse);
	if (ft_lst_size(current) > ft_lst_size(*current_max))
	{
		ft_lst_clear(current_max, free);
		*current_max = current;
	}
	else
		ft_lst_clear(&current, free);
}

t_list	*longest_sequence(t_list *list)
{
	int		len;
	t_list	*current;
	t_list	*current_max;

	current_max = NULL;
	len = ft_lst_size(list);
	while (len--)
	{
		get_n_compare(list, &current_max, 0);
		get_n_compare(list, &current_max, 1);
		ft_lst_rotate_right(&list);
	}
	return (current_max);
}
