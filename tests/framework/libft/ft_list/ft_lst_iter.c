/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lst_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:18:33 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:54 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lst_iter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL)
	{
		f(lst->content);
		ft_lst_iter(lst->next, f);
	}
}
