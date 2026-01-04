/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:55:27 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:55 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_count(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	sub_min_zero(int a, int b)
{
	int	result;

	result = a - b;
	if (result < 0)
		return (0);
	return (result);
}

int	mini(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
