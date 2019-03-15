/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_cond_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:59:06 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 00:10:49 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"

int			ftbi_lt(const t_ftbi *a, const t_ftbi *b)
{
	if (a == NULL || b == NULL)
		return (FTBI_ERR_NULLARG);
	if (ftbi_eq(a, b) == 1)
		return (0);
	return (1 - ftbi_gt(a, b));
}

int			ftbi_gteq(const t_ftbi *a, const t_ftbi *b)
{
	if (a == NULL || b == NULL)
		return (FTBI_ERR_NULLARG);
	if (ftbi_eq(a, b))
		return (1);
	return (ftbi_gt(a, b));
}

int			ftbi_lteq(const t_ftbi *a, const t_ftbi *b)
{
	if (a == NULL || b == NULL)
		return (FTBI_ERR_NULLARG);
	if (ftbi_eq(a, b))
		return (1);
	return (1 - ftbi_gt(a, b));
}
