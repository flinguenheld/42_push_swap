/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_ten.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:35:50 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/09 19:35:50 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands/commands.h"
#include "libft/libft.h"
#include "push_swap.h"

typedef struct s_data
{
	int still;
	int in_a;
} t_data;

void	swap(t_list **a, t_list **b)
{
	int	on_a;
	int	on_b;

	on_a = *a != NULL && (*a)->next != NULL && content(*a) < content((*a)->next); 
	on_b = *b != NULL && (*b)->next != NULL && content(*b) > content((*b)->next); 

	if (on_a && on_b)
		swap_b(*b);
}

void is_ok(t_list *b, int amount)
{


	
}

/**
 * @brief
 * Only sort the ten first values
 */
void	sort_ten_top_values(t_list **b)
{
	t_data	data;

	data = (t_data){.still = 4, .in_a = 0};



	// Go down and swap the highest up to the last one
}
