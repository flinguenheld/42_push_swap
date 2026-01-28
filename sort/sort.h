/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 07:54:05 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/28 10:11:53 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../push_swap.h"
# include "../commands/commands.h"
# include "../utils/utils.h"

// ----------------------------------------------------------------------------
// -------------------------------------------------------- GREEDY LIS SORT ---

/**
 * @brief
 * Sort discovered thanks to Patrick in 3 steps
 *   - Get longest Increasing Subsequence
 *   - Push values in B and only keep lis values in the stack A
 *        Optimisation
 *           - With keeplist to try to increase the lis
 *           - With a median to separate values in two parts in the stack B
 *   - Push back all values in A with a greed alorithm
 *           - Before each action, compute all possibilites to do the cheapest
 */
void	greedy_lis_sort(t_stack *a, t_stack *b);

// ----------------------------------------------------------------------------
// --------------------------------------------------------- SELECTION SORT ---

/**
 * @brief
 * Selection sort O(n²)
 * Great with a small amount of data
 */
void	selection_sort(t_stack *from, t_stack *to);
/**
 * @brief
 * Same as selection sort but only on 0 to range values
 * (preserve the stack below)
 */
void	selection_sort_range(t_stack *from, t_stack *to,
			size_t range, char reverse);

// ----------------------------------------------------------------------------
// ------------------------------------------------------------- GROUP SORT ---

/**
 * @brief
 * Group
 */
void	group_sort(t_stack *from, t_stack *to, int group_size);

#endif
