/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_set_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:27:10 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 14:17:07 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"

int			ftbi_set_digit(t_ftbi *bi, size_t i, char to)
{
	int		ret_error;
	if (i >= bi->alloc_size && (ret_error = ftbi_realloc(bi, i)) < 0)
		return (ret_error);
	bi->a[i] = to;
	if (i >= bi->len)
		bi->a[i + 1] = '\0';
	while (i-- > 0)
	{
		if (bi->a[i] == '\0')
			bi->a[i] = '0';
	}
	bi->len = ftbi_strlen(bi->a);
	return (FTBI_OK);
}
