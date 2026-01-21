/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:32:08 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/21 16:32:09 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libunit.h"

void	lu_lst_delone(t_lu_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		del(lst->content);
		lst->content = NULL;
		free(lst);
	}
}

void	lu_lst_clear(t_lu_list **lst, void (*del)(void *))
{
	if (lst != NULL && *lst != NULL)
	{
		lu_lst_clear(&(*lst)->next, del);
		lu_lst_delone(*lst, del);
		*lst = NULL;
	}
}

t_lu_list	*lu_lst_new(void *content)
{
	t_lu_list	*new_node;

	new_node = malloc(sizeof(t_lu_list));
	if (new_node != NULL)
	{
		new_node->content = content;
		new_node->next = NULL;
	}
	return (new_node);
}

void	lu_lst_push_back(t_lu_list **lst, t_lu_list *new_node)
{
	if (*lst == NULL)
		*lst = new_node;
	else
		lu_lst_last(*lst)->next = new_node;
}

t_lu_list	*lu_lst_last(t_lu_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	return (lu_lst_last(lst->next));
}
