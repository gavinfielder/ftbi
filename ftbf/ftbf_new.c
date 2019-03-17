/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbf_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:41:08 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/16 19:16:02 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftbf.h"

t_ftbf				*ftbf_new_float(float f)
{
	t_ftbf		*r;
	t_ftbi		*tmp;
	int			exp2;

	if ((r = ftbf_check_special_float(f)))
		return (r);
	FTBI_MALGRD(r = (t_ftbf *)malloc(sizeof(t_ftbf)));
	exp2 = FTBF_GET_EXP_F(f);
	FTBI_MALGRD(r->val = ftbi_new_ullong(FTBF_MASK_MTS_F(f)));
	FTBI_MALGRD(tmp = ftbi_new_pow(5, FTBF_MBITS_F));
	FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_mul(tmp, r->val)));
	FTBI_MALGRD(ftbi_repl(&tmp, ftbi_new_pow(2, FTBF_ABS(exp2))));
	if (exp2 >= 0)
	{
		FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_mul(tmp, r->val)));
	}
	else
	{
		FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_div(r->val, tmp)));
	}
	r->exp = -FTBF_MBITS_F;
	r->val->neg = (f < 0 ? 1 : 0);
	r->special = FTBF_NORMAL;
	ftbi_del(&tmp);
	return (r);
}

t_ftbf				*ftbf_new_double(double f)
{
	t_ftbf		*r;
	t_ftbi		*tmp;
	int			exp2;

	if ((r = ftbf_check_special_double(f)))
		return (r);
	FTBI_MALGRD(r = (t_ftbf *)malloc(sizeof(t_ftbf)));
	exp2 = FTBF_GET_EXP_D(f);
	FTBI_MALGRD(r->val = ftbi_new_ullong(FTBF_MASK_MTS_D(f)));
	FTBI_MALGRD(tmp = ftbi_new_pow(5, FTBF_MBITS_D));
	FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_mul(tmp, r->val)));
	FTBI_MALGRD(ftbi_repl(&tmp, ftbi_new_pow(2, FTBF_ABS(exp2))));
	if (exp2 >= 0)
	{
		FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_mul(tmp, r->val)));
	}
	else
	{
		FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_div(r->val, tmp)));
	}
	r->exp = -FTBF_MBITS_D;
	r->val->neg = (f < 0 ? 1 : 0);
	r->special = FTBF_NORMAL;
	ftbi_del(&tmp);
	return (r);
}

t_ftbf				*ftbf_new_ldouble(long double f)
{
	t_ftbf		*r;
	t_ftbi		*tmp;
	int			exp2;

	if ((r = ftbf_check_special_ldouble(f)))
		return (r);
	FTBI_MALGRD(r = (t_ftbf *)malloc(sizeof(t_ftbf)));
	exp2 = FTBF_GET_EXP_LD(f);
	FTBI_MALGRD(r->val = ftbi_new_ullong(FTBF_MASK_MTS_LD(f)));
	FTBI_MALGRD(tmp = ftbi_new_pow(5, FTBF_MBITS_LD));
	FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_mul(tmp, r->val)));
	FTBI_MALGRD(ftbi_repl(&tmp, ftbi_new_pow(2, FTBF_ABS(exp2))));
	if (exp2 >= 0)
	{
		FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_mul(tmp, r->val)));
	}
	else
	{
		FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_div(r->val, tmp)));
	}
	r->exp = -FTBF_MBITS_LD;
	r->val->neg = (f < 0 ? 1 : 0);
	r->special = FTBF_NORMAL;
	ftbi_del(&tmp);
	return (r);
}
