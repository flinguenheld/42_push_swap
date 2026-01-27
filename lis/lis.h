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
 * Regroup the keeplist and its status
 * (the status allows only_keep_lis to avoid calculations)
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
 * Clear and fill the keeplist
 * The values to keep are values which can be put in the next subsequence pair
 * So:
 *   - get the next subequence pair (left & right)
 *   - loop in the stack until the 'left'
 *       - save values which can fit in the pair
 */
void	up_keep_list(t_stack *a, t_list *subseq, t_keeplist *keeplist);

/**
 * @brief
 * Push all values from a to b which are not in the 'lis' and also keep
 * those which are not but close to the next 'lis' value.
 * Diagram: https://github.com/flinguenheld/42_push_swap
 */
void	only_keep_lis(t_stack *a, t_stack *b, t_list *lis,
			t_keeplist *keeplist);

#endif
