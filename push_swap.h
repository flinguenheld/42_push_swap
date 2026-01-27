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


void patrick(t_stack *a, t_stack *b);

void	only_keep_subsequence_blah(t_stack *a, t_stack *b, t_list *subsequence, t_list **keeplist);

void	only_keep_subsequence(t_stack *a, t_stack *b, t_list *subsequence, t_list **keeplist, char keeplist_status);


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
 * Loop in the list to find the lowest value stored
 * @return
 * The lowest node pointer
 */t_list	*lowest_node(t_list *lst);

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
int	is_sorted_circular(t_list *lst);

// TODO REMOVE THAT !!!!!!!!
// TODO REMOVE THAT !!!!!!!!
// TODO REMOVE THAT !!!!!!!!
/**
 * @brief
 * Check if the given list is sorted but allow a 'tolerance'
 * Check can continue if the next value is higher as long as tolerance > 0
 */
int		is_sorted_tolerance(t_list *node, char tolerance);

// ----------------------------------------------------------------------------
// --------------------------------------------------------------- SEQUENCE ---

/**
 * @brief
 * Find the longest sequence of values in the list
 * Clone these values, skip the other and add them in a new list
 * @return
 * A brand new list with the sequence
 */
t_list	*longest_sequence(t_list *list);

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

/**
 * @brief
 * Print the list and add the separator between each values
 */
void print_list(t_list *list, char *separator);

#endif
