/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lst_rotate_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 12:08:11 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/04 12:20:48 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lst_rotate_left(t_list **lst)
{
	t_list	*first;

	first = ft_lst_pop_front(lst);
	if (first != NULL)
		ft_lst_push_back(lst, first);
}
