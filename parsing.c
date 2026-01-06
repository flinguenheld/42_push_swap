/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:31 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 21:06:33 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	contains(void *a, void *b)
{
	return (a != NULL && b != NULL && *(int *)a == *(int *)b);
}

/**
 * @brief
 * Convert str into an int and push it at the end of 'a'
 * Except if:
 * - str is not a digit
 * - str overflowesint limits
 * - 'a' already contains str
 * @return
 * 1 if ok
 */
int	check_and_push_argv(t_list **a, char *str)
{
	int	*new_value;

	if (ft_is_integer(str))
	{
		new_value = malloc(sizeof(int));
		if (new_value != NULL)
		{
			*new_value = ft_atoi(str);
			if (*new_value != ft_atol(str)
				|| ft_lst_contains_key(*a, new_value, contains))
			{
				free(new_value);
				return (0);
			}
			ft_lst_push_back(a, ft_lst_new(new_value));
			return (1);
		}
	}
	return (0);
}
