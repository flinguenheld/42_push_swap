/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   greedy_push.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:21:57 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/27 20:22:27 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../utils/utils.h"
#include "../commands/commands.h"

/**
 * @brief
 * Everything you need to act as McScrooge
 */
typedef struct s_greed
{
	int	value;
	int	pivot;
	int	price;
}	t_greed;

/**
 * @brief
 * Push entirely b in a
 * For each new value in b, find the cheapest, rotate b, rotate a then push
 */
void	greedy_push(t_stack *a, t_stack *b);
