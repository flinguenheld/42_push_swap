/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:10:23 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 18:22:26 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief
 * Print the given field according to the str current value and the va_list
 * argument.
 * Then update the total value.
 * Set value to -1 if there is an error.
 */
static void	pfield(const char *str, va_list params, t_flags flags, int *total)
{
	if (*str == 'd' || *str == 'i')
		*total += print_int(va_arg(params, int), flags);
	else if (*str == 'u')
		*total += print_uint(va_arg(params, unsigned), flags);
	else if (*str == 's')
		*total += print_string(va_arg(params, char *), flags);
	else if (*str == 'c')
		*total += print_char(va_arg(params, int), flags);
	else if (*str == 'p')
		*total += print_pointer(va_arg(params, unsigned long), flags);
	else if (*str == 'x')
		*total += print_hexa(va_arg(params, unsigned int), flags, 0, 1);
	else if (*str == 'X')
		*total += print_hexa(va_arg(params, unsigned int), flags, 1, 1);
	else if (*str == '%')
		*total += putchar_count('%', flags);
	else
		*total = -1;
}

/**
 * @brief
 * Recursively print the current character or call pfield if the char is a %.
 * Update the total value for each printed char.
 */
static void	run(int fd, const char *str, va_list params, int *total)
{
	t_flags	flags;

	flags = init_flags(fd);
	if (*str == '\0')
	{
		va_end(params);
		return ;
	}
	else if (*str == '%')
	{
		str++;
		str = parse_flags(str, &flags);
		pfield(str, params, flags, total);
		if (*total == -1)
			return ;
	}
	else
		*total += putchar_count(*str, flags);
	run(fd, str + 1, params, total);
}

int	ft_printf_fd(int file_descriptor, const char *str, va_list params)
{
	int		total;

	if (str == NULL)
		return (-1);
	total = 0;
	run(file_descriptor, str, params, &total);
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;

	va_start(params, str);
	return (ft_printf_fd(1, str, params));
}

int	ft_printf_err(const char *str, ...)
{
	va_list	params;

	va_start(params, str);
	return (ft_printf_fd(2, str, params));
}
