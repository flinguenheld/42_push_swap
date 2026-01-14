/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   04_signal_bus_error_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:07 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/13 19:49:41 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// https://en.wikipedia.org/wiki/Bus_error
int	signal_bus_error_test(void)
{
	int		*iptr;
	char	*cptr;

	__asm__("pushf\norl $0x40000,(%rsp)\npopf");
	cptr = malloc(sizeof(int) + 1);
	iptr = (int *)++cptr;
	*iptr = 42;
	return (0);
}
