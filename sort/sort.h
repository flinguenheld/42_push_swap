/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 07:54:05 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/28 07:56:23 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../push_swap.h"
# include "../commands/commands.h"
# include "../utils/utils.h"

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
