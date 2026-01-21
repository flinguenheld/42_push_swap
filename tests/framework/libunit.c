/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:02:13 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/21 16:31:39 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdio.h>

/**
 * @brief
 * Malloc a new content
 * @return
 * unode struct ptr or NULL if malloc error
 */
static t_lu_unode	*new_content(char *name, int (*function)(void))
{
	t_lu_unode	*content;

	content = malloc(sizeof(t_lu_unode));
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
static int	fork_n_test(char *title, t_lu_unode *test, t_lu_list **list_to_free)
{
	pid_t	id_fork;
	int		status;
	int		(*function_to_test)(void);

	id_fork = fork();
	if (id_fork < 0)
	{
		printf("%s:\t%s:\tLaunch test error.\n", title, test->name);
		lu_lst_clear(list_to_free, free);
		return (0);
	}
	else if (id_fork == 0)
	{
		function_to_test = test->function;
		lu_lst_clear(list_to_free, free);
		exit(function_to_test());
	}
	wait(&status);
	return (print_result(status, test->name));
}

int	launch_tests(char *title, t_lu_list *start_list, t_lu_counter *final_count)
{
	t_lu_counter	local_count;
	t_lu_unode		*content;
	t_lu_list		*current_node;

	print_title(title);
	local_count = counter_init();
	current_node = start_list;
	while (current_node != NULL)
	{
		content = (t_lu_unode *)current_node->content;
		local_count.success += fork_n_test(title, content, &start_list);
		current_node = current_node->next;
		(local_count.total)++;
	}
	lu_lst_clear(&start_list, free);
	print_local_counter(local_count.success, local_count.total);
	final_count->success += local_count.success;
	final_count->total += local_count.total;
	if (local_count.success == local_count.total)
		return (0);
	return (-1);
}

void	load_test(t_lu_list **list, char *name, int (*function)(void))
{
	lu_lst_push_back(list, lu_lst_new(new_content(name, function)));
}
