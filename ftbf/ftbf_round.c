/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbf_round.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:00:53 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/16 20:58:12 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftbf.h"

/*
** prec is the negative of the exponent we want to be at
*/

t_ftbf		*ftbf_round(const t_ftbf *f, int prec)
{
	t_ftbf	*r;

	if (f == NULL)
		return (NULL);
	if ((f->special == FTBF_POSZERO || f->special == FTBF_NEGZERO)
			&& prec > 0)
	{
		r = ftbf_copy(f);
		r->exp = -prec;
	}
	else if (f->special || -(f->exp) == prec)
		r = ftbf_copy(f);
	else if (-(f->exp) > prec)
		r = ftbf_shiftdiv10(f, -(f->exp) - prec);
	else
		r = ftbf_shiftmul10(f, prec + f->exp);
	return (r);
}
