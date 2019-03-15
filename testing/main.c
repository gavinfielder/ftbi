/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:55:10 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 17:11:48 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	freeform_test(int argc, char **argv);

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	run_all_tests();
	//freeform_test(argc, argv);
	//while (1);
	return (0);
}


void	freeform_test(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_ftbi *bi = ftbi_new_llong(99999);
	int to_add = 99;
	size_t place = 1;
	printf("old=%lli, to_add=%i, place=%lu, ", ftbi_to_ll(bi), to_add, place);
	//add_to_nplace(bi, to_add, place);
	printf("new=%lli\n", ftbi_to_ll(bi));
}
