/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:27:30 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 18:22:26 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char value, t_flags flags)
{
	int		total;

	total = 0;
	flags.width.val--;
	while (!flags.width.after && flags.width.val-- > 0)
		total += putchar_count(' ', flags);
	total += putchar_count(value, flags);
	while (flags.width.after && flags.width.val-- > 0)
		total += putchar_count(' ', flags);
	return (total);
}
