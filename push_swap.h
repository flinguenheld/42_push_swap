/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:31 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/09 19:03:59 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "commands/commands.h"
# include "limits.h"

/**
 * @brief
 * Allow you to store a node value with its index in the list
 */
typedef struct s_point
{
	int	value;
	int	index;
}	t_point;

// ----------------------------------------------------------------------------
// --------------------------------------------------------- SELECTION SORT ---
/**
 * @brief
 * Selection sort O(n²)
 * Great with a small amount of data
 */
void	selection_sort(t_list **a);

// ----------------------------------------------------------------------------
// ------------------------------------------------------------------ UTILS ---
/**
 * @brief
 * Wrapper to cast the node contend
 * The node cannot be NULL
 */
int		content(t_list *node);

/**
 * @brief
 * Check if the list is sorted
 * @return
 * 1 if true
 */
int		is_sorted(t_list *node, int reverse);

/**
 * @brief
 * Find the lowest value and return its index and the value itself
 * @return
 * The lowest or {0, 0}
 */
t_point	get_lowest(t_list *list, int nb_nodes_max);

/**
 * @brief
 * Put the value in first by using rotation.
 * According to the value of index and list length, use reverse rotation.
 */
void	rotate(t_list **list, int index, int value_in_first);

// ----------------------------------------------------------------------------
// ---------------------------------------------------------------- PARSING ---
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
int		check_and_push_argv(t_list **a, char *str);

// ----------------------------------------------------------------------------
// ------------------------------------------------------------------ PRINT ---
/**
 * @brief
 * Print a beautiful table with all values
 */
void	print_ab(t_list *a, t_list *b, char *title);

#endif
