/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:10:40 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 21:42:25 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void	reverse_rotate(t_list **start, char *to_print)
{
	if (*start != NULL)
	{
		ft_lst_rotate_right(start);
		ft_printf(to_print);
	}
}

void	reverse_rotate_a(t_list **a)
{
	reverse_rotate(a, "rra\n");
}

void	reverse_rotate_b(t_list **b)
{
	reverse_rotate(b, "rrb\n");
}

void	reverse_rotate_ab(t_list **a, t_list **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}
