/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:44:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/13 19:50:11 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftbi.h"

static t_ftbi	*ftbi_new_zero(void)
{
	t_ftbi	*bi;

	bi = (t_ftbi *)malloc(sizeof(t_ftbi));
	if (bi == NULL)
		return (NULL);
	bi->a = (char *)malloc(FTBI_ALLOCATION_UNIT + 1);
	if (bi->a == NULL)
	{
		free(bi);
		return (NULL);
	}
	bi->a[0] = '0';
	bi->a[1] = '\0';
	bi->alloc_size = FTBI_ALLOCATION_UNIT;
	bi->neg = 0;
	bi->len = 1;
	return (bi);
}

static char		*local_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int		new_negative(long long *val, t_ftbi *bi)
{
	bi->neg = 1;
	if ((*(unsigned long long *)val) == FTBI_LLMIN)
	{
		if (ftbi_realloc(bi, 19) > 0)
		{
			local_strcpy(bi->a, "8085774586302733229");
			bi->len = 19;
		}
		else
			ftbi_del(&bi);
		return (FTBI_EARLY_RETURN);
	}
	*val = (*val) * -1;
	return (FTBI_OK);
}

t_ftbi			*ftbi_new_llong(long long val)
{
	t_ftbi	*bi;
	size_t	i;

	if ((bi = ftbi_new_zero()) == NULL)
		return (NULL);
	if (val == 0ll)
		return (bi);
	if (val < 0ll && new_negative(&val, bi) == FTBI_EARLY_RETURN)
		return (bi);
	i = 0;
	while (val)
	{
		ftbi_set_digit(bi, i, val % 10 + '0');
		val /= 10;
		i++;
	}
	bi->len = i;
	return (bi);
}

t_ftbi			*ftbi_new_ullong(unsigned long long val)
{
	t_ftbi	*bi;
	size_t	i;

	bi = ftbi_new_zero();
	if (val == 0ull)
		return (bi);
	i = 0;
	while (val)
	{
		ftbi_set_digit(bi, i, val % 10 + '0');
		val /= 10;
		i++;
	}
	bi->len = i - 1;
	return (bi);
}
