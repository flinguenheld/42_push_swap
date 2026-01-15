/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:10:40 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/15 21:47:24 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	reverse_rotate(t_list **start, char to_print)
{
	if (*start != NULL)
	{
		ft_lst_rotate_right(start);
		if (to_print != '\0')
		{
			ft_printf("rr");
			ft_printf("%c\n", to_print);
		}
		return (1);
	}
	return (0);
}

void	reverse_rotate_ab(t_list **a, t_list **b)
{
	int	done;

	done = reverse_rotate(a, '\0');
	done += reverse_rotate(b, '\0');
	if (done)
		ft_printf("rrr\n");
}
