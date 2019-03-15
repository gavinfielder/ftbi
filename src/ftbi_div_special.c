/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_div_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:13:41 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 14:44:20 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"

t_ftbi	*ftbi_divpow10(const t_ftbi *a, size_t pow)
{
	t_ftbi	*r;
	size_t	i;

	i = 0;
	if ((r = ftbi_new_llong(0)) < 0)
		return (NULL);
	while (i < a->len)
	{
		if (i >= pow && ftbi_set_digit(r, i - pow, a->a[i]) < 0)
			return (ftbi_del_and_ret_null(1, &r));
		i++;
	}
	r->neg = a->neg;
	return (r);
}

t_ftbi	*ftbi_div2(const t_ftbi *a)
{
	t_ftbi	*carry;
	t_ftbi	*r;
	size_t	i;

	if (!(carry = ftbi_new_alloc(a->len)))
		return (NULL);
	if (!(r = ftbi_new_alloc(a->len)))
		return (NULL);
	i = 0;
	while (i < a->len)
	{
		if (ftbi_set_digit(r, i, ((a->a[i] - '0') / 2) + '0') < 0)
			return (ftbi_del_and_ret_null(2, &r, &carry));
		if (i > 0 && a->a[i] % 2 == 1 && ftbi_set_digit(carry, i - 1, '5') < 0)
			return (ftbi_del_and_ret_null(2, &r, &carry));
		i++;
	}
	ftbi_repl(&r, ftbi_add(r, carry));
	ftbi_del(&carry);
	ftbi_trim_leading_zeros(r);
	r->neg = a->neg;
	return (r);
}
