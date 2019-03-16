/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_pow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:54:14 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 19:00:39 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"

t_ftbi		*ftbi_pow(const t_ftbi *a, int exp)
{
	int		i;
	t_ftbi	*r;

	i = 0;
	if (exp < 0)
		return (ftbi_new_llong(0));
	FTBI_MALGRD(r = ftbi_new_llong(1));
	while (i < exp)
	{
		FTBI_MALGRD(ftbi_repl(&r, ftbi_mul(r, a)));
		i++;
	}
	return (r);
}
