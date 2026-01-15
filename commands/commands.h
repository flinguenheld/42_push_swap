/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:11:46 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 21:42:25 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../libft/libft.h"

// ----------------------------------------------------------------------------
// ------------------------------------------------------------------- SWAP ---
/**
 * @brief
 * Swap the two first nodes at the top of the given list and print "to_print"
 * Do nothing if there is less than two nodes.
 */
int		swap(t_list *start, char to_print);

/**
 * @brief
 * Launch swap a & swap b
 * Print "ss" if at least one swap was effective
 */
void	swap_ab(t_list *a, t_list *b);

// ----------------------------------------------------------------------------
// ------------------------------------------------------------------- PUSH ---
/**
 * @brief
 * Take the first element at the top of 'from' and put it at the top of 'to'.
 * And print 's' + 'to_print' + '\n';
 * Do nothing if 'from' is empty
 */
void	push(t_list **from, t_list **to, char to_print);

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------- ROTATE ---
/**
 * @brief
 * Shift up all elements of the given list by one.
 * And print 'r' + 'to_print' + '\n';
 * The first element becomes the last one.
 * Do nothing if a is empty
 */
int		rotate(t_list **start, char to_print);

/**
 * @brief
 * Launch rotate a & rotate b
 * Print "rr" if at least one rotate was effective
 */
void	rotate_ab(t_list **a, t_list **b);

// ----------------------------------------------------------------------------
// --------------------------------------------------------- REVERSE_ROTATE ---
/**
 * @brief
 * Shift down all elements of the given list by one.
 * And print 'rr' + 'to_print' + '\n';
 * The last element becomes the first one.
 * Do nothing if a is empty
 */
int		reverse_rotate(t_list **start, char to_print);

/**
 * @brief
 * Launch reverse_rotate a & reverse_rotate b
 * Print "rrr" if at least one reverse_rotate was effective
 */
void	reverse_rotate_ab(t_list **a, t_list **b);

#endif
