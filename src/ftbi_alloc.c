/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:42:22 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 15:13:43 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftbi.h"

static size_t	ftbi_get_alloc_size_needed(size_t i)
{
	size_t	size;

	size = FTBI_ALLOCATION_UNIT;
	while (size <= i)
	{
		size += FTBI_ALLOCATION_UNIT;
	}
	return (size);
}

int				ftbi_realloc(t_ftbi *bi, size_t i)
{
	size_t	new_size;
	char	*new_a;
	size_t	j;

	new_size = ftbi_get_alloc_size_needed(i);
	new_a = (char *)malloc(new_size + 1);
	if (new_a == NULL)
		return (FTBI_ERR_MLCFAIL);
	j = 0;
	while (j <= new_size)
	{
		if (j < bi->alloc_size)
			new_a[j] = bi->a[j];
		else
			new_a[j] = '\0';
		j++;
	}
	free(bi->a);
	bi->a = new_a;
	bi->alloc_size = new_size;
	return (1);
}

t_ftbi			*ftbi_new_alloc(size_t size)
{
	t_ftbi	*bi;
	size_t	i;

	bi = (t_ftbi *)malloc(sizeof(t_ftbi));
	if (bi == NULL)
		return (NULL);
	bi->a = (char *)malloc(size + 1);
	if (bi->a == NULL)
	{
		free(bi);
		return (NULL);
	}
	bi->a[0] = '0';
	i = 0;
	while (++i <= size)
		bi->a[i] = '\0';
	bi->alloc_size = size;
	bi->neg = 0;
	bi->len = 1;
	return (bi);
}

t_ftbi			*ftbi_new_pow10(size_t pow)
{
	t_ftbi	*r;

	r = ftbi_new_llong(1);
	ftbi_repl(&r, ftbi_mulpow10(r, pow));
	return (r);
}
