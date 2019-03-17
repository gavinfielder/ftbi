/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbf_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:11:01 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/16 16:31:06 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftbf.h"

t_ftbf			*ftbf_shiftdiv10(const t_ftbf *f, int pow)
{
	t_ftbi		*carry;
	t_ftbf		*r;

	if (f == NULL || pow <= 0)
		return (NULL);
	FTBI_MALGRD(r = ftbf_copy(f));
	FTBI_MALGRD(carry = ftbi_new_llong((pow > (int)(f->val->len)) ||
				(f->val->a[pow - 1] < '5') ? 0 : 1));
	FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_divpow10(f->val, (size_t)pow)));
	FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_add(r->val, carry)));
	r->exp += pow;
	ftbi_del(&carry);
	return (r);
}

t_ftbf			*ftbf_shiftmul10(const t_ftbf *f, int pow)
{
	t_ftbf	*r;

	if (f == NULL || pow <= 0)
		return (NULL);
	FTBI_MALGRD(r = ftbf_copy(f));
	FTBI_MALGRD(ftbi_repl(&(r->val), ftbi_mulpow10(f->val, (size_t)pow)));
	r->exp -= pow;
	return (r);
}
