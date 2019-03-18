/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_tostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:21:35 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/17 20:37:53 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftbi.h"

char		*ftbi_tostr(t_ftbi *bi)
{
	char	*ret;
	size_t	i;

	FTBI_MALGRD(bi);
	FTBI_MALGRD(ret = (char *)malloc(bi->len + 1 + bi->neg));
	ret[bi->len + bi->neg] = '\0';
	if (bi->neg)
		ret[0] = '-';
	i = (size_t)(bi->neg);
	while (i < bi->len + bi->neg)
	{
		ret[i] = bi->a[bi->len - (i - bi->neg) - 1];
		i++;
	}
	return (ret);
}
