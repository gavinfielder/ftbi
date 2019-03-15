/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:32:43 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 12:40:37 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"
#include <stddef.h>
#include <stdlib.h>

size_t	ftbi_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

t_ftbi	*ftbi_copy(const t_ftbi *tocopy)
{
	t_ftbi	*r;
	size_t	i;

	r = ftbi_new_llong(0);
	i = 0;
	while (i < tocopy->len)
	{
		ftbi_set_digit(r, i, tocopy->a[i]);
		i++;
	}
	r->neg = tocopy->neg;
	return (r);
}

void	ftbi_trim_leading_zeros(t_ftbi *bi)
{
	while (bi->len > 1 && bi->a[bi->len - 1] == '0')
	{
		bi->a[bi->len - 1] = '\0';
		bi->len = bi->len - 1;
	}
}

int		ftbi_is_zero(const t_ftbi *bi)
{
	return (bi->len == 1 && bi->a[0] == '0');
}

int		ftbi_is_unity(const t_ftbi *bi)
{
	return (bi->len == 1 && bi->a[0] == '1');
}
