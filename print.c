/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:34:30 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/07 19:46:07 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	print_one_line(t_list **a, t_list **b)
{
	int	still_one;

	still_one = 0;
	if (*a != NULL)
	{
		ft_printf(" % 10d |", *(int *)(*a)->content);
		*a = (*a)->next;
		still_one = 1;
	}
	else
		ft_printf("            |");
	if (*b != NULL)
	{
		ft_printf(" % 10d |", *(int *)(*b)->content);
		*b = (*b)->next;
		still_one = 1;
	}
	else
		ft_printf("            |");
	return (still_one);
}

void	print_ab(t_list *a, t_list *b, char *before, char *after)
{
	ft_printf(before);
	ft_printf("    a       |     b      |\n");
	ft_printf("------------|------------|\n");
	while (print_one_line(&a, &b))
		ft_printf("\n");
	ft_printf("\n");
	ft_printf(after);
}
