/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 22:18:11 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:54 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lst_push_back(t_list **lst, t_list *new_node)
{
	if (*lst == NULL)
		*lst = new_node;
	else
		ft_lst_last(*lst)->next = new_node;
}
