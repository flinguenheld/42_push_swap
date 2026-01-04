/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:27:30 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:55 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char value, t_flags flags)
{
	int		total;

	total = 0;
	flags.width.val--;
	while (!flags.width.after && flags.width.val-- > 0)
		total += putchar_count(' ');
	total += putchar_count(value);
	while (flags.width.after && flags.width.val-- > 0)
		total += putchar_count(' ');
	return (total);
}
