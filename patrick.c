/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   patrick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:38:22 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/27 20:22:23 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lis/lis.h"
#include "push_swap.h"
#include "utils/utils.h"


void	patrick(t_stack *a, t_stack *b)
{
	t_list		*lis;
	t_keeplist	keeplist;

	keeplist = (t_keeplist){.list = NULL, .status = 0};
	lis = get_lis(a->start);
	print_ab(lis, NULL, "L I S");

	only_keep_lis(a, b, lis, &keeplist);
	print_ab(a->start, b->start, "PUSH DONE");

	ft_lst_clear(&keeplist.list, free);
	
	print_ab(lis, NULL, "L I S before clean");
	ft_lst_clear(&lis, free);
	print_ab(lis, NULL, "L I S before clean");

	greedy_push(a, b);

	rotate_shortest_way(a, get_index(a->start, content(lowest_node(a->start, 0))));
}
