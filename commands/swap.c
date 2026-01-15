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

int	swap(t_list *start, char to_print)
{
	if (start != NULL && start->next != NULL)
	{
		ft_lst_swap_content(start, start->next);
		if (to_print != '\0')
		{
			ft_printf("s");
			ft_printf("%c\n", to_print);
		}
		return (1);
	}
	return (0);
}

void	swap_ab(t_list *a, t_list *b)
{
	int	done;

	done = swap(a, '\0');
	done += swap(b, '\0');
	if (done)
		ft_printf("ss\n");
}
