/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tghnassi <tghnassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:47:58 by tghnassi          #+#    #+#             */
/*   Updated: 2026/01/14 15:25:18 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	print_test_line(char *name, char *msg, char *color)
{
	printf("=====   [%s%s%s]  %s", color, msg, KNRM, name);
	print_close_frame_right(8 + strlen(msg) + strlen(name));
}

void	print_title(char *title)
{
	int	i;

	printf("\n");
	print_frame_line(0);
	i = 80 - (strlen(title) + 10);
	while (i--)
		printf("=");
	printf(" %s ========\n", title);
	print_frame_line(1);
}

void	print_local_counter(int counter, int total)
{
	int		red;
	int		green;
	char	*red_str;
	char	*green_str;

	green = ((float) counter / (float) total) * 120;
	red = 255 - green;
	if (counter == total)
		green = 255;
	if (!counter)
		red = 255;
	red_str = lu_ltobase(red, "0123456789");
	green_str = lu_ltobase(green, "0123456789");
	print_frame_line(1);
	printf("=====           ");
	printf("%s%s;%s%s% 4i success      % 4i fails      % 4i total%s",
		KSTA, red_str, green_str, KEND, counter, total - counter, total, KNRM);
	print_close_frame_right(8 + 48);
	print_frame_line(0);
	free(red_str);
	free(green_str);
}

void	print_final_counter(t_lu_counter *s_count)
{
	printf("=========================================");
	printf("======================== ");
	printf("%s255;0%sT%s200;50%sO%s150;100%sT",
		KSTA, KEND, KSTA, KEND, KSTA, KEND);
	printf("%s100;150%sA%s50;200%sL%s0;255%s%s",
		KSTA, KEND, KSTA, KEND, KSTA, KEND, KNRM);
	printf(" ========\n");
	print_local_counter(s_count->success, s_count->total);
}
