/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:44:17 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/15 19:30:20 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libftbi.h"
# include "ftbf.h"

# define TEST_OUTPUT_FILENAME "test_results.txt"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

//Unit test definition
typedef	int	(* t_unit_test) (void);
//Unit test array
extern const t_unit_test	g_unit_tests[];
extern const char *g_unit_test_names[];
//Primary functions
void		run_all_tests(void);
void		run_tests(int from_num, int to_num);
long long	ftbi_to_ll(t_ftbi *bi);
void		append_to_log(const char *fmt, ...);
//Assertion Functions
int			assert_int(int actual, int expected);
int			assert_size_t(size_t actual, size_t expected);
int			assert_long_long(long long actual, long long expected);
int			assert_str(char *actual, char *expected);

//printing
void				print_bits(unsigned long *p, unsigned long start,
						unsigned long stop, int dot);

void				ftbi_debug_print(t_ftbi *bi);

#endif











