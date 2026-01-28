/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   greedy_push.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:21:57 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/28 10:11:54 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GREEDY_PUSH_H
# define GREEDY_PUSH_H

# include "../push_swap.h"
# include "../utils/utils.h"
# include "../commands/commands.h"

/**
 * @brief
 * Times to rotate & direction
 */
typedef struct s_price
{
	int		times;
	char	reverse;
}	t_price;

/**
 * @brief
 * Regroup price a & b
 */
typedef struct s_greed
{
	t_price	price_a;
	t_price	price_b;
}	t_greed;

/**
 * @brief
 * Push entirely b in a
 * For each new value in b, find the cheapest, rotate b, rotate a then push
 */
void	greedy_push(t_stack *a, t_stack *b);

/**
 * @brief
 * Calculate and compare the cost for all values in 'a' to be pushed in 'b'
 * Rotations can be in both sides and simultaneously
 * @return
 * The cheapest
 */
t_greed	get_lowest_price(t_stack *a, t_stack *b, int len_a, int len_b);

#endif
