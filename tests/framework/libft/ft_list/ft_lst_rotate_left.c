/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lst_rotate_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 12:08:11 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/04 12:20:48 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lst_rotate_right(t_list **lst)
{
	t_list	*last;

	last = ft_lst_pop_back(lst);
	if (last != NULL)
		ft_lst_push_front(lst, last);
}
