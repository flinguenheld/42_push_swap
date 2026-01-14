/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:02:13 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/13 22:27:52 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft/libft.h"

/**
 * @brief
 * Malloc a new content
 * @return
 * unode struct ptr or NULL if malloc error
 */
static t_unode	*new_content(char *name, int (*function)(void))
{
	t_unode	*content;

	content = malloc(sizeof(t_unode));
	if (content != NULL)
	{
		content->name = name;
		content->function = function;
	}
	return (content);
}

/**
 * @brief
 * Print the test result according to the given status with this format:
 * [title]:[test->name]:[status]
 *
 * Use <sys/wait.h> macros to check first if the returned status is from
 *   - exit() or return() (OK & KO only in this project)
 *   - signal
 * Then use another macro to get the code value.
 * @return
 * - 1 if test is OK
 * - 0 for all other cases
 */
static int	print_result(int status, char *name)
{
	int	code;

	if (WIFEXITED(status))
	{
		code = WEXITSTATUS(status);
		if (code == EXIT_OK)
			return (print_test_line(name, "OK", KGRAD0_GRN), 1);
		else if (code == EXIT_KO)
			return (print_test_line(name, "KO", KGRAD9_RED), 0);
	}
	else if (WIFSIGNALED(status))
	{
		code = WTERMSIG(status);
		if (code == SIGSEGV)
			return (print_test_line(name, "SIGSEGV", KGRAD6_RED), 0);
		else if (code == SIGBUS)
			return (print_test_line(name, "SIGBUS", KGRAD6_RED), 0);
	}
	return (print_test_line(name, "unknown error", KMAG), 0);
}

/**
 * @brief
 * Create a fork to launch the test fuction.
 * The child emits a signal OK/KO with the exit fuction
 * Due to the exit, the child frees the ENTIRE list to avoid any leak.
 *
 * The parent process waits the end of its child, then prints the result.
 * @return
 * 1 if test is OK
 * 0 for all other cases
 */
static int	fork_to_test(char *title, t_unode *test, t_list **list_to_free)
{
	pid_t	id_fork;
	int		status;
	int		(*function_to_test)(void);

	id_fork = fork();
	if (id_fork < 0)
	{
		ft_printf_err("%s:\t%s:\tLaunch test error.\n", title, test->name);
		ft_lst_clear_basic(list_to_free);
		return (0);
	}
	else if (id_fork == 0)
	{
		function_to_test = test->function;
		ft_lst_clear_basic(list_to_free);
		exit(function_to_test());
	}
	wait(&status);
	return (print_result(status, test->name));
}

int	launch_tests(char *title, t_list *start_list, t_count *final_count)
{
	t_count	local_count;
	t_unode	*content;
	t_list	*current_node;

	print_title(title);
	local_count = counter_init();
	current_node = start_list;
	while (current_node != NULL)
	{
		content = (t_unode *)current_node->content;
		local_count.success += fork_to_test(title, content, &start_list);
		current_node = current_node->next;
		(local_count.total)++;
	}
	ft_lst_clear_basic(&start_list);
	print_local_counter(local_count.success, local_count.total);
	final_count->success += local_count.success;
	final_count->total += local_count.total;
	if (local_count.success == local_count.total)
		return (0);
	return (-1);
}

void	load_test(t_list **list, char *name, int (*function)(void))
{
	ft_lst_push_back(list, ft_lst_new(new_content(name, function)));
}
