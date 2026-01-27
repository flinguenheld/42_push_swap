/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   patrick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:38:22 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/22 16:38:23 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lis/lis.h"
#include "push_swap.h"


void	patrick(t_stack *a, t_stack *b)
{
	t_list	*sub;
	t_keeplist	keeplist;

	keeplist = (t_keeplist){.list = NULL, .status = 0};
	sub = get_lis(a->start);
	print_ab(sub, NULL, "LONGEST SUB");
	// ft_printf("size %d-------------------------------------------------------\n", ft_lst_size(sub));
	// print_ab(a->start, b->start, "is it ok ?");

	only_keep_subsequence(a, b, sub, &keeplist);
	print_ab(a->start, b->start, "PUSH DONE");
	ft_lst_clear(&keeplist.list, free);

	ft_lst_clear(&sub, free);
}
