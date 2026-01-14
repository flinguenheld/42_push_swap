/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:05:25 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:55 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned long value, t_flags flags, char uppercase, char no_plus)
{
	char	*unsigned_value_str;

	unsigned_value_str = ft_ultobase(value, "0123456789abcdef");
	if (no_plus == 1)
		flags.plus = 0;
	if (value == 0)
		flags.hexa = "";
	if (uppercase == 1)
	{
		ft_striter(unsigned_value_str, &ft_toupper);
		if (*flags.hexa != '\0')
			flags.hexa = "0X";
	}
	flags = up_flags_number(0, unsigned_value_str, flags);
	return (print_number(0, unsigned_value_str, flags));
}
