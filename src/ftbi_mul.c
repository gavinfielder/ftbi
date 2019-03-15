/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:39:54 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 14:04:55 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"

static void	add_to_nplace(t_ftbi *sum, int mul, size_t place)
{
	int		digit;

	if (place < sum->len)
		digit = sum->a[place] - '0' + mul;
	else
		digit = mul;
	ftbi_set_digit(sum, place, (digit % 10) + '0');
	digit /= 10;
	if (digit)
		add_to_nplace(sum, digit, place + 1);
}

t_ftbi		*ftbi_mul(const t_ftbi *a, const t_ftbi *b)
{
	t_ftbi	*sum;
	int		mul;
	size_t	i;
	size_t	j;

	if (a == NULL || b == NULL)
		return (NULL);
	sum = ftbi_new_llong(0);
	if (ftbi_is_zero(a) || ftbi_is_zero(b))
		return (sum);
	i = 0;
	while (i < a->len)
	{
		j = 0;
		while (j < b->len)
		{
			mul = (a->a[i] - '0') * (b->a[j] - '0');
			add_to_nplace(sum, mul, i + j);
			j++;
		}
		i++;
	}
	sum->neg = a->neg ^ b->neg;
	return (sum);
}

t_ftbi		*ftbi_mulpow10(const t_ftbi *a, size_t pow)
{
	t_ftbi	*r;
	size_t	i;

	i = 0;
	r = ftbi_new_llong(0);
	while (i < a->len)
	{
		if (ftbi_set_digit(r, i + pow, a->a[i]) < 0)
			return (NULL);
		i++;
	}
	r->neg = a->neg;
	return (r);
}
