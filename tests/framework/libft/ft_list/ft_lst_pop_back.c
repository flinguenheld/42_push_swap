/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lst_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:46:37 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 22:52:48 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lst_pop_back(t_list **lst)
{
	t_list	*penultimate;

	if (*lst == NULL)
		return (NULL);
	if ((*lst)->next == NULL)
	{
		penultimate = *lst;
		*lst = NULL;
		return (penultimate);
	}
	if (((*lst)->next)->next == NULL)
	{
		penultimate = (*lst)->next;
		(*lst)->next = NULL;
		return (penultimate);
	}
	return (ft_lst_pop_back(&(*lst)->next));
}
