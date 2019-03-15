/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_new_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:21:12 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/14 13:16:25 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftbi.h"

t_ftbi	*ftbi_new_str(char *str)
{
	t_ftbi	*r;
	size_t	i;
	size_t	len;

	r = ftbi_new_llong(0);
	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < len)
	{
		if (i + 1 == len && str[0] == '-')
			r->neg = 1;
		else
			ftbi_set_digit(r, i, str[len - i - 1]);
		i++;
	}
	return (r);
}

t_ftbi	*ftbi_pow10(size_t pow)
{
	t_ftbi	*r;

	r = ftbi_new_llong(0);
	ftbi_set_digit(r, pow, '1');
	return (r);
}
