/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:04:54 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 11:51:34 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"
#include <limits.h>
#include <stdio.h>

// ls *.c *.h | grep -v "main" | while read -r FILE; do norminette "$FILE"; done

void space(char *str) {
	printf("\n\n\n\e[0;33m");
	printf("##########################################################################\n");
	printf("##########################################################################\n");
	printf("######################################################  %s  ##\e[0;0m\n", str);
}

void comparison_simple(char *what)
{
	printf("\n\x1B[34m-------------------------- '%s' --\x1B[0m\n", what);
	int real = printf(what);
	printf("\n");
	int mine = ft_printf(what);
	if (real != mine)
		printf("\n\x1B[31mFAIL %d -> %d\x1B[0m\n", real, mine);
}

void test_simple()
{
	comparison_simple(NULL);
	comparison_simple("");
	comparison_simple("blah");

	comparison_simple("%");
	comparison_simple("kkkkkk%");
	comparison_simple("kkkkkk%%");
	comparison_simple("kkkkkk%%kkkkkk%%kkkkkk%%");
	comparison_simple("kkkkkk%%kkkkkk%%kkkkkk%");
	comparison_simple("%%");
	comparison_simple("//%5%//");
	comparison_simple("//%-5%//");
	comparison_simple("//%-05%//");
	comparison_simple("//%-0.5%//");
	comparison_simple("//%+-0.5%//");
	comparison_simple("%%%");
	comparison_simple("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
	comparison_simple(" %% //");
	comparison_simple(" %%%% //");
	comparison_simple(" %% %% %% //");
	comparison_simple(" %%  %%  %% //");
	comparison_simple(" %%   %%   %% //");
	comparison_simple("%%//");
	comparison_simple("%% %%//");
}

void comparison_decimal(char *what, int value)
{
	printf("\n\x1B[34m-------------------------- '%s' on '%d' --\x1B[0m\n", what, value);
	int real = printf(what, value);
	printf("\n");
	int mine = ft_printf(what, value);
	if (real != mine)
		printf("\n\x1B[31mFAIL %d -> %d\x1B[0m\n", real, mine);
}

void test_decimal()
{
	comparison_decimal("%d",            123);
	comparison_decimal("%d",            -321);
	comparison_decimal("%d",            9);

	comparison_decimal("%d//",          0);
	comparison_decimal("%.d//",         0);
	comparison_decimal("%.0d//",        0);
	comparison_decimal("%.1d//",        0);
	comparison_decimal("%0d//",         0);
	comparison_decimal("%01d//",        0);

	comparison_decimal("%+d",           0);
	comparison_decimal("%+d",           321);
	comparison_decimal("%+d",           -321);

	comparison_decimal("%05d",          123);
	comparison_decimal("%010d",         321);
	comparison_decimal("%010d",         -321);
	comparison_decimal("%01d",          -321);

	comparison_decimal("%5d",           123);
	comparison_decimal("%10d",          321);
	comparison_decimal("%10d",          -321);
	comparison_decimal("%1d",           -321);

	comparison_decimal("%-10daaa",      -321);
	comparison_decimal("%+-1daaa",      -321);

	comparison_decimal("%.10d",         -321);
	comparison_decimal("%.10d",         123);
	comparison_decimal("%.1d",          -321);
	comparison_decimal("%.1d",          789);
	comparison_decimal("%.0d",          789);

	comparison_decimal("%20.10d",       -654);
	comparison_decimal("%20.10d",       456);

	comparison_decimal("%-20.10daaa",   -654);
	comparison_decimal("%-20.10daaa",   456);

	comparison_decimal("%+-20.10daaa",  -654);
	comparison_decimal("%+-20.10daaa",  456);

	comparison_decimal("%+20.10daaa",   -654);
	comparison_decimal("%+20.10daaa",   456);

	comparison_decimal("%d",            INT_MAX);
	comparison_decimal("%d",            INT_MIN);

	comparison_decimal("%.50d",         INT_MAX);
	comparison_decimal("%.50d",         INT_MIN);

	comparison_decimal("%100.50d",      INT_MAX);
	comparison_decimal("%100.50d",      INT_MIN);

	comparison_decimal("%0100d",        INT_MAX);
	comparison_decimal("%0100d",        INT_MIN);

	comparison_decimal("%0100.50d",     INT_MAX);
	comparison_decimal("%0100.50d",     INT_MIN);

	comparison_decimal("%+100.50d",     INT_MAX);
	comparison_decimal("%+100.50d",     INT_MIN);

	comparison_decimal("%+-100.50daaa", INT_MAX);
	comparison_decimal("%+-100.50daaa", INT_MIN);

	comparison_decimal("%.d//",          123);
	comparison_decimal("%.0d//",         123);
	comparison_decimal("%.1d//",         123);

	
	comparison_decimal("%08.3i//",        8375);
	comparison_decimal("%08.3i//",        -8473);
	comparison_decimal("%.0i//",          0);
	comparison_decimal("%.i//",           0);
	comparison_decimal("%5.0i//",         0);
	comparison_decimal("%5.i//",          0);
	comparison_decimal("%-5.0i//",        0);
	comparison_decimal("%-5.i//",         0);
	comparison_decimal("%08.3d//",        8375);
	comparison_decimal("%08.3d//",        -8473);
	comparison_decimal("%.0d//",          0);
	comparison_decimal("%.d//",           0);
	comparison_decimal("%.d//",           5);
	comparison_decimal("%5.0d//",         0);
	comparison_decimal("%5.d//",          0);
	comparison_decimal("%-5.0d//",        0);
	comparison_decimal("%-5.d//",         0);
	
	comparison_decimal("%- 12.10i //", 1234567890);
	comparison_decimal("%-12.10i //",  1234567890);

	comparison_decimal("% i",  123);

	comparison_decimal("%01.d//", 0);
	comparison_decimal("%01.0d//", 0);
	comparison_decimal("%02.0d//", 0);
	comparison_decimal("%03.0d//", 0);
	comparison_decimal("%01.i//", 0);
	comparison_decimal("%02.0i//", 0);

	comparison_decimal(" %012d //", LONG_MIN);
	// comparison_decimal(" %09d %010d %011d %012d %013d %014d %015d//", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	comparison_decimal(" %013i //", UINT_MAX);
}

void comparison_unsigned(char *what, unsigned int value)
{
	printf("\n\x1B[34m-------------------------- '%s' on '%u' --\x1B[0m\n", what, value);
	int real = printf(what, value);
	printf("\n");
	int mine = ft_printf(what, value);
	if (real != mine)
		printf("\n\x1B[31mFAIL %d -> %d\x1B[0m\n", real, mine);
}

void test_unsigned()
{
	comparison_unsigned("%u",            123);
	comparison_unsigned("%u",            -321);

	comparison_unsigned("%u",            UINT_MAX);
	comparison_unsigned("%u",            0);
	

	comparison_unsigned("%+u",           0);
	comparison_unsigned("%+u",           321);
	comparison_unsigned("%+u",           -321);

	comparison_unsigned("%u",            UINT_MAX);
	comparison_unsigned("%.50u",         UINT_MAX);
	comparison_unsigned("%100.50u",      UINT_MAX);
	comparison_unsigned("%0100u",        UINT_MAX);
	comparison_unsigned("%0100.50u",     UINT_MAX);
	comparison_unsigned("%+100.50u",     UINT_MAX);
	comparison_unsigned("%+-100.50uaaa", UINT_MAX);

	comparison_unsigned(" %01u //", 0);
	comparison_unsigned(" %013u //", UINT_MAX);
}

void comparison_char(char *what, char value)
{
	printf("\n\x1B[34m-------------------------- '%s' on '%d' --\x1B[0m\n", what, value);
	int real = printf(what, value);
	printf("\n");
	int mine = ft_printf(what, value);
	if (real != mine)
		printf("\n\x1B[31mFAIL %d -> %d\x1B[0m\n", real, mine);
}

void test_char()
{
	comparison_char("%c",        'x');
	comparison_char("%+c",       'x');
	comparison_char("%10c",      'x');
	comparison_char("%010c",     'x');
	comparison_char("%.10c",     'x');
	comparison_char("%-.10cbbb", 'x');
	comparison_char("%-10cbbb",  'x');
}

void comparison_string(char *what, char *value)
{
	printf("\n\x1B[34m-------------------------- '%s' on '%s' --\x1B[0m\n", what, value);
	int real = printf(what, value);
	printf("\n");
	int mine = ft_printf(what, value);
	if (real != mine)
		printf("\n\x1B[31mFAIL %d -> %d\x1B[0m\n", real, mine);
}

void test_string()
{
	comparison_string("%s",           "");
	comparison_string("%s",           NULL);

	comparison_string("++%s//",       NULL);
	comparison_string("++%10s//",     NULL);
	comparison_string("++%-10s//",    NULL);
	comparison_string("++%.10s//",    NULL);
	comparison_string("++%.2s//",     NULL);
	comparison_string("++%.6s//",     NULL);
	comparison_string("++%10s//",     NULL);
	comparison_string("++%10.10s//",  NULL);
	comparison_string("++%-10.10s//", NULL);

	comparison_string("\\%.s\\",          NULL);
	comparison_string("\\%.s\\",          "hello");
	comparison_string("\\%.0s\\",         "hello");
	comparison_string("\\%.s\\",          "NULL");
	comparison_string("\\%.0s\\",         "NULL");
	comparison_string("\\%.03s\\",        NULL);
	comparison_string("\\%3.s\\",         NULL);
	comparison_string("\\%10.s\\",        NULL);
	comparison_string("\\%-3.s\\",        NULL);
	comparison_string("\\%-8.s\\",        NULL);
	comparison_string("\\%3.1s\\",        NULL);
	comparison_string("\\%9.1s\\",        NULL);

	comparison_string("++%s//",       "");
	comparison_string("++%10s//",     "");
	comparison_string("++%-10s//",    "");
	comparison_string("++%.10s//",    "");
	comparison_string("++%10s//",     "");
	comparison_string("++%10.10s//",  "");
	comparison_string("++%-10.10s//", "");

	comparison_string("++%10s//",     "1");
	comparison_string("++%10.10s//",  "1");
	comparison_string("++%-10.10s//", "1");

	comparison_string("%s",           "king of the pirates");
	comparison_string("%+s",          "king of the pirates");
	comparison_string("%10s",         "king of the pirates");
	comparison_string("%050s",        "king of the pirates");
	comparison_string("%-50s///",     "king of the pirates");
	comparison_string("%.10s",        "king of the pirates");
	comparison_string("%-.10s///",    "king of the pirates");
	comparison_string("%-10s///",     "king of the pirates");
	comparison_string("%.1s",         "king of the pirates");
	comparison_string("%10.1s",       "king of the pirates");
	comparison_string("%-10.1s///",   "king of the pirates");

	comparison_string("some naugty tests: %s", "0000%");
	comparison_string("some naugty tests: %s", "    %");
	comparison_string("some naugty tests: %s", "%000");
}

void test_hexa()
{
	comparison_decimal("%x",            123);
	comparison_decimal("%x",            -321);

	comparison_decimal("%#x",           123);
	comparison_decimal("%#x",           -321);

	comparison_decimal("%#x",           123);
	comparison_decimal("%#x",           -321);

	comparison_decimal("%+#x",          0);

	comparison_decimal("%#x",           0);

	comparison_decimal("%.x",           0);
	comparison_decimal("%.x",           1);
	// comparison_decimal("%.#x",          0);
	// comparison_decimal("%.#x",          1);
	// comparison_decimal("%.#x",          123);

	comparison_decimal("%.0x",           0);
	comparison_decimal("%.0x",           1);
	// comparison_decimal("%.0#x",          0);
	// comparison_decimal("%.0#x",          1);
	// comparison_decimal("%.0#x",          123);

	comparison_decimal("%#.0x",          0);
	comparison_decimal("%#.0x",          1);
	comparison_decimal("%#.0x",          123);

	// return;

	comparison_decimal("%+x",           321);
	comparison_decimal("%+x",           -321);

	comparison_decimal("%05x",          123);
	comparison_decimal("%010x",         321);
	comparison_decimal("%010x",         -321);
	comparison_decimal("%01x",          -321);

	comparison_decimal("%#5x",          123);
	comparison_decimal("%#10x",         321);
	comparison_decimal("%#10x",         -321);
	comparison_decimal("%#1x",          -321);

	comparison_decimal("%-10xaaa",      -321);
	comparison_decimal("%+-1xaaa",      -321);

	comparison_decimal("%.10x",         -321);
	comparison_decimal("%.10x",         123);
	comparison_decimal("%.1x",          -321);

	comparison_decimal("%20.10x",       -654);
	comparison_decimal("%20.10x",       456);

	comparison_decimal("%-20.10xaaa",   -654);
	comparison_decimal("%-20.10xaaa",   456);

	comparison_decimal("%+-20.10xaaa",  -654);
	comparison_decimal("%+-20.10xaaa",  456);

	comparison_decimal("%+20.10xaaa",   -654);
	comparison_decimal("%+20.10xaaa",   456);

	comparison_decimal("%x",            INT_MAX);
	comparison_decimal("%x",            INT_MIN);

	comparison_decimal("%.7x",          INT_MAX / 4);
	comparison_decimal("%.7x",          INT_MIN / 4);

	comparison_decimal("%100.50x",      INT_MAX);
	comparison_decimal("%100.50x",      INT_MIN);

	comparison_decimal("%#0100x",       INT_MAX);
	comparison_decimal("%#0100x",       INT_MIN);

	comparison_decimal("%0100.50x",     INT_MAX);
	comparison_decimal("%0100.50x",     INT_MIN);

	comparison_decimal("%+100.50x",     INT_MAX);
	comparison_decimal("%+100.50x",     INT_MIN);

	comparison_decimal("%+-100.50xaaa", INT_MAX);
	comparison_decimal("%+-100.50xaaa", INT_MIN);

	comparison_decimal(" %01x //",      0);
	comparison_decimal(" %013x //",     UINT_MAX);
}

void test_hexa_uppercase()
{
	comparison_decimal("%X",            123);
	comparison_decimal("%X",            -321);

	comparison_decimal("%#X",           123);
	comparison_decimal("%#X",           -321);

	comparison_decimal("%#X",           123);
	comparison_decimal("%#X",           -321);

	comparison_decimal("%+#X",          0);
	comparison_decimal("%+#X",          0);

	comparison_decimal("%#X",           0);
	comparison_decimal("%#X",           0);

	comparison_decimal("%+X",           321);
	comparison_decimal("%+X",           -321);

	comparison_decimal("%05X",          123);
	comparison_decimal("%010X",         321);
	comparison_decimal("%010X",         -321);
	comparison_decimal("%01X",          -321);

	comparison_decimal("%#5X",          123);
	comparison_decimal("%#10X",         321);
	comparison_decimal("%#10X",         -321);
	comparison_decimal("%#1X",          -321);

	comparison_decimal("%-10Xaaa",      -321);
	comparison_decimal("%+-1Xaaa",      -321);

	comparison_decimal("%.10X",         -321);
	comparison_decimal("%.10X",         123);
	comparison_decimal("%.1X",          -321);

	comparison_decimal("%20.10X",       -654);
	comparison_decimal("%20.10X",       456);

	comparison_decimal("%-20.10Xaaa",   -654);
	comparison_decimal("%-20.10Xaaa",   456);

	comparison_decimal("%+-20.10Xaaa",  -654);
	comparison_decimal("%+-20.10Xaaa",  456);

	comparison_decimal("%+20.10Xaaa",   -654);
	comparison_decimal("%+20.10Xaaa",   456);

	comparison_decimal("%X",            INT_MAX);
	comparison_decimal("%X",            INT_MIN);

	comparison_decimal("%.7X",          INT_MAX / 4);
	comparison_decimal("%.7X",          INT_MIN / 4);

	comparison_decimal("%100.50X",      INT_MAX);
	comparison_decimal("%100.50X",      INT_MIN);

	comparison_decimal("%#0100X",       INT_MAX);
	comparison_decimal("%#0100X",       INT_MIN);

	comparison_decimal("%0100.50X",     INT_MAX);
	comparison_decimal("%0100.50X",     INT_MIN);

	comparison_decimal("%+100.50X",     INT_MAX);
	comparison_decimal("%+100.50X",     INT_MIN);

	comparison_decimal("%+-100.50Xaaa", INT_MAX);
	comparison_decimal("%+-100.50Xaaa", INT_MIN);

	comparison_decimal(" %01X //",      0);
	comparison_decimal(" %013X //",     UINT_MAX);
}

void comparison_pointer(char *what, unsigned long address)
{
	printf("\n\x1B[34m-------------------------- '%s' on '%lu' --\x1B[0m\n", what, address);
	int real = printf(what, address);
	printf("\n");
	int mine = ft_printf(what, address);
	if (real != mine)
		printf("\n\x1B[31mFAIL %d -> %d\x1B[0m\n", real, mine);
}

void test_pointer()
{
	// comparison_pointer("%p",                     NULL);
	comparison_pointer("%p",                     0);
	comparison_pointer("%p",                     1);
	comparison_pointer("%p",                     2);
	comparison_pointer("%p",                     INT_MAX);
	comparison_pointer("%p",                     INT_MIN);
	comparison_pointer("%p",                     LONG_MAX);
	comparison_pointer("%p",                     LONG_MIN);

	// comparison_pointer("//%20p//",               NULL);
	// comparison_pointer("//%+p//",                NULL);
	// comparison_pointer("//%+#p//",               NULL);
	// comparison_pointer("//%-50p//",              NULL);
	// comparison_pointer("//%+#-50p//",            NULL);
	// comparison_pointer("//%-20p//",              NULL);
	// comparison_pointer("//%.10p//",              NULL);
	// comparison_pointer("//%-20.3p//",            NULL);
	// comparison_pointer("//%.2p//",               NULL);

	comparison_pointer("%p",                     0);
	comparison_pointer("//%20p//",               0);
	comparison_pointer("//%+p//",                0);
	comparison_pointer("//%+#p//",               0);
	comparison_pointer("//%-50p//",              0);
	comparison_pointer("//%+#-50p//",            0);
	comparison_pointer("//%-20p//",              0);
	comparison_pointer("//%.10p//",              0);
	comparison_pointer("//%-20.3p//",            0);
	comparison_pointer("//%.2p//",               0);

	comparison_pointer("%p",           (unsigned long)&"aaa");
	comparison_pointer("//%20p//",     (unsigned long)(&"aab" + 651546321654321592));
	comparison_pointer("//%+p//",      (unsigned long)(&"aac" + 154287265452723215));
	comparison_pointer("//%+#p//",     (unsigned long)(&"aad" + 6542 * 158984));
	comparison_pointer("//%-50p//",    (unsigned long)(&"aae" + 654546321654321621));
	comparison_pointer("//%+#-50p//",  (unsigned long)(&"aaf" + 654546321654321621));
	comparison_pointer("//%-20p//",    (unsigned long)(&"aag" + 654546321654321621));
	comparison_pointer("//%.3p//",     (unsigned long)(&"aah" + 654546321654321621));
	comparison_pointer("//%-20.2p//",  (unsigned long)(&"aai" + 654546321654321621));

	comparison_pointer("//%.20p//",  50);
	comparison_pointer("//%+p//",  50);
}

void comparison_multiple()
{

	printf("\n\x1B[34m-------------------------- MULTIPLE --\x1B[0m\n");
	printf("\n");
	   printf("hello %d %s %u %c %p %x %X", 123, "abc", 456, 'a', NULL, 0, 123);
	printf("\n");
	ft_printf("hello %d %s %u %c %p %x %X", 123, "abc", 456, 'a', NULL, 0, 123);
	printf("\n");
	
	
	printf("\n");
	   printf("hello %.10d %.s %+u %c %020p %-x %.5X", 123, "abc", 456, 'a', NULL, 0, 123);
	printf("\n");
	ft_printf("hello %.10d %.s %+u %c %020p %-x %.5X", 123, "abc", 456, 'a', NULL, 0, 123);
	printf("\n");

	printf("\n");
	   printf("hello %.10d %010.2d %-20.5s", 123, 789, "goodbye");
	printf("\n");
	ft_printf("hello %.10d %010.2d %-20.5s", 123, 789, "goodbye");
	printf("\n");

	printf("\n");
	   printf("hello %+.10d %010.2d %-20.5s", 123, 789, "goodbye");
	printf("\n");
	ft_printf("hello %+.10d %010.2d %-20.5s", 123, 789, "goodbye");
	printf("\n");

	printf("\n");
	   printf("hello %+.10d %010.2d %-20.5s", 123, 789, NULL);
	printf("\n");
	ft_printf("hello %+.10d %010.2d %-20.5s", 123, 789, NULL);
	printf("\n");
}

int main()
{
	ft_printf("PRINTF TESTS --\n");
	// ------------------------------------------------------------------------
	// ------------------------------------------------------ TEST PRINTF -----

	space("SIMPLE");
	test_simple();

	// return 0;

	space("DECIMAL");
	test_decimal();

	// return 0;

	space("UNSIGNED");
	test_unsigned();

	// return 0;

	space("CHAR");
	test_char();

	// return 0;

	space("STRING");
	test_string();

	// return 0;

	space("HEXA");
	test_hexa();

	// return 0;

	space("HEXA UPPERCASE");
	test_hexa_uppercase();

	// return 0;

	space("POINTER");
	test_pointer();

	// return 0;

	comparison_multiple();

	return 0;
}
