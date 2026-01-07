/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:31 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/07 21:09:25 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "commands/commands.h"

static void	print_node(void *content)
{
	ft_printf("value -> %d\n", *(int *)(content));
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	while (argc-- > 1)
	{
		argv++;
		if (check_and_push_argv(&a, *argv) == 0)
		{
			ft_lst_clear_basic(&a);
			ft_printf_err("Error\n");
			return (1);
		}
	}
	ft_lst_iter(a, print_node);
	push_b(&a, &b);
	push_b(&a, &b);
	print_ab(a, b, "before", "after");


	
	ft_lst_clear_basic(&a);
	ft_printf("end\n");
	return (0);
}
