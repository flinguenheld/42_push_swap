/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:26:48 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:55 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lst_size(t_list *lst)
{
	if (lst == NULL)
		return (0);
	if (lst->next == NULL)
		return (1);
	return (ft_lst_size(lst->next) + 1);
}
