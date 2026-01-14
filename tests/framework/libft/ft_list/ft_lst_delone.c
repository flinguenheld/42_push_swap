/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lst_delone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:44:41 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:55 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	del_node_basic(void *content)
{
	free(content);
}

void	ft_lst_delone_basic(t_list *lst)
{
	ft_lst_delone(lst, del_node_basic);
}

void	ft_lst_delone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		del(lst->content);
		lst->content = NULL;
		free(lst);
	}
}
