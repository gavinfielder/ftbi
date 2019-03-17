/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbf_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:01:27 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/16 20:18:40 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftbf.h"

t_ftbf		*ftbf_repl(t_ftbf **into, t_ftbf *value)
{
	ftbf_del(into);
	*into = value;
	return (value);
}

t_ftbf		*ftbf_copy(const t_ftbf *f)
{
	t_ftbf	*r;

	r = (t_ftbf *)malloc(sizeof(t_ftbf));
	r->val = ftbi_copy(f->val);
	r->exp = f->exp;
	r->special = f->special;
	return (r);
}
