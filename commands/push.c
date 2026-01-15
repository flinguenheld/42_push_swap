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

void	push(t_list **from, t_list **to, char to_print)
{
	if (*from != NULL)
	{
		ft_lst_push_front(to, ft_lst_pop_front(from));
		if (to_print != '\0')
		{
			ft_printf("p");
			ft_printf("%c\n", to_print);
		}
	}
}
