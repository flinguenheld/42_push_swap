/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:10:40 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 21:42:25 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int	swap(t_list *start, char *to_print)
{
	if (start != NULL && start->next != NULL)
	{
		ft_lst_swap_content(start, start->next);
		ft_printf(to_print);
		return (1);
	}
	return (0);
}

void	swap_a(t_list *a)
{
	swap(a, "sa\n");
}

void	swap_b(t_list *b)
{
	swap(b, "sb\n");
}

void	swap_ab(t_list *a, t_list *b)
{
	int	done;

	done = swap(a, "");
	done += swap(b, "");
	if (done)
		ft_printf("ss\n");
}
