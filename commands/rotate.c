/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:10:40 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 21:42:25 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int	rotate(t_list **start, char *to_print)
{
	if (*start != NULL)
	{
		ft_lst_rotate_left(start);
		ft_printf(to_print);
		return (1);
	}
	return (0);
}

void	rotate_a(t_list **a)
{
	rotate(a, "ra\n");
}

void	rotate_b(t_list **b)
{
	rotate(b, "rb\n");
}

void	rotate_ab(t_list **a, t_list **b)
{
	if (rotate(a, "") || rotate(b, ""))
		ft_printf("rr\n");
}
