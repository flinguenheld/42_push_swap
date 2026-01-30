/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:34:30 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/30 16:15:41 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"

#include "../libft/libft.h"

static int	print_one_line(t_list **a, t_list **b)
{
	int	still_one;

	still_one = 0;
	if (*a != NULL)
	{
		ft_printf("┃ % 12d ┃", *(int *)(*a)->content);
		*a = (*a)->next;
		still_one = 1;
	}
	else
		ft_printf("┃              ┃");
	if (*b != NULL)
	{
		ft_printf(" % 12d ┃", *(int *)(*b)->content);
		*b = (*b)->next;
		still_one = 1;
	}
	else
		ft_printf("              ┃");
	return (still_one);
}

void	print_ab(t_list *a, t_list *b, char *title, char simple)
{
	if (simple)
	{
		ft_printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		ft_printf("┃% 25s    ┃\n", title);
		ft_printf("┣━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┫\n");
	}
	else
	{
		ft_printf("┏━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┓\n");
		ft_printf("┃      a       ┃      b       ┃\n");
		ft_printf("┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫\n");
	}
	while (print_one_line(&a, &b))
		ft_printf("\n");
	ft_printf("\n");
	ft_printf("┗━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛\n");
}

void	print_list(t_list *list, char *separator)
{
	ft_printf("\n--\n");
	while (list != NULL)
	{
		ft_printf("%d", *(int *)(list->content));
		if (list->next != NULL)
			ft_printf("%s", separator);
		list = list->next;
	}
	ft_printf("\n--\n");
}
