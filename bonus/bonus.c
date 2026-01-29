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

#include "../push_swap.h"
#include "../utils/utils.h"

/**
 * @brief
 * Extend 'run_cmp' with rotations
 */
static char	run_rotation(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strncmp(cmd, "ra\n", 3) == 0)
		return (rotate(&a->start, '\0'));
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		return (rotate(&b->start, '\0'));
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
	{
		rotate(&a->start, '\0');
		rotate(&b->start, '\0');
		return (1);
	}
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		return (reverse_rotate(&a->start, '\0'));
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		return (reverse_rotate(&b->start, '\0'));
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
	{
		reverse_rotate(&a->start, '\0');
		reverse_rotate(&b->start, '\0');
		return (1);
	}
	return (-1);
}

/**
 * @brief
 * Check the given cmd and run the associated cmd (do not print it)
 * @return
 * 1  -> command found and run
 * 2  -> cmd NULL or just a new line
 * -1 -> unknown command (nothing done)
 */
static char	run_cmd(char *cmd, t_stack *a, t_stack *b)
{
	if (cmd == NULL || *cmd == '\n')
		return (2);
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		return (swap(a->start, '\0'));
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		return (swap(b->start, '\0'));
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
	{
		swap(a->start, '\0');
		swap(b->start, '\0');
		return (1);
	}
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		return (push(&b->start, &a->start, '\0'));
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		return (push(&a->start, &b->start, '\0'));
	return (run_rotation(cmd, a, b));
}

static void	get_commands(t_stack *a, t_stack *b)
{
	char	*line;
	int		cmd_status;

	while (1)
	{
		line = ft_get_next_line(0);
		cmd_status = run_cmd(line, a, b);
		free(line);
		if (cmd_status == -1)
		{
			ft_printf_err("Error\n");
			break ;
		}
		else if (cmd_status == 2)
		{
			if (is_sorted(a->start, 0) && b->start == NULL)
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
			break ;
		}
	}
}

/**
 * Print usage
 */
static void	usage(void)
{
	ft_printf(" Usage: checker VALUES...\n");
	ft_printf("\n");
	ft_printf(" Push swap checker\n");
	ft_printf("\n");
	ft_printf("     Give your list in argument, they will be used to fill A\n");
	ft_printf("     The checker will wait commands in the standard input\n");
	ft_printf("     Write one command per line, the checker will perform it\n");
	ft_printf("     (allowed cmd: sa sb ss pa pb ra rb rr rra rrb rrr)\n");
	ft_printf("\n");
	ft_printf("     Then press enter or Ctrl-D, it will print:\n");
	ft_printf("         OK if the stack A is sorted and the B is empty\n");
	ft_printf("         KO if not\n");
	ft_printf("\n");
	ft_printf("     In case of wrong values or command,\n");
	ft_printf("     it will print 'Error'\n");
	ft_printf("\n");
	ft_printf("   Example:\n");
	ft_printf("      ./checker 3 2 5\n");
	ft_printf("      sa\n");
	ft_printf("      rrr\n");
	ft_printf("      rrr\n");
	ft_printf("      sa\n");
	ft_printf("      rr\n");
	ft_printf("      rr\n");
	ft_printf("      OK\n");
}

/**
 * @brief
 * Create the stacks A & B
 * Fill A with the given arguments
 * Then wait commands in the standard input until Ctrl-D or an empty line
 * After each new line, execute the writen command.
 *
 * Allowed commands:
 *   - sa
 *   - sb
 *   - ss
 *   - pa
 *   - pb
 *   - ra
 *   - rb
 *   - rr
 *   - rra
 *   - rrb
 *   - rrr
 *
 * After an empty line or Ctrl-D, check if the stack A is sorted an B is empty
 * Print 'OK' or 'KO'
 */
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a = (t_stack){.start = NULL, .name = 'a'};
	b = (t_stack){.start = NULL, .name = 'b'};
	if (argc <= 1 || ft_strncmp(argv[1], "-h", 2) == 0
		|| ft_strncmp(argv[1], "--help", 6) == 0)
		usage();
	else
	{
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
		get_commands(&a, &b);
		ft_lst_clear(&a.start, free);
		ft_lst_clear(&b.start, free);
	}
	return (0);
}
