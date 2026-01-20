/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:31 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/20 00:32:03 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	// t_list	*a;
	// t_list	*b;

	t_stack	a;
	t_stack	b;

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

	a = (t_stack){.start = NULL, .name = 'a'};
	b = (t_stack){.start = NULL, .name = 'b'};
	if (argc <= 1)
		return (0);
	while (argc-- > 1)
	{
		argv++;
		if (check_and_push_argv(&a.start, *argv) == 0)
		{
			ft_lst_clear(&a.start, free);
			ft_printf_err("Error\n");
			return (1);
		}
	}
	print_ab(a.start, b.start, "Original");

	// ADD A MECHANISM TO TRY DIFFERENT GROUP SIZES
	// AND COUNT STEPS TO ONLY GET THE BEST ONE --------------------------

	if (is_sorted(a.start, 0))
		return (0);
	if (ft_lst_size(a.start) < 12)
	{
		selection_sort(&a, &b);
		// return (0);
	}
	else
	{
		// selection_sort(&a, &b);
		// selection_sort_range(&a, &b, 2);
		group_sort(&a, &b, 40);
		// group_sort(&a, &b, 8);
		
	}
	print_ab(a.start, b.start, "Sorted");

	if (!is_sorted(a.start, 0))
	{
		ft_printf_err("SORT FAIL!\n");
	}

	// --
	ft_lst_clear(&a.start, free);
	return (0);
}
