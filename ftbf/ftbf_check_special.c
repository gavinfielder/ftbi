/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbf_check_special.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:32:10 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/16 19:16:40 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftbf.h"

/*
** All of these functions return a valid ftbf if it is a special value,
** and return NULL if it is a normal (non-special) value.
*/

t_ftbf		*ftbf_check_special_float(float f)
{
	t_ftbf	*r;

	FTBI_MALGRD(r = (t_ftbf *)malloc(sizeof(t_ftbf)));
	FTBI_MALGRD(r->val = ftbi_new_llong(0));
	r->exp = 0;
	r->val->neg = FTBF_GET_SGN_F(f);
	r->special = FTBF_NORMAL;
	if (FTBF_MASK_EXP_F(f) >> FTBF_MBITS_F == 0
			&& FTBF_RAW_MASK_MTS_F(f) == 0)
		r->special = (r->val->neg ? FTBF_NEGZERO : FTBF_POSZERO);
	else if (FTBF_MASK_EXP_F(f) >> FTBF_MBITS_F == 0xFF
			&& FTBF_RAW_MASK_MTS_F(f) == 0)
		r->special = (r->val->neg ? FTBF_NEGINF : FTBF_POSINF);
	else if (FTBF_MASK_EXP_F(f) >> FTBF_MBITS_F == 0xFF
			&& FTBF_RAW_MASK_MTS_F(f) != 0)
		r->special = FTBF_NAN;
	if (r->special == FTBF_NORMAL)
		ftbf_del(&r);
	return (r);
}

t_ftbf		*ftbf_check_special_double(double f)
{
	t_ftbf	*r;

	FTBI_MALGRD(r = (t_ftbf *)malloc(sizeof(t_ftbf)));
	FTBI_MALGRD(r->val = ftbi_new_llong(0));
	r->exp = 0;
	r->val->neg = FTBF_GET_SGN_D(f);
	r->special = FTBF_NORMAL;
	if (FTBF_MASK_EXP_D(f) >> FTBF_MBITS_D == 0
			&& FTBF_RAW_MASK_MTS_D(f) == 0)
		r->special = (r->val->neg ? FTBF_NEGZERO : FTBF_POSZERO);
	else if (FTBF_MASK_EXP_D(f) >> FTBF_MBITS_D == 0x7FF
			&& FTBF_RAW_MASK_MTS_D(f) == 0)
		r->special = (r->val->neg ? FTBF_NEGINF : FTBF_POSINF);
	else if (FTBF_MASK_EXP_D(f) >> FTBF_MBITS_D == 0x7FF
			&& FTBF_RAW_MASK_MTS_D(f) != 0)
		r->special = FTBF_NAN;
	if (r->special == FTBF_NORMAL)
		ftbf_del(&r);
	return (r);
}

t_ftbf		*ftbf_check_special_ldouble(long double f)
{
	t_ftbf	*r;

	FTBI_MALGRD(r = (t_ftbf *)malloc(sizeof(t_ftbf)));
	FTBI_MALGRD(r->val = ftbi_new_llong(0));
	r->exp = 0;
	r->val->neg = FTBF_GET_SGN_LD(f);
	r->special = FTBF_NORMAL;
	if (FTBF_MASK_EXP_LD(f) == 0 && FTBF_MASK_MTS_LD(f) == 0)
		r->special = (r->val->neg ? FTBF_NEGZERO : FTBF_POSZERO);
	else if (FTBF_MASK_EXP_LD(f) == 0x7FFF && FTBF_MASK_MTS_LD(f) == 0)
		r->special = (r->val->neg ? FTBF_NEGINF : FTBF_POSINF);
	else if (FTBF_MASK_EXP_LD(f) == 0x7FFF && FTBF_MASK_MTS_LD(f) != 0)
		r->special = FTBF_NAN;
	if (r->special == FTBF_NORMAL)
		ftbf_del(&r);
	return (r);
}
