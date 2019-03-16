/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:07:12 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/15 19:31:21 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "libftbi.h"
#include "test.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int				test_num;

void	run_all_tests(void)
{
	run_tests(0, -1);
}

void	run_tests(int from_num, int to_num)
{
	test_num = from_num;
	if (to_num < from_num) to_num = 2147483647;
	int fail = 0;
	int num_fails = 0;
	int	num_run = 0;
	for (int i = from_num; i <= to_num && g_unit_tests[i] != NULL; i++)
	{
		printf("Test %3i:  %-42s [",test_num, g_unit_test_names[i]);
		fail = g_unit_tests[i]();
		if (fail)
			printf(RED "FAIL" RESET);
		else
			printf(GRN "PASS" RESET);
		printf("]\n");
		num_fails += fail;
		num_run++;
		test_num++;
	}
	printf("Tests completed. %i/%i tests passed.\n",
			num_run - num_fails, num_run);
	if (num_run - num_fails != num_run)
		printf("See %s for details.\n", TEST_OUTPUT_FILENAME);
}
long long	ftbi_to_ll(t_ftbi *bi)
{
	long long	val;
	int			sign;
	size_t		i;

	sign = (bi->neg ? -1 : 1);
	i = bi->len;
	val = 0;
	while (i-- > 0)
	{
		val = val * 10 + sign * (bi->a[i] - '0');
	}
	return (val);
}

void	append_to_log(const char *fmt, ...)
{
	va_list			args;
	int				fd;
	
	va_start(args, fmt);
	fd = open(TEST_OUTPUT_FILENAME, O_CREAT | O_WRONLY | O_APPEND,
				S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd > 0)
	{
		vdprintf(fd, fmt, args);
		close(fd);
	}
	va_end(args);
}

void	print_bits(unsigned long *p, unsigned long start,
				unsigned long stop, int dot)
{
	unsigned long mask;

	mask = (unsigned long)1 << (unsigned long)(stop);
	for (unsigned long i = start; i <= stop; i++)
	{
		if ((*p) & mask)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (dot && (i + 1) % 4 == 0)
			write(1, ".", 1);
		mask >>= 1;
	}
}

void	ftbi_debug_print(t_ftbi *bi)
{
	printf("bi->len=%lu; value is: ", bi->len);
	for (int i = 0; i < (int)(bi->len); i++)
	{
		printf("%c", bi->a[bi->len - i - 1]);
	}
	printf("\n");
}
