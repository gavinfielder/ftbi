/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_div_backend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:03:11 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 17:08:59 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"

/*
** The functions in this file should only be called with non-negative numbers
*/

static int		is_one_away(const t_ftbi *a, const t_ftbi *c)
{
	t_ftbi	*ap1;
	int		ret;

	if (a == NULL || c == NULL || (ap1 = ftbi_new_llong(1)) == NULL)
		return (FTBI_ERR_GENERAL);
	ftbi_repl(&ap1, ftbi_add(ap1, a));
	if (ftbi_eq(ap1, c))
		ret = 1;
	else
		ret = 0;
	ftbi_del(&ap1);
	return (ret);
}

static void		init_helper(t_ftbi **b, t_ftbi **check)
{
	*b = NULL;
	*check = NULL;
}

t_ftbi			*ftbi_div_work(t_ftbi *num, t_ftbi *den, t_ftbi **mod)
{
	t_ftbi	*a;
	t_ftbi	*b;
	t_ftbi	*c;
	t_ftbi	*check;

	init_helper(&b, &check);
	a = (num->len > den->len ? ftbi_new_pow10(num->len - den->len - 1)
			: ftbi_new_llong(1));
	c = ftbi_new_pow10(num->len + 1 - den->len);
	while (!is_one_away(a, c))
	{
		ftbi_repl(&b, ftbi_add(a, c));
		ftbi_repl(&b, ftbi_div2(b));
		ftbi_repl(&check, ftbi_mul(b, den));
		if (ftbi_gteq(num, check))
			ftbi_repl(&a, ftbi_copy(b));
		else
			ftbi_repl(&c, ftbi_copy(b));
	}
	ftbi_repl(&check, ftbi_mul(a, den));
	*mod = ftbi_sub(num, check);
	ftbi_del_and_ret_null(3, &b, &c, &check);
	return (a);
}
