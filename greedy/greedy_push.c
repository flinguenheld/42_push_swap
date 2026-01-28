/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   greedy_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:30:48 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/28 10:11:54 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greedy_push.h"

static void	two_side_rotation(t_stack *a, t_stack *b, t_greed greed)
{
	int	to_loop;

	to_loop = ft_min(greed.price_a.times, greed.price_b.times);
	while (to_loop--)
	{
		if (greed.price_a.reverse)
			reverse_rotate_ab(&a->start, &b->start);
		else
			rotate_ab(&a->start, &b->start);
	}
}

static void	one_side_rotation(t_stack *stack, int to_loop, char reverse)
{
	while (to_loop--)
	{
		if (reverse)
			reverse_rotate(&stack->start, stack->name);
		else
			rotate(&stack->start, stack->name);
	}
}

static void	greedy_rotation(t_stack *a, t_stack *b, t_greed	greed)
{
	if (greed.price_a.reverse == greed.price_b.reverse)
	{
		two_side_rotation(a, b, greed);
		if (greed.price_a.times > greed.price_b.times)
			one_side_rotation(a, ft_sub_abs(greed.price_a.times,
					greed.price_b.times), greed.price_a.reverse);
		else
			one_side_rotation(b, ft_sub_abs(greed.price_a.times,
					greed.price_b.times), greed.price_b.reverse);
	}
	else
	{
		one_side_rotation(a, greed.price_a.times, greed.price_a.reverse);
		one_side_rotation(b, greed.price_b.times, greed.price_b.reverse);
	}
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
		current = get_lowest_price(a, b, len_a, len_b);
		greedy_rotation(a, b, current);
		push(&b->start, &a->start, a->name);
		len_a++;
		len_b--;
	}
}
