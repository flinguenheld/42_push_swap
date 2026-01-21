/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:07:14 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/21 16:31:39 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

# define EXIT_OK 1
# define EXIT_KO 0

# define KNRM  "\x1B[0m"
# define KSTA  "\x1B[38;2;"
# define KEND  ";0m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KGRAD0_GRN  "\x1B[38;2;0;200;0m"
# define KGRAD6_RED  "\x1B[38;2;200;200;0m"
# define KGRAD9_RED  "\x1B[38;2;200;0;0m"

/**
 * List node.
 */
typedef struct s_lu_list
{
	void				*content;
	struct s_lu_list	*next;
}	t_lu_list;

/**
 * @brief
 * Struct used to store data in lists
 */
typedef struct s_lu_unode
{
	int		(*function)(void);
	char	*name;
}	t_lu_unode;

/**
 * @brief
 * Struct used to store result counter
 */
typedef struct s_lu_counter
{
	int		total;
	int		success;
}	t_lu_counter;

// ----------------------------------------------------------------------------
// ---------------------------------------------------------------- Tests -----

/**
 * @brief
 * Add a new test in the list.
 */
void			load_test(t_lu_list **list, char *name, int (*function)(void));

/**
 * @brief
 * Loop in the list and launch tests.
 * Free the list once at the end of the function
 * @return
 * 0 if all tests are OK
 * Otherwise 1
 */
int				launch_tests(char *title, t_lu_list *start_list,
					t_lu_counter *final_count);

// ----------------------------------------------------------------------------
// ---------------------------------------------------------------- Print -----

/**
 * @brief
 * Print the given msg with all format options and clear them at the end
 */
void			print_test_line(char *name, char *msg, char *color);

/**
 * @brief
 * Print the counter for one launcher with an adapted colour
 */
void			print_local_counter(int counter, int total);

/**
 * @brief
 * Print the final counter with an adapted colour
 */
void			print_final_counter(t_lu_counter *s_count);

/**
 * @brief
 * Print a title on the left with a lot of ====
 */
void			print_title(char *title);

/**
 * @brief
 * Print spaces then equal sings to set the right part of the frame
 *   txt              =====
 *   txt              =====
 */
void			print_close_frame_right(int already_printed);

/**
 * @brief
 * Print a full line of equal signs or just equal signs on left & right
 * ========================================================================
 * =====                                                              =====
 */
void			print_frame_line(int empty);

// ----------------------------------------------------------------------------
// -------------------------------------------------------------- Counter -----

/**
 * @brief
 * Init a new counter with values to 0
 */
t_lu_counter	counter_init(void);

// ----------------------------------------------------------------------------
// ----------------------------------------------------------- Utils list -----

/**
 * @brief
 * Takes a node as parameter and frees its content using the function ’del’.
 * Free the node itself but does NOT free the next node.
 */
void			lu_lst_delone(t_lu_list *lst, void (*del)(void *));

/**
 * @brief
 * Deletes and frees the given node and all its successors, using the
 * function ’del’ and free(3). Finally, set the pointer to the list to NULL.
 */
void			lu_lst_clear(t_lu_list **lst, void (*del)(void *));

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a new node.
 * The content member variable is initialized with the given parameter content.
 * The variable next is initialized to NULL.
 * 
 * @return
 * A pointer to the new node.
 */
t_lu_list		*lu_lst_new(void *content);

/**
 * @brief
 * Push the node ’new’ at the end of the list.
 */
void			lu_lst_push_back(t_lu_list **lst, t_lu_list *new_node);

/**
 * @brief
 * Returns the last node of the list.
 */
t_lu_list		*lu_lst_last(t_lu_list *lst);

// ----------------------------------------------------------------------------
// ---------------------------------------------------------------- Utils -----

/**
 * @brief
 * Convert the value into a malloc char.
 */
char			*lu_ltobase(long value, char *base_str);

#endif
