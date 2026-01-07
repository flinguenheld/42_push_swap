/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:04:31 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/07 23:04:11 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "commands/commands.h"
# include "limits.h"

typedef struct s_lowests
{
	int	first;
	int	second;
}	t_lowests;

int		check_and_push_argv(t_list **a, char *str);
void	print_ab(t_list *a, t_list *b, char *title);

/**
 * @brief
 * Simple sort
 */
void	lowest_sort(t_list **a);

#endif
