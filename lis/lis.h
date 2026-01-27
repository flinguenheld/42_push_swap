/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   lis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:06:11 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/27 14:06:12 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIS_H
# define LIS_H

# include "../push_swap.h"

/**
 * @brief
 */
typedef struct s_keeplist
{
	t_list	*list;
	char	status;
}	t_keeplist;

/**
 * @brief
 * Find the Longest Increasing Sequence of values in the list
 * Clone these values, skip the others and add them in a new list
 * @return
 * A brand new list with the lis
 */
t_list	*get_lis(t_list *list);

/**
 * @brief
 */
void	up_keep_list(t_stack *a, t_list *subseq, t_keeplist *keeplist);

/**
 * @brief
 */
void	only_keep_subsequence(t_stack *a, t_stack *b, t_list *subsequence,
			t_keeplist *keeplist);

#endif
