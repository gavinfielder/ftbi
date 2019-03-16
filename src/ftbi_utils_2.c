/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:26:07 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/15 00:02:41 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftbi.h"

t_ftbi				*ftbi_repl(t_ftbi **into, t_ftbi *value)
{
	ftbi_del(into);
	*into = value;
	return (value);
}

t_ftbi				*ftbi_del_and_ret_null(int num_args, ...)
{
	va_list		args;
	t_ftbi		**current;
	int			i;

	va_start(args, num_args);
	i = 0;
	while (i < num_args)
	{
		current = va_arg(args, t_ftbi **);
		ftbi_del(current);
		i++;
	}
	va_end(args);
	return (NULL);
}

void				ftbi_swap(t_ftbi **a, t_ftbi **b)
{
	t_ftbi *tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
