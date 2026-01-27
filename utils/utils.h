/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:06:11 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/27 16:19:56 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../push_swap.h"

// ----------------------------------------------------------------------------
// ------------------------------------------------------------------ UTILS ---

/**
 * @brief
 * Cast a & b in int to compare them
 * @return
 * 1 if they are equal
 */
int		are_equal(void *a, void *b);

/**
 * @brief
 * Find the lowest value in the given range and return its index/value
 * You can give a list to ignore values
 * @return
 * A point with index/value
 * A point with index = -1 not enough values
 */
t_point	get_lowest_point(t_list *list, int nb_nodes_max, t_list *to_ignore);

/**
 * @brief
 * Find the highest value in the given range and return its index/value
 * You can give a list to ignore values
 * @return
 * A point with index/value
 * A point with index = -1 not enough values
 */
t_point	get_highest_point(t_list *list, int nb_nodes_max, t_list *to_ignore);

/**
 * @brief
 * Find the value 'to_find' in the list and return its index
 * @return
 * The index or -1 if not found
 */
int		get_index(t_list *list, int to_find);

/**
 * @brief
 * Rotate the given list with 'index' rotations
 * (According to the value of index and list length, use reverse rotation)
 */
// void	rotate_shorter_side(t_list **list, char who, int index);
void	rotate_shorter_side(t_stack *from, t_stack *to,
			int index, void *previous);

/**
 * @brief
 * Rotate the given stack up to having the 'index' at the top
 * Take care of the shortest way to do that (rotate or reverse rotate)
 */
void	rotate_shortest_way(t_stack *stack, int index_to);

// ----------------------------------------------------------------------------
// ------------------------------------------------------------------- LIST ---

/**
 * @brief
 * Wrapper to cast the node contend
 * The node cannot be NULL
 */
int		content(t_list *node);
/**
 * @brief
 * Malloc and set a int to value;
 */
int		*new_content(int value);

/**
 * @brief
 * Loop in the list to find the lowest value stored
 * @return
 * The lowest node pointer
 */
t_list	*lowest_node(t_list *lst);

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------- SORTED ---

/**
 * @brief
 * Check if the list is sorted
 * @return
 * 1 if true
 */
int		is_sorted(t_list *node, int reverse);

/**
 * @brief
 * Check if the given list is sorted
 * The lower value does not need to be the first one
 * For example, all of these lists are sorted:
 *     15 16 0 2 4 10 3
 *     15 16 3 1
 *     5 6
 *     6 5
 * @return
 * 1 if the list is sorted
 */
int		is_sorted_circular(t_list *lst);

#endif
