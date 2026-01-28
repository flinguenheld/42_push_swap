/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:31 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/28 07:51:50 by flinguen         ###   ########.fr       */
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
void	greedy_lis(t_stack *a, t_stack *b);

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
