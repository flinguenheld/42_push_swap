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

int	rotate(t_list **start, char to_print)
{
	if (*start != NULL)
	{
		ft_lst_rotate_left(start);
		if (to_print != '\0')
		{
			ft_printf("r");
			ft_printf("%c\n", to_print);
		}
		return (1);
	}
	return (0);
}

void	rotate_ab(t_list **a, t_list **b)
{
	int	done;

	done = rotate(a, '\0');
	done += rotate(b, '\0');
	if (done)
		ft_printf("rr\n");
}
