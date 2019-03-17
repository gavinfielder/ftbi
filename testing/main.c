/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:55:10 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/16 17:09:38 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	freeform_test(int argc, char **argv);
void	unit_testing(int argc, char **argv);


int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	unit_testing(argc, argv);
	//freeform_test(argc, argv);
	//while (1);
	return (0);
}

void	freeform_test(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	long double f = 64.75;
	if (argc > 1)
		f = (long double)atof(argv[1]);
	t_ftbf *bf = ftbf_new_ldouble(f);
	ftbf_print(bf);
	write(1, "\n", 1);
	ftbf_del(&bf);
}

void	unit_testing(int argc, char **argv)
{
	int from, to;
	if (argc > 1)
	{
		from = atoi(argv[1]);
		if (argc > 2)
			to = atoi(argv[2]);
		else
			to = -1;
		run_tests(from, to);
	}
	else
	{
		run_all_tests();
	}
}

