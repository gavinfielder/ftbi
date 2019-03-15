/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:51:36 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 17:06:40 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"

static t_ftbi	*del_and_return(t_ftbi **num, t_ftbi **den, t_ftbi *ret)
{
	ftbi_del(num);
	ftbi_del(den);
	return (ret);
}

t_ftbi			*ftbi_div(const t_ftbi *a, const t_ftbi *b)
{
	t_ftbi	*num;
	t_ftbi	*den;
	t_ftbi	*mod;
	t_ftbi	*r;

	FTBI_MALGRD2(a, b);
	if (ftbi_is_zero(b))
		return (NULL);
	FTBI_MALGRD(num = ftbi_copy(a));
	num->neg = 0;
	FTBI_MALGRD(den = ftbi_copy(b));
	den->neg = 0;
	if (ftbi_gt(den, num))
		return (del_and_return(&num, &den, ftbi_new_llong(0)));
	FTBI_MALGRD(r = ftbi_div_work(num, den, &mod));
	ftbi_del_and_ret_null(3, &num, &den, &mod);
	r->neg = a->neg ^ b->neg;
	return (r);
}

t_ftbi			*ftbi_mod(const t_ftbi *a, const t_ftbi *b)
{
	t_ftbi	*num;
	t_ftbi	*den;
	t_ftbi	*mod;
	t_ftbi	*r;

	FTBI_MALGRD2(a, b);
	if (ftbi_is_zero(b))
		return (NULL);
	FTBI_MALGRD(num = ftbi_copy(a));
	num->neg = 0;
	FTBI_MALGRD(den = ftbi_copy(b));
	den->neg = 0;
	if (ftbi_gt(den, num))
		return (del_and_return(&num, &den, ftbi_copy(a)));
	FTBI_MALGRD(r = ftbi_div_work(num, den, &mod));
	ftbi_del_and_ret_null(3, &num, &den, &r);
	mod->neg = a->neg;
	return (mod);
}

t_ftbi			*ftbi_divmod(const t_ftbi *a, const t_ftbi *b, t_ftbi **mod)
{
	t_ftbi	*num;
	t_ftbi	*den;
	t_ftbi	*r;

	FTBI_MALGRD2(a, b);
	if (ftbi_is_zero(b))
		return (NULL);
	FTBI_MALGRD(num = ftbi_copy(a));
	num->neg = 0;
	FTBI_MALGRD(den = ftbi_copy(b));
	den->neg = 0;
	if (ftbi_gt(den, num))
	{
		*mod = ftbi_copy(a);
		return (del_and_return(&num, &den, ftbi_new_llong(0)));
	}
	FTBI_MALGRD(r = ftbi_div_work(num, den, mod));
	ftbi_del_and_ret_null(2, &num, &den);
	r->neg = a->neg ^ b->neg;
	(*mod)->neg = a->neg;
	return (r);
}
