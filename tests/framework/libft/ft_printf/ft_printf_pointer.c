/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:13:12 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:55 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long address, t_flags flags)
{
	char	*unsigned_value_str;

	if (address == 0)
	{
		flags.prec.on = 0;
		return (print_string("(nil)", flags));
	}
	flags.hexa = "0x";
	unsigned_value_str = ft_ultobase(address, "0123456789abcdef");
	flags = up_flags_number(0, unsigned_value_str, flags);
	return (print_number(0, unsigned_value_str, flags));
}
