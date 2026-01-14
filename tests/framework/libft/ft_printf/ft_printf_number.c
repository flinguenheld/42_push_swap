/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:21:27 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/13 23:50:47 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	up_flags_number(char negative, char *unsigned_value, t_flags flags)
{
	int		len_without_sign;

	len_without_sign = (int)ft_strlen(unsigned_value);
	if (flags.prec.val > 0 && flags.width.val > 0)
		flags.width.filler = ' ';
	if (flags.prec.on && (*unsigned_value == '\0' || (*unsigned_value == '0')))
		flags.width.filler = ' ';
	if (flags.prec.on && flags.prec.val == 0 && *unsigned_value == '0')
	{
		flags.prec.on = -1;
		flags.prec.val = 0;
		return (flags);
	}
	flags.prec.val = sub_min_zero(flags.prec.val, len_without_sign);
	if (*flags.hexa != '\0')
		len_without_sign += 2;
	if (flags.plus && !negative)
		len_without_sign++;
	else if (flags.space && !negative)
		len_without_sign++;
	else if (negative)
		len_without_sign++;
	flags.width.val -= (flags.prec.val + len_without_sign);
	return (flags);
}

int	print_number(char negative, char *unsigned_value, t_flags flags)
{
	int		total;

	total = 0;
	while (flags.width.on && !flags.width.after && flags.width.filler == ' '
		&& flags.width.val-- > 0)
		total += putchar_count(' ', flags);
	if (flags.plus && !negative)
		total += putchar_count('+', flags);
	else if (flags.space && !negative)
		total += putchar_count(' ', flags);
	if (*flags.hexa != '\0')
		total += ft_printf(flags.hexa);
	if (negative)
		total += putchar_count('-', flags);
	while (flags.prec.on && flags.prec.val-- > 0)
		total += putchar_count('0', flags);
	while (flags.width.on && flags.width.after == 0
		&& flags.width.filler == '0' && flags.width.val-- > 0)
		total += putchar_count('0', flags);
	if (flags.prec.on >= 0)
		total += ft_printf(unsigned_value);
	while (flags.width.on && flags.width.after && flags.width.val-- > 0)
		total += putchar_count(' ', flags);
	free(unsigned_value);
	return (total);
}
