/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:04:54 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/04 21:30:02 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void test_is_integer()
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("---------------------------------- TEST IS INTEGER STR ----\n");

	ft_printf("% 10s  OK -> %d\n", "123", ft_is_integer("123"));
	ft_printf("% 10s NOK -> %d\n", "123   ", ft_is_integer("123   "));
	ft_printf("% 10s  OK -> %d\n", "-123", ft_is_integer("-123"));
	ft_printf("% 10s  OK -> %d\n", "   123", ft_is_integer("   123"));
	ft_printf("% 10s NOK -> %d\n", "+ 123", ft_is_integer("+ 123"));
	ft_printf("% 10s NOK -> %d\n", "123a", ft_is_integer("123a"));
	ft_printf("% 10s NOK -> %d\n", "1a23a", ft_is_integer("1a23a"));
	ft_printf("% 10s NOK -> %d\n", "one", ft_is_integer("one"));
	ft_printf("% 10s NOK -> %d\n", "   ", ft_is_integer("   "));
	ft_printf("% 10s  OK -> %d\n", "00000", ft_is_integer("00000"));
	ft_printf("% 10s  OK -> %d\n", "-00000", ft_is_integer("-00000"));
	ft_printf("% 10s  OK -> %d\n", "+00000", ft_is_integer("+00000"));
	ft_printf("% 10s NOK -> %d\n", "++00000", ft_is_integer("++00000"));
	ft_printf("% 10s  OK -> %d\n", "0", ft_is_integer("0"));
	ft_printf("% 10s NOK -> %d\n", "+-123", ft_is_integer("+-123"));
	ft_printf("% 10s NOK -> %d\n", "   -", ft_is_integer("   -"));
}

int main()
{
	ft_printf("IS TESTS --\n");
	// ------------------------------------------------------------------------
	// ---------------------------------------------------------- TEST IS -----
	test_is_integer();

	return 0;
}
