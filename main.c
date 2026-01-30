/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:31 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/30 14:09:02 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils/utils.h"
#include "sort/sort.h"

static void	sort(t_stack *a, t_stack *b)
{
	int	len_a;

	len_a = ft_lst_size(a->start);
	if (!is_sorted(a->start, 0))
	{
		if (len_a < 10)
			selection_sort(a, b);
		else
			greedy_lis_sort(a, b);
		if (!is_sorted(a->start, 0))
			ft_printf_err("SORT FAIL!\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

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
	sort(&a, &b);
	ft_lst_clear(&a.start, free);
	ft_lst_clear(&b.start, free);
	return (0);
}
