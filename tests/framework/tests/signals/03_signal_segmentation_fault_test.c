/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   03_signal_segmentation_fault_test.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/13 19:49:41 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

int	signal_segmentation_fault_test(void)
{
	int	*a;

	a = NULL;
	*a = 50;
	return (0);
}
