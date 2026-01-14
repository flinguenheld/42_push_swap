/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:25:04 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/04 12:20:48 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lst_pop_front(t_list **lst)
{
	t_list	*first;

	if (*lst == NULL)
		return (NULL);
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	return (first);
}
