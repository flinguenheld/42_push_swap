/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:52:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/28 11:07:20 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <unistd.h>

static char	apply_rotate(char *txt, t_stack *a, t_stack *b)
{
	if (ft_strncmp(txt, "ra\n\0" , 4) == 0)
		rotate(&a->start, '\0');
	else if (ft_strncmp(txt, "rb\n\0" , 4) == 0)
		rotate(&b->start, '\0');
	else if (ft_strncmp(txt, "rr\n\0" , 4) == 0)
	{
		rotate(&a->start, '\0');
		rotate(&b->start, '\0');
	}
	else if (ft_strncmp(txt, "rra\n" , 4) == 0)
		reverse_rotate(&a->start, '\0');
	else if (ft_strncmp(txt, "rrb\n" , 4) == 0)
		reverse_rotate(&b->start, '\0');
	else if (ft_strncmp(txt, "rrr\n" , 4) == 0)
	{
		reverse_rotate(&a->start, '\0');
		reverse_rotate(&b->start, '\0');
	}
	else
		return (0);
	return (1);
}

static char	apply(char *txt, t_stack *a, t_stack *b)
{
	if (ft_strncmp(txt, "sa\n\0" , 4) == 0)
		swap(a->start, '\0');
	else if (ft_strncmp(txt, "sb\n\0" , 4) == 0)
		swap(b->start, '\0');
	else if (ft_strncmp(txt, "ss\n\0" , 4) == 0)
	{
		swap(a->start, '\0');
		swap(b->start, '\0');
	}
	else if (ft_strncmp(txt, "pa\n\0" , 4) == 0)
		push(&b->start, &a->start, '\0');
	else if (ft_strncmp(txt, "pb\n\0" , 4) == 0)
		push(&a->start, &b->start, '\0');
	else
		return (apply_rotate(txt, a, b));
	return (1);
}

static t_list *read_that(t_stack *a, t_stack *b)
{
	char	buffer[5];
	int		amount_read;

	ft_memset(buffer, '\0', 5);
	while (1)
	{
		amount_read = read(0, &buffer, 5);
		if (amount_read == -1)
		{
			ft_printf_err("Error\n");
			break ;
		}
		if (amount_read == 0)
		{
			ft_printf("Done\n");
			break ;
		}
		if (amount_read > 4)
		{
			ft_printf_err("supp to 4\n");
			break ;
		}

		if (!apply(buffer, a, b))
		{
			ft_printf_err("Error\n");
			return (0);
		}

		// ft_memset(buffer, '\0', 5);
	}

	return (NULL);
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

	ft_printf("Hello\n");
	print_list(a.start, " ");

	read_that(&a, &b);

	
	ft_lst_clear(&a.start, free);
	ft_lst_clear(&b.start, free);
	return (0);
}
