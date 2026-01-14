/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:02:43 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:54 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lst_new(new_content);
		if (new_node == NULL)
		{
			del(new_content);
			ft_lst_clear(&new_list, del);
			return (NULL);
		}
		ft_lst_push_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
