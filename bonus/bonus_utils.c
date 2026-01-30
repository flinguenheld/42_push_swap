/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:55:06 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/30 16:15:41 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	run_rotation(char *cmd, t_stack *a, t_stack *b, char verbose)
{
	if (ft_strncmp(cmd, "ra\n", 3) == 0)
		return (rotate(&a->start, '\0'), verb(a, b, verbose, "ra"), 1);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		return (rotate(&b->start, '\0'), verb(a, b, verbose, "rb"), 1);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
	{
		rotate(&a->start, '\0');
		rotate(&b->start, '\0');
		return (verb(a, b, verbose, "rr"), 1);
	}
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		return (reverse_rotate(&a->start, '\0'), verb(a, b, verbose, "rra"), 1);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		return (reverse_rotate(&b->start, '\0'), verb(a, b, verbose, "rrb"), 1);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
	{
		reverse_rotate(&a->start, '\0');
		reverse_rotate(&b->start, '\0');
		return (verb(a, b, verbose, "rrr"), 1);
	}
	else
		return (-1);
	return (1);
}

char	run_cmd(char *cmd, t_stack *a, t_stack *b, char verbose)
{
	if (cmd == NULL || *cmd == '\n')
		return (2);
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		return (swap(a->start, '\0'), verb(a, b, verbose, "sa"), 1);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		return (swap(b->start, '\0'), verb(a, b, verbose, "sb"), 1);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
	{
		swap(a->start, '\0');
		swap(b->start, '\0');
		return (verb(a, b, verbose, "ss"), 1);
	}
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		return (push(&b->start, &a->start, '\0'), verb(a, b, verbose, "pa"), 1);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		return (push(&a->start, &b->start, '\0'), verb(a, b, verbose, "pb"), 1);
	return (run_rotation(cmd, a, b, verbose));
}

void	usage(void)
{
	ft_printf(" Usage: checker [OPTION] VALUES...\n");
	ft_printf(" Push swap checker\n");
	ft_printf("\n");
	ft_printf("      -h, --help       Print this message\n");
	ft_printf("      -v, --verbose    Print the stacks after each command\n");
	ft_printf("\n");
	ft_printf(" Give your list in argument, they will be used to fill A.\n");
	ft_printf(" The checker will wait commands in the standard input.\n");
	ft_printf(" Write one command per line, the checker will run it\n");
	ft_printf(" (allowed cmd: sa sb ss pa pb ra rb rr rra rrb rrr)\n");
	ft_printf("\n");
	ft_printf(" Then press enter or Ctrl-D to end it and launch the test:\n");
	ft_printf("     OK if the stack A is sorted and the B is empty\n");
	ft_printf("     KO if not\n");
	ft_printf("\n");
	ft_printf("     Print 'Error' in case of wrong values or command.\n");
	ft_printf("\n");
	ft_printf("   Example:  ./checker 3 2 5\n");
	ft_printf("             sa\n");
	ft_printf("             rrr\n");
	ft_printf("             rrr\n");
	ft_printf("             sa\n");
	ft_printf("             rr\n");
	ft_printf("             rr\n");
	ft_printf("             OK\n");
}

void	verb(t_stack *a, t_stack *b, char verbose, char *title)
{
	if (verbose)
		print_ab(a->start, b->start, title);
}
