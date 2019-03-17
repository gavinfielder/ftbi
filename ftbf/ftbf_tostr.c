/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbf_tostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:54:29 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/16 20:09:53 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftbf.h"

static char	*ftbf_tostr_less_than_one(const t_ftbf *f)
{
	int		i;
	int		j;
	char	*r;

	FTBI_MALGRD(r = (char *)malloc(3 - f->exp + f->val->neg));
	j = 0;
	if (f->val->neg)
		r[j++] = '-';
	r[j++] = '0';
	r[j++] = '.';
	i = -1;
	while (++i < (-(f->exp) - (int)(f->val->len)))
		r[j++] = '0';
	i = -1;
	while (++i < (int)(f->val->len))
		r[j++] = *(f->val->a + f->val->len - i - 1);
	r[j] = '\0';
	return (r);
}

static char	*ftbf_tostr_pos_exp(const t_ftbf *f)
{
	int		i;
	int		j;
	char	*r;

	FTBI_MALGRD(r = (char *)malloc(2 + f->val->len + f->val->neg + f->exp));
	j = 0;
	if (f->val->neg)
		r[j++] = '-';
	i = 0;
	while (i < (int)(f->val->len))
		r[j++] = *(f->val->a + f->val->len - i++ - 1);
	i = -1;
	while (++i < f->exp)
		r[j++] = '0';
	r[j] = '\0';
	return (r);
}

static char	*local_strdup(const char *str)
{
	char	*r;
	int		len;
	int		i;

	len = 0;
	while (str[len])
		len++;
	r = (char *)malloc((sizeof(char) * (len + 1)));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		r[i] = str[i];
		i++;
	}
	return (r);
}

static char	*ftbf_tostr_special(const t_ftbf *f)
{
	if (f->special == FTBF_POSINF)
		return (local_strdup("inf"));
	else if (f->special == FTBF_NEGINF)
		return (local_strdup("-inf"));
	else if (f->special == FTBF_NAN)
		return (local_strdup("nan"));
	return (local_strdup("[ftbf_tostr_special: error]"));
}

char		*ftbf_tostr(const t_ftbf *f)
{
	int		i;
	int		j;
	char	*r;

	FTBI_MALGRD(f);
	if (f->special && f->special != FTBF_POSZERO && f->special != FTBF_NEGZERO)
		return (ftbf_tostr_special(f));
	if ((int)(f->val->len) <= -(f->exp))
		return (ftbf_tostr_less_than_one(f));
	if (f->exp >= 0)
		return (ftbf_tostr_pos_exp(f));
	FTBI_MALGRD(r = (char *)malloc(2 + f->val->len + f->val->neg));
	j = 0;
	if (f->val->neg)
		r[j++] = '-';
	i = 0;
	while (i < ((int)(f->val->len) + f->exp))
		r[j++] = *(f->val->a + f->val->len - i++ - 1);
	r[j++] = '.';
	while (i < (int)(f->val->len))
		r[j++] = *(f->val->a + f->val->len - i++ - 1);
	r[j] = '\0';
	return (r);
}
