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
#include "push_swap.h"

// Rotate the stack as long as it's not sorted



void	patrick(t_stack *a, t_stack *b)
{
	t_list	*test;

	test = longest_sequence(a->start);
	ft_printf("hello %d\n", ft_lst_size(test));
	print_ab(test, NULL, "what the eck");
	print_ab(a->start, b->start, "is it ok ?");

	ft_lst_clear(&test, free);
}
