/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:10:40 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 21:42:25 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void	push(t_list **from, t_list **to, char *to_print)
{
	if (*from != NULL)
	{
		ft_lst_push_front(to, ft_lst_pop_front(from));
		ft_printf(to_print);
	}
}

void	push_a(t_list **a, t_list **b)
{
	push(b, a, "pa\n");
}

void	push_b(t_list **a, t_list **b)
{
	push(a, b, "pb\n");
}
