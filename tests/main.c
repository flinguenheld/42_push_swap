/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:39:23 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/14 14:53:24 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/libunit.h"

// --
#include "template_tests/template_tests.h"

int	main(void)
{
	// Create and init a counter --
	t_count	counter;

	counter = counter_init();

	// Add here all your launchers --
	template_launcher(&counter);


	// Print a summary of successful tests --
	print_final_counter(&counter);
	if (counter.success != counter.total)
		return (-1);
	return (0);
}
