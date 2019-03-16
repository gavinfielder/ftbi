/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbf_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:31:29 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/15 20:39:59 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftbf.h"

static void		ftbf_print_neg_exp(t_ftbf *f)
{
	int		i;

	write(1, "0.", 2);
	i = 0;
	while (i < (f->exp - (int)(f->val->len)))
	{
		write(1, "0", 1);
		i++;
	}
	i = 0;
	while (i < (int)(f->val->len))
	{
		write(1, f->val->a + f->val->len - i - 1, 1);
		i++;
	}
}

void			ftbf_print(t_ftbf *f)
{
	int		i;

	if (f == NULL)
		return ;
	if (f->val->neg)
		write(1, "-", 1);
	if ((int)(f->val->len) <= f->exp)
	{
		ftbf_print_neg_exp(f);
		return ;
	}
	i = 0;
	while (i < ((int)(f->val->len) - f->exp))
		write(1, f->val->a + f->val->len - i++ - 1, 1);
	write(1, ".", 1);
	while (i < (int)(f->exp))
		write(1, f->val->a + f->val->len - i++ - 1, 1);
}
