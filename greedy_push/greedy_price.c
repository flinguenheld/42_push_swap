/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   greedy_price.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 01:12:49 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/28 01:25:28 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greedy_push.h"

/**
 * @brief
 * Find the value on 'a' which should be on the top for the given value in b
 * @return
 * The pivot in a
 */
static int	find_pivot(t_list *start, int value)
{
	int		lower;
	int		higher;
	t_list	*current;
	t_list	*next;

	lower = content(lowest_node(start, 0));
	higher = content(lowest_node(start, 1));
	if (value < lower || value > higher)
		return (lower);
	current = start;
	while (1)
	{
		next = current->next;
		if (next == NULL)
			next = start;
		if (content(current) != higher
			&& content(current) < value && content(next) > value)
			break ;
		current = next;
	}
	return (content(next));
}

/**
 * @brief
 * You want to rotate?
 * Here the price
 * @return
 * The amount of commands needed (r or rr)
 */
static t_price	price_rotation(t_stack *stack, int value, int stack_len)
{
	int	index;

	index = get_index(stack->start, value);
	if (index > stack_len / 2)
		return ((t_price){.times = stack_len - index, .reverse = 1});
	return ((t_price){.times = index, .reverse = 0});
}

/**
 * @brief
 * Get the total cost according to rotation types
 */
static int	total(t_greed blah)
{
	if (blah.price_a.reverse == blah.price_b.reverse)
		return (ft_max(blah.price_a.times, blah.price_b.times));
	return (blah.price_a.times + blah.price_b.times);
}

t_greed	get_lowest_price(t_stack *a, t_stack *b, int len_a, int len_b)
{
	t_greed	current;
	t_greed	lowest;
	t_list	*current_node;
	int		lowest_price;

	lowest_price = INT_MAX;
	current_node = b->start;
	while (current_node != NULL)
	{
		current.price_b = price_rotation(b, content(current_node), len_b);
		current.price_a = price_rotation(a,
				find_pivot(a->start, content(current_node)), len_a);
		if (total(current) < lowest_price)
		{
			lowest.price_b = current.price_b;
			lowest.price_a = current.price_a;
			lowest_price = total(current);
		}
		current_node = current_node->next;
	}
	return (lowest);
}
