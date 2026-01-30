/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:52:56 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/30 11:57:08 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

/**
 * @brief
 * Infinitly read the input and run the written command
 */
static void	read_input(t_stack *a, t_stack *b, char verbose)
{
	char	*line;
	int		cmd_status;

	while (1)
	{
		line = ft_get_next_line(0);
		cmd_status = run_cmd(line, a, b, verbose);
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
 * @brief
 * Parse the arguments and launch the checker
 * @return
 * 1 if error
 */
static int	parse_and_check(int argc, char **argv, char verbose)
{
	t_stack	a;
	t_stack	b;

	a = (t_stack){.start = NULL, .name = 'a'};
	b = (t_stack){.start = NULL, .name = 'b'};
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
	if (verbose)
		print_ab(a.start, b.start, "Start");
	read_input(&a, &b, verbose);
	ft_lst_clear(&a.start, free);
	ft_lst_clear(&b.start, free);
	return (0);
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
 * @return
 * 1 if error
 */
int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (usage(), 1);
	if (ft_strncmp(argv[1], "-h", 2) == 0
		|| ft_strncmp(argv[1], "--help", 6) == 0)
		return (usage(), 0);
	if (ft_strncmp(argv[1], "-v", 2) == 0
		|| ft_strncmp(argv[1], "--verbose", 9) == 0)
		return (parse_and_check(argc - 1, argv + 1, 1));
	return (parse_and_check(argc, argv, 0));
}
