/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:31 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/17 11:33:38 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "commands/commands.h"
# include "libft/libft.h"
# include "limits.h"

/**
 * @brief
 * Associate a list with its name
 */
typedef struct s_stack
{
	t_list	*start;
	char	name;
}	t_stack;

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
void	selection_sort(t_stack *from, t_stack *to);
/**
 * @brief
 * Same as selection sort but only on 0 to range values
 * (preserve the stack below)
 */
void	selection_sort_range(t_stack *from, t_stack *to, size_t amount);

// ----------------------------------------------------------------------------
// ------------------------------------------------------------- GROUP SORT ---
/**
 * @brief
 * Group
 */
void	group_sort(t_stack *from, t_stack *to, int group_size);

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
void	rotate_shorter_side(t_stack *from, t_stack *to, int index, void *previous);

/**
 * @brief
 * Rotate the given stack up to having the 'index' at the top
 * Take care of the shortest way to do that (rotate or reverse rotate)
 */
void	rotate_shortest_way(t_stack *stack, int index_to);

// ----------------------------------------------------------------------------
// ------------------------------------------------------------- UTILS LIST ---
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
 * Check if the list is sorted
 * @return
 * 1 if true
 */
int		is_sorted(t_list *node, int reverse);


/**
 * @brief
 * Check if the given list is sorted but allow a 'tolerance'
 * Check can continue if the next value is higher as long as tolerance > 0
 */
int		is_sorted_tolerance(t_list *node, char tolerance);


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
