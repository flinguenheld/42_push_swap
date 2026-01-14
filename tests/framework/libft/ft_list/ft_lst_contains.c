/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lst_contains.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:59:10 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/04 22:13:00 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lst_contains(t_list *lst, int (*comparison)(void *))
{
	if (lst == NULL)
		return (0);
	if (comparison(lst->content))
		return (1);
	return (ft_lst_contains(lst->next, comparison));
}

int	ft_lst_contains_key(t_list *lst, void *key, int (*comp)(void *, void *))
{
	if (lst == NULL)
		return (0);
	if (comp(lst->content, key))
		return (1);
	return (ft_lst_contains_key(lst->next, key, comp));
}
