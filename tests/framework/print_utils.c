/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:41:57 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/14 14:53:24 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	print_close_frame_right(int already_printed)
{
	int	len;

	len = 71 - already_printed;
	while (len--)
		ft_printf(" ");
	ft_printf("=====\n");
}

void	print_frame_line(int empty)
{
	int	length;

	length = 80;
	if (empty == 1)
		ft_printf("=====% 70c=====\n", ' ');
	else
	{
		while (length--)
			ft_printf("=");
		ft_printf("\n");
	}
}
