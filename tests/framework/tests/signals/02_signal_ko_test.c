/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   02_signal_ko_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/13 19:49:41 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

int	signal_ko_test(void)
{
	int	a;
	int	b;

	a = 100;
	b = 100;
	// Voluntarily fail
	if (a + b == 1000000)
		return (1);
	else
		return (0);
}
