/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:55:10 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/15 21:03:32 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	freeform_test(int argc, char **argv);

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//run_all_tests();
	freeform_test(argc, argv);
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

/*
void	unit_testing(int argc, char **argv)
{
	if (argc > 1)
	{
		if (strcmp(argv[1], "float"))
*/
