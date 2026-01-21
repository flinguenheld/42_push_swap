/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/21 16:38:15 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals/signals.h"

int	main(void)
{
	t_lu_counter	s_count;

	s_count = counter_init();
	signal_launcher(&s_count);
	print_final_counter(&s_count);
	if (s_count.success != s_count.total)
		return (-1);
	return (0);
}
