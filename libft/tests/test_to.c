/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:04:54 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 00:32:09 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"
#include <stdio.h>

void print_atoil(char *str) {
	printf("int  -> '%s' -> '%d'\n", str, ft_atoi(str));
	printf("long -> '%s' -> '%ld'\n", str, ft_atol(str));
	ft_printf("\n");
}

void test_to_atoi()
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("----------------------------------------- TEST TO ATOI ----\n");

	print_atoil("");
	print_atoil("0");
	print_atoil("123");
	print_atoil("-123");
	print_atoil("--123");
	print_atoil("123a");
	print_atoil("123a456");
	print_atoil("2147483647");
	print_atoil("-2147483648");
	print_atoil("-2147483649");
}

int main()
{
	ft_printf("TO TESTS --\n");
	// ------------------------------------------------------------------------
	// ---------------------------------------------------------- TEST TO -----
	test_to_atoi();

	return 0;
}
