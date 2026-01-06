/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:50:16 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 18:22:26 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags(int file_descriptor)
{
	return ((t_flags){
		.file_descriptor = file_descriptor,
		.width = (t_width){.on = 0, .val = 0, .filler = ' ', .after = 0},
		.prec = (t_precision){.on = 0, .val = 0},
		.plus = 0,
		.space = 0,
		.hexa = "" });
}

/**
 * @brief
 * As long as ptr value is a digit, convert them in int
 * and set the value 'to_set'
 * @return
 * The new position of ptr
 */
static const char	*get_value(const char *ptr, int *to_set)
{
	while (ft_isdigit(*ptr))
		*to_set = *to_set * 10 + (*ptr++ - '0');
	return (ptr);
}

/**
 * @brief
 * As long as ptr value is a valid flag, update 'flags'
 * @return
 * The new position of ptr
 */
static const char	*get_flags(const char *ptr, t_flags *flags)
{
	while (ft_strchr("-+# ", *ptr))
	{
		if (*ptr == '-')
			flags->width.after = 1;
		else if (*ptr == '+')
			flags->plus = 1;
		else if (*ptr == ' ')
			flags->space = 1;
		else if (*ptr == '#')
			flags->hexa = "0x";
		ptr++;
	}
	return (ptr);
}

/**
 * @brief
 * Set the width value according to ptr
 * @return
 * The new position of ptr
 */
static const char	*get_width(const char *ptr, t_flags *flags)
{
	if (*ptr == '0')
	{
		flags->width.on = 1;
		flags->width.filler = '0';
		ptr++;
	}
	if (ft_isdigit(*ptr))
	{
		flags->width.on = 1;
		ptr = (get_value(ptr, &flags->width.val));
	}
	return (ptr);
}

const char	*parse_flags(const char *ptr, t_flags *flags)
{
	if (*ptr != '\0')
	{
		ptr = get_flags(ptr, flags);
		ptr = get_width(ptr, flags);
		if (*ptr == '.')
		{
			flags->prec.on = 1;
			ptr = (get_value(ptr + 1, &flags->prec.val));
		}
	}
	return (ptr);
}
