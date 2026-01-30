/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:55:06 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/30 16:15:41 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../push_swap.h"
# include "../utils/utils.h"

/**
 * Print usage
 */
void	usage(void);

/**
 * @brief
 * Print the stacks in a wonderful frame
 */
void	verb(t_stack *a, t_stack *b, char verbose, char *title);

/**
 * @brief
 * Check the given cmd and run the associated cmd (do not print it)
 * @return
 * 1  -> command found and run
 * 2  -> cmd NULL or just a new line
 * -1 -> unknown command (nothing done)
 */
char	run_cmd(char *cmd, t_stack *a, t_stack *b, char verbose);

/**
 * @brief
 * Extend 'run_cmp' with rotations -_-'
 * @return
 * 1  -> command found and run
 * 2  -> cmd NULL or just a new line
 * -1 -> unknown command (nothing done)
 */
char	run_rotation(char *cmd, t_stack *a, t_stack *b, char verbose);

#endif
