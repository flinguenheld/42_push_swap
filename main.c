/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:31 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/09 18:48:36 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int *new_content(int v)
{
	int *blah = malloc(sizeof(int));
	*blah = v;
	return blah;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	// a = NULL;
	// ft_lst_push_back(&a, ft_lst_new(new_content(0)));
	// ft_lst_push_back(&a, ft_lst_new(new_content(1)));
	// ft_lst_push_back(&a, ft_lst_new(new_content(2)));
	// ft_lst_push_back(&a, ft_lst_new(new_content(3)));

	// // if (is_sorted(a, 5))
	// if (is_sorteddddd(a))
	// 	ft_printf("yes\n");
	// else
	// 	ft_printf("no\n");

	// ft_lst_clear_basic(&a);
	// return 0;

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
	if (is_sorted(a, 0))
		return (0);
	print_ab(a, NULL, "Original");
	selection_sort(&a);
	print_ab(a, NULL, "Sorted");

	// --
	ft_lst_clear_basic(&a);
	return (0);
}
