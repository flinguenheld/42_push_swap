/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:39:23 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/14 14:53:27 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/libunit.h"
#include "template_tests.h"

int	template_launcher(t_lu_counter *final_counter)
{
	t_lu_list	*list;

	list = NULL;
	load_test(&list, "template name", &template_test);

	return (launch_tests("GROUP NAME", list, final_counter));
}
