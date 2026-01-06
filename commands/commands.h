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
 * Launch swap_a & swap_b
 */
void	swap_ab(t_list *a, t_list *b);

// ----------------------------------------------------------------------------
// ------------------------------------------------------------------- PUSH ---
/**
 * @brief
 * Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty
 */
void	push_a(t_list **a, t_list **b);

/**
 * @brief
 * Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty
 */
void	push_b(t_list **a, t_list **b);

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------- ROTATE ---
/**
 * @brief
 * Shift up all elements of list a by one.
 * The first element becomes the last one.
 */
void	rotate_a(t_list **a);

/**
 * @brief
 * Shift up all elements of list b by one.
 * The first element becomes the last one.
 */
void	rotate_b(t_list **b);

/**
 * @brief
 * Launch rotate_a & rotate_b
 */
void	rotate_ab(t_list **a, t_list **b);

// ----------------------------------------------------------------------------
// --------------------------------------------------------- REVERSE_ROTATE ---
/**
 * @brief
 * Shift down all elements of list a by one.
 * The last element becomes the first one.
 */
void	reverse_rotate_a(t_list **a);

/**
 * @brief
 * Shift down all elements of list b by one.
 * The last element becomes the first one.
 */
void	reverse_rotate_b(t_list **b);

/**
 * @brief
 * Launch reverse_rotate_a & reverse_rotate_b
 */
void	reverse_rotate_ab(t_list **a, t_list **b);

#endif
