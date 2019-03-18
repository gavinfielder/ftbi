/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_tostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:21:35 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/17 20:25:50 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftbi.h"

char		*ftbi_tostr(t_ftbi *bi)
{
	char	*ret;
	size_t	i;

	FTBI_MALGRD(ret = (char *)malloc(bi->len + 1));
	ret[bi->len] = '\0';
	i = 0;
	while (i < bi->len)
	{
		ret[i] = bi->a[bi->len - i - 1];
		i++;
	}
	return (ret);
}
