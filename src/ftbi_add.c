/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:01:35 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 00:30:51 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"

static void		add_work(const t_ftbi *a, const t_ftbi *b, t_ftbi *r)
{
	int		digsum;
	int		carry;
	size_t	i;

	i = 0;
	carry = 0;
	while (i < a->len || i < b->len || carry > 0)
	{
		if (i < a->len && i < b->len)
			digsum = (a->a[i] - '0') + (b->a[i] - '0') + carry;
		else if (i < a->len)
			digsum = a->a[i] - '0' + carry;
		else if (i < b->len)
			digsum = b->a[i] - '0' + carry;
		else
			digsum = carry;
		carry = digsum / 10;
		ftbi_set_digit(r, i, (digsum % 10) + '0');
		i++;
	}
}

static t_ftbi	*delegate_to_sub(const t_ftbi *a, const t_ftbi *b)
{
	t_ftbi	*tmp;
	t_ftbi	*r;

	if (a->neg)
	{
		tmp = ftbi_neg(a);
		r = ftbi_sub(b, tmp);
	}
	else
	{
		tmp = ftbi_neg(b);
		r = ftbi_sub(a, tmp);
	}
	ftbi_del(&tmp);
	return (r);
}

t_ftbi	*ftbi_add(const t_ftbi *a, const t_ftbi *b)
{
	t_ftbi	*r;

	if (a == NULL || b == NULL)
		return (NULL);
	if (a->neg == b->neg)
	{
		r = ftbi_new_llong(0);
		add_work(a, b, r);
		r->neg = a->neg;
	}
	else
		r = delegate_to_sub(a, b);
	return (r);
}
