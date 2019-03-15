/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:27:47 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/13 20:35:49 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

extern int	test_num;

int			assert_int(int actual, int expected)
{
	if (actual != expected)
	{
		append_to_log("Test %3i: FAIL    %s\n                  actual=%i, expected=%i\n",
				test_num, g_unit_test_names[test_num], actual, expected);
		return (1);
	}
	return (0);
}

int			assert_size_t(size_t actual, size_t expected)
{
	if (actual != expected)
	{
		append_to_log("Test %3i: FAIL    %s\n                  actual=%lu, expected=%lu\n",
				test_num, g_unit_test_names[test_num], actual, expected);
		return (1);
	}
	return (0);
}

int			assert_long_long(long long actual, long long expected)
{
	if (actual != expected)
	{
		append_to_log("Test %3i: FAIL    %s\n                  actual=%lli, expected=%lli\n",
				test_num, g_unit_test_names[test_num], actual, expected);
		return (1);
	}
	return (0);
}

int			assert_str(char *actual, char *expected)
{
	if (strcmp(actual, expected) != 0)
	{
		append_to_log("Test %3i: FAIL    %s\n                  actual=\"%s\", expected=\"%s\"\n",
				test_num, g_unit_test_names[test_num], actual, expected);
		return (1);
	}
	return (0);
}
