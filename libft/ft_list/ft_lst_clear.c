/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:16:12 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:54 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lst_clear_basic(t_list **lst)
{
	if (lst != NULL && *lst != NULL)
	{
		ft_lst_clear_basic(&(*lst)->next);
		ft_lst_delone_basic(*lst);
		*lst = NULL;
	}
}

void	ft_lst_clear(t_list **lst, void (*del)(void *))
{
	if (lst != NULL && *lst != NULL)
	{
		ft_lst_clear(&(*lst)->next, del);
		ft_lst_delone(*lst, del);
		*lst = NULL;
	}
}
