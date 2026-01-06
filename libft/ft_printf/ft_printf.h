/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:10:23 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 18:28:49 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"

typedef struct s_precision
{
	char	on;
	int		val;
}	t_precision;

typedef struct s_width
{
	char	on;
	int		val;
	char	filler;
	char	after;
}	t_width;

typedef struct s_flags
{
	int			file_descriptor;
	t_precision	prec;
	t_width		width;
	char		plus;
	char		space;
	char		*hexa;
}	t_flags;

/* ****************************************************************************/
/* ************************************************************ PRINTF FD *****/
/**
 * @brief
 * Launch ft_printf logic in the given file descriptor.
 * Don't use this function directly, use instead:
 *   - ft_printf
 *   - ft_printf_err
 * @return
 * The amount of printed char or -1 if error
 */
int			ft_printf_fd(int fd, const char *str, va_list params);

/* ****************************************************************************/
/* **************************************************************** FLAGS *****/
/**
 * @brief
 * Loop in the given char to fill the t_flags struct.
 * It respects this logic:
 * [flags][width][.precision]type
 *   - Authorised flags are: -+ #
 *   - Width can be preceed with a 0
 *   - Precision mandatorily starts with a dot
 * @return
 * The ptr position after parsing
 */
const char	*parse_flags(const char *ptr, t_flags *flags);

/**
 * @brief
 * Set default flag values
 */
t_flags		init_flags(int file_descriptor);

/* ****************************************************************************/
/* ************************************************************** NUMBERS *****/
/**
 * @brief
 * Adapt flags to fit general requirements
 *   - hexa sign
 *   - width filler
 *   - Width
 *   - Precision
 * It can look absurd, c'est la vie though:
 *   - Specific case when precision is on with a value of 0 and number is 0
 *
 * It allows print_number to easily use width & precision values
 * @return
 * Updated flags
 */
t_flags		up_flags_number(char negative, char *unsigned_value, t_flags flags);

/**
 * @brief
 * That's tricky, so:
 * - Convert the value into a string
 * - Adapt the flags
 * - Then
 *     - add spaces
 *     - add sign or space if space flag
 *     - add zeroes
 *     - add the value
 *     - add spaces
 *  - Free string
 * @return
 * The amount of printed chars
 */
int			print_number(char negative, char *unsigned_value, t_flags flags);
/**
 * @brief
 * Print an int with all flags
 * @return
 * The amount of printed chars
 */
int			print_int(int value, t_flags flags);

/**
 * @brief
 * Print an unsinged int with all flags
 * @return
 * The amount of printed chars
 */
int			print_uint(unsigned int value, t_flags flags);

/* ****************************************************************************/
/* ***************************************************************** HEXA *****/
/**
 * @brief
 * Print the value in base 16.
 * You can display it in uppercase and activate or not the '+' flag
 * Otherwise, flags are the same as with decimal values
 * @return
 * The amount of printed chars
 */
int			print_hexa(unsigned long value, t_flags flags,
				char uppercase, char no_plus);

/* ****************************************************************************/
/* ************************************************************** POINTER *****/
/**
 * @brief
 * Print the address of ptr
 * It results as a lowercase hexadecimal value with the "0x" prefix
 * And it manages the zero value by printing '(nil)'.
 * @return
 * The amount of printed chars
 */
int			print_pointer(unsigned long address, t_flags flags);

/* ****************************************************************************/
/* **************************************************************** CHARS *****/
/**
 * @brief
 * Only a few flags are available with chars, so:
 *   - add spaces
 *   - add the value
 *   - add spaces
 * @return
 * The amount of printed chars
 */
int			print_char(char value, t_flags flags);

/* ****************************************************************************/
/* *************************************************************** STRING *****/
/**
 * @brief
 * Print a string and take care of three flags
 *   - Precision: max printed chars of the value
 *   - Width: Min string length filled with spaces
 *   - Minus: Add width after the string
 * @return
 * The amount of printed chars
 */
int			print_string(char *value, t_flags flags);

/* ****************************************************************************/
/* ************************************************************** UTILS *******/
/**
 * @brief
 * shorcut to write one char and return 1
 * @return
 * 1
 */
int			putchar_count(char c, t_flags flags);

/**
 * @brief
 * Sub b to a
 * @return
 * 0 if the result is lower than 0
 */
int			sub_min_zero(int a, int b);

/**
 * @brief
 * Return the smaller value
 */
int			mini(int a, int b);

#endif
