/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   greedy_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:30:48 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/27 20:29:10 by flinguen         ###   ########.fr       */
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
static int	price_rotation(t_stack *stack, int value, int stack_len)
{
	int	index;

	index = get_index(stack->start, value);
	if (index > stack_len / 2)
		return (stack_len - index);
	return (index);
}

/**
 * @brief
 * Calculate the cost of all value to be pushed in 'a'
 * @return
 * The cheapest
 */
static t_greed	current_lowest_price(t_stack *a, t_stack *b,
								int len_a, int len_b)
{
	t_greed	current;
	t_greed	lowest;
	t_list	*current_node;

	lowest.price = INT_MAX;
	current_node = b->start;
	while (current_node != NULL)
	{
		current.price = price_rotation(b, content(current_node), len_b);
		current.pivot = find_pivot(a->start, content(current_node));
		current.price += price_rotation(a, current.pivot, len_a);
		if (current.price < lowest.price)
		{
			lowest.value = content(current_node);
			lowest.price = current.price;
			lowest.pivot = current.pivot;
		}
		current_node = current_node->next;
	}
	// ft_printf("cheapest: value: %d, pivot: %d, price: %d\n", lowest.value, lowest.pivot, lowest.price);
	return (lowest);
}

void	greedy_push(t_stack *a, t_stack *b)
{
	t_greed	current;
	int		len_a;
	int		len_b;

	len_a = ft_lst_size(a->start);
	len_b = ft_lst_size(b->start);
	while (b->start != NULL)
	{
		current = current_lowest_price(a, b, len_a, len_b);
		rotate_shortest_way(b, get_index(b->start, current.value));
		rotate_shortest_way(a, get_index(a->start, current.pivot));
		push(&b->start, &a->start, a->name);
		len_a++;
		len_b--;
	}
}
