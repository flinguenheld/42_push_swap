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
int	swap(t_list *start, char *to_print);

/**
 * @brief
 * Swap the two first nodes at the top of the stack a and print "sa"
 * Do nothing if there is only one node or node.
 */
void	swap_a(t_list *a);

/**
 * @brief
 * Swap the two first nodes at the top of the stack b and print "sb"
 * Do nothing if there is only one node or node.
 */
void	swap_b(t_list *b);

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
 * And print the message;
 * Do nothing if 'from' is empty
 */
void	push(t_list **from, t_list **to, char *to_print);

/**
 * @brief
 * Take the first element at the top of b and put it at the top of a.
 * And print "pa"
 * Do nothing if b is empty
 */
void	push_a(t_list **a, t_list **b);

/**
 * @brief
 * Take the first element at the top of a and put it at the top of b.
 * And print "pb"
 * Do nothing if a is empty
 */
void	push_b(t_list **a, t_list **b);

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------- ROTATE ---

/**
 * @brief
 * Shift up all elements of the given list by one and print "to_print".
 * The first element becomes the last one.
 * Do nothing if a is empty
 */
int	rotate(t_list **start, char *to_print);

/**
 * @brief
 * Shift up all elements of list a by one and print "ra".
 * The first element becomes the last one.
 * Do nothing if a is empty
 */
void	rotate_a(t_list **a);

/**
 * @brief
 * Shift up all elements of list b by one and print "rb".
 * The first element becomes the last one.
 * Do nothing if b is empty
 */
void	rotate_b(t_list **b);

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
 * Shift down all elements of the given list by one and print "to_print".
 * The last element becomes the first one.
 * Do nothing if a is empty
 */
int	reverse_rotate(t_list **start, char *to_print);

/**
 * @brief
 * Shift down all elements of list a by one and print "rra".
 * The last element becomes the first one.
 * Do nothing if a is empty
 */
void	reverse_rotate_a(t_list **a);

/**
 * @brief
 * Shift down all elements of list b by one and print "rrb".
 * The last element becomes the first one.
 * Do nothing if a is empty
 */
void	reverse_rotate_b(t_list **b);

/**
 * @brief
 * Launch reverse_rotate a & reverse_rotate b
 * Print "rrr" if at least one reverse_rotate was effective
 */
void	reverse_rotate_ab(t_list **a, t_list **b);

#endif
