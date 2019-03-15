/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbi_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:07:36 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/13 18:58:06 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftbi.h"

void	ftbi_del(t_ftbi **bi)
{
	if (bi == NULL || *bi == NULL)
		return ;
	if ((*bi)->a != NULL)
		free((*bi)->a);
	free(*bi);
	*bi = NULL;
}
