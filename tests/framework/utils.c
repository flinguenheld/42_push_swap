/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:32:08 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/21 16:32:09 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libunit.h"

static size_t	get_size(unsigned long value, unsigned long base)
{
	if (value == 0)
		return (1);
	return (get_size(value / base, base) + 1);
}

static void	run(char *ptr, unsigned long value,
			unsigned long base, char *base_str)
{
	if (value >= base)
		run(ptr - 1, value / base, base, base_str);
	*ptr = base_str[value % base];
}

char	*lu_ltobase(long value, char *base_str)
{
	size_t			length;
	char			*start;
	long			base;
	unsigned long	unsigned_n;

	base = (unsigned long)strlen(base_str);
	if (value < 0)
		unsigned_n = -value;
	else
		unsigned_n = value;
	length = get_size(unsigned_n / base, base);
	if (value < 0)
		length++;
	start = calloc(length + 1, sizeof(char));
	if (start != NULL)
	{
		if (value < 0)
			*start = '-';
		run(start + length - 1, unsigned_n, base, base_str);
	}
	return (start);
}
