/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:22:02 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 18:22:26 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_string_null(t_flags flags)
{
	if (flags.prec.on && flags.prec.val < 6)
		return (print_string("", flags));
	return (print_string("(null)", flags));
}

int	print_string(char *value, t_flags flags)
{
	int	total;

	total = 0;
	if (value == NULL)
		return (print_string_null(flags));
	if (flags.prec.on)
		flags.width.val -= mini(flags.prec.val, ft_strlen(value));
	else
		flags.width.val -= ft_strlen(value);
	while (flags.width.on && !flags.width.after && flags.width.val-- > 0)
		total += putchar_count(' ', flags);
	while (*value != '\0' && (!flags.prec.on || flags.prec.val-- > 0))
		total += putchar_count(*value++, flags);
	while (flags.width.on && flags.width.after && flags.width.val-- > 0)
		total += putchar_count(' ', flags);
	return (total);
}
