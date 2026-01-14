/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:33:26 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/13 23:50:48 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_atol(const char *str)
{
	int		is_neg;
	long	value;

	value = 0;
	is_neg = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		is_neg = (*str++ == '-');
	while (ft_isdigit(*str))
		value = value * 10 + (*str++ - '0');
	if (is_neg)
		value = -value;
	return (value);
}
