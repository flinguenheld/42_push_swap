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

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

/**
 * @brief
 * Malloc a int and set it to one
 */
static void	*init_one(void)
{
	int	*content;

	content = malloc(sizeof(int));
	*content = 1;
	return (content);
}

/**
 * @brief
 * From the given list and the lis values, extract one of the subsequences.
 * (list and lis have to have the same size)
 *   - Get the maximum lis
 *   - Then get the maximum lis - 1 until the end of the list
 *
 * Empties lis and set it to NULL
 * @return
 * A brand new list with the longest increasing subsequence
 */
static t_list	*extract_subsequence(t_list **list, t_list **lis)
{
	t_list	*values;
	t_list	*current_lis;
	int		current_lis_value;

	values = NULL;
	current_lis_value = get_highest_point(*lis, INT_MAX, NULL).value;
	while (*lis != NULL)
	{
		current_lis = ft_lst_pop_back(lis);
		ft_lst_rotate_right(list);
		if (content(current_lis) == current_lis_value)
		{
			ft_lst_push_front(&values, ft_lst_new(new_content(content(*list))));
			current_lis_value--;
		}
		ft_lst_clear(&current_lis, free);
	}
	return (values);
}

/**
 * @brief
 * Loop from the start to the *_node_to_reach to update its value
 *
 * Then for each couple of values (list & list):
 *    Add one to the 'lis_to_reach' if
 *       - current checked value is lower than the to_reach one
 *       - lis value is equal or higher than the lis to reach
 */
static void	up_lis_value(t_list *list, t_list *list_node_to_reach,
						t_list *lis, t_list *lis_node_to_reach)
{
	while (lis != lis_node_to_reach)
	{
		if (content(list_node_to_reach) > content(list)
			// && content(lis) == content(lis_node_to_reach))
			&& content(lis) >= content(lis_node_to_reach))
			(*(int *)lis_node_to_reach->content) += 1;
		lis = lis->next;
		list = list->next;
	}
}

/**
 * @brief
 * Find the longest increasing subsequence (lis) in list
 * Performs that with the dynamic programming algorithm
 *
 *   - Init another list named 'lis' and set all values to one
 *   - Loop both in the list & the list
 *   - For each value set the 'lis' value corresponding
 *       -> this lis value is the longest subsequence possible
 *
 * Once all lis values are set, extract one subsequence in a
 * new list and return it.
 * @return
 * A new list with the longest subsequence
 */
static t_list	*longest_increasing_subsequence(t_list *list)
{
	t_list	*list_iter;
	t_list	*result;
	t_list	*lis_iter;
	t_list	*lis;

	lis = ft_lst_init(ft_lst_size(list), &init_one);
	lis_iter = lis;
	result = NULL;
	list_iter = list;
	while (lis_iter != NULL)
	{
		up_lis_value(list, list_iter, lis, lis_iter);
		lis_iter = lis_iter->next;
		list_iter = list_iter->next;
	}
	print_ab(list, lis, "LIS");
	result = extract_subsequence(&list, &lis);
	return (result);
}

/**
 * @brief
 * Apply the longest increasing subsequence on the list
 * Rotate the list entirely (dry run, do not print actions) to apply the lis
 * on all possibilites
 * @return
 * A new list with the longest subsequence
 */
t_list	*longest_sequence(t_list *list)
{
	int		len;
	t_list	*temp;
	int		temp_len;
	t_list	*subsequence;
	int		subsequence_len;

	subsequence = NULL;
	subsequence_len = 0;
	len = ft_lst_size(list);
	while (len--)
	{
		print_ab(list, subsequence, "we rotate");
		temp = longest_increasing_subsequence(list);
		temp_len = ft_lst_size(temp);
		if (temp_len > subsequence_len)
		{
			ft_lst_clear(&subsequence, free);
			subsequence = temp;
			subsequence_len = temp_len;
		}
		ft_lst_rotate_right(&list);
	}
	return (subsequence);
}
