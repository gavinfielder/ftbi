/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:50:27 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 18:44:07 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"

static int		borrow(t_ftbi *gt, size_t fori)
{
	if (gt->a[fori + 1] == '0')
		gt->a[fori + 1] += borrow(gt, fori + 1);
	gt->a[fori + 1] -= 1;
	return (10);
}

static t_ftbi	*sub_work(t_ftbi *gt, t_ftbi *lt)
{
	t_ftbi	*r;
	size_t	i;

	r = ftbi_new_llong(0);
	i = 0;
	while (i < gt->len)
	{
		if (i < lt->len)
		{
			if (gt->a[i] < lt->a[i])
				gt->a[i] += borrow(gt, i);
			ftbi_set_digit(r, i, gt->a[i] - lt->a[i] + '0');
		}
		else
			ftbi_set_digit(r, i, gt->a[i]);
		i++;
	}
	ftbi_trim_leading_zeros(r);
	return (r);
}

/*
** gt gets the greater absolute value. Return whether result is negative.
**   guaranteed precondition: a != b
** #--------#---------#----------#-------#------------#-----------------------#
** |   a    |    b    |  a->neg  | a > b | gt=a (xor) |  result is negative?  |
** #--------#---------#----------#-------#------------#-----------------------#
** |   456  |   321   |    0     |   1   |     1      |           0           |
** |  -456  |  -321   |    1     |   0   |     1      |           1           |
** |   321  |   456   |    0     |   0   |     0      |           1           |
** |  -321  |  -456   |    1     |   1   |     0      |           0           |
** #--------#---------#----------#-------#------------#-----------------------#
*/

static int		pick_gt_lt_and_return_neg(const t_ftbi *a,
					const t_ftbi *b, t_ftbi **gt, t_ftbi **lt)
{
	int	neg;

	if (ftbi_gt(a, b) ^ a->neg)
	{
		*gt = ftbi_copy(a);
		*lt = ftbi_copy(b);
		neg = a->neg;
	}
	else
	{
		*gt = ftbi_copy(b);
		*lt = ftbi_copy(a);
		neg = 1 - a->neg;
	}
	return (neg);
}

static t_ftbi	*delegate_to_add(const t_ftbi *a, const t_ftbi *b)
{
	t_ftbi	*tmp;
	t_ftbi	*r;

	tmp = ftbi_neg(b);
	r = ftbi_add(a, tmp);
	ftbi_del(&tmp);
	return (r);
}

t_ftbi			*ftbi_sub(const t_ftbi *a, const t_ftbi *b)
{
	t_ftbi	*r;
	t_ftbi	*gt;
	t_ftbi	*lt;
	int		neg;

	if (a == NULL || b == NULL)
		return (NULL);
	if (ftbi_eq(a, b))
		r = ftbi_new_llong(0);
	else if (a->neg == b->neg)
	{
		neg = pick_gt_lt_and_return_neg(a, b, &gt, &lt);
		r = sub_work(gt, lt);
		ftbi_del(&gt);
		ftbi_del(&lt);
		r->neg = neg;
	}
	else
		r = delegate_to_add(a, b);
	return (r);
}
