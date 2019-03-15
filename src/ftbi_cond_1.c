/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_cond_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:58:53 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 00:10:13 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"

int			ftbi_eq(const t_ftbi *a, const t_ftbi *b)
{
	size_t	i;

	if (a == NULL || b == NULL)
		return (FTBI_ERR_NULLARG);
	if (a->neg != b->neg || a->len != b->len)
		return (0);
	i = 0;
	while (i < a->len)
	{
		if (a->a[i] != b->a[i])
			return (0);
		i++;
	}
	return (1);
}

static int	compare_a_gt(const t_ftbi *a, const t_ftbi *b)
{
	size_t	i;

	i = a->len;
	while (i-- > 0)
	{
		if (a->a[i] > b->a[i])
			return (2);
		if (a->a[i] < b->a[i])
			return (0);
	}
	return (1);
}

int			ftbi_gt(const t_ftbi *a, const t_ftbi *b)
{
	if (a == NULL || b == NULL)
		return (FTBI_ERR_NULLARG);
	if (a->neg && !(b->neg))
		return (0);
	if (!(a->neg) && b->neg)
		return (1);
	if (a->neg)
	{
		if (a->len > b->len)
			return (0);
		if (b->len > a->len)
			return (1);
		return ((2 - compare_a_gt(a, b)) / 2);
	}
	else
	{
		if (a->len > b->len)
			return (1);
		if (b->len > a->len)
			return (0);
		return (compare_a_gt(a, b) / 2);
	}
}
