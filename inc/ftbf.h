/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:50:18 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/16 21:14:46 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTBF_H
# define FTBF_H

# include "libftbi.h"

# define FTBF_ABS(x) ((x) < 0 ? (-x) : (x))

# define FTBF_MBITS_F 23
# define FTBF_MBITS_D 52
# define FTBF_MBITS_LD 64

# define FTBF_BIAS_F 127
# define FTBF_BIAS_D 1023
# define FTBF_BIAS_LD 16382

# define FTBF_NORMAL 0
# define FTBF_POSZERO 1
# define FTBF_NEGZERO 2
# define FTBF_POSINF 3
# define FTBF_NEGINF 4
# define FTBF_NAN 5

typedef unsigned int			t_ui4;
typedef unsigned long			t_ui8;

# define FTBF_MASK_SGN_F(x) ((*((int *)(&x))) & 0x80000000)
# define FTBF_MASK_EXP_F(x) ((*((int *)(&x))) & 0x7F800000)
# define FTBF_MASK_MTS_F(x) (((*((t_ui4 *)(&x))) & 0x007FFFFF) | 0x800000)
# define FTBF_RAW_MASK_MTS_F(x) ((*((t_ui4 *)(&x))) & 0x007FFFFF)
# define FTBF_GET_SGN_F(x) (FTBF_MASK_SGN_F(x) ? 1 : 0)
# define FTBF_GET_EXP_F(x) ((FTBF_MASK_EXP_F(x) >> FTBF_MBITS_F) - FTBF_BIAS_F)

# define FTBFM1 0x000FFFFFFFFFFFFF
# define FTBF_MASK_SGN_D(x) ((*((long *)(&x))) & 0x8000000000000000)
# define FTBF_MASK_EXP_D(x) ((*((long *)(&x))) & 0x7FF0000000000000)
# define FTBF_MASK_MTS_D(x) (((*((t_ui8 *)(&x))) & FTBFM1) | (1ull << 52))
# define FTBF_RAW_MASK_MTS_D(x) ((*((t_ui8 *)(&x))) & FTBFM1)
# define FTBF_GET_SGN_D(x) (FTBF_MASK_SGN_D(x) ? 1 : 0)
# define FTBF_GET_EXP_D(x) ((FTBF_MASK_EXP_D(x) >> FTBF_MBITS_D) - FTBF_BIAS_D)

# define FTBF_MASK_SGN_LD(x) (((short *)(&x))[4] & 0x8000)
# define FTBF_MASK_EXP_LD(x) (((short *)(&x))[4] & 0x7FFF)
# define FTBF_MASK_MTS_LD(x) (*((unsigned long *)(&x)))
# define FTBF_GET_SGN_LD(x) (FTBF_MASK_SGN_LD(x) ? 1 : 0)
# define FTBF_GET_EXP_LD(x) (FTBF_MASK_EXP_LD(x) - FTBF_BIAS_LD)

typedef struct					s_ftbf
{
	t_ftbi						*val;
	int							exp;
	int							special;
}								t_ftbf;

/*
** -----------------------------------------------------------------------------
**                                  Utility
** -----------------------------------------------------------------------------
*/

t_ftbf							*ftbf_round(const t_ftbf *f, int prec);
char							*ftbf_tostr(const t_ftbf *f);
t_ftbf							*ftbf_repl(t_ftbf **into, t_ftbf *value);
t_ftbf							*ftbf_copy(const t_ftbf *f);

/*
** -----------------------------------------------------------------------------
**                        Constructors and Destructors
** -----------------------------------------------------------------------------
*/

t_ftbf							*ftbf_new_float(float f);
t_ftbf							*ftbf_new_double(double f);
t_ftbf							*ftbf_new_ldouble(long double f);
void							ftbf_del(t_ftbf **f);

/*
** -----------------------------------------------------------------------------
**                            Arithmetic Operations
** -----------------------------------------------------------------------------
*/

/*
** -----------------------------------------------------------------------------
**             Helper functions (do not call outside of intended use)
** -----------------------------------------------------------------------------
*/

t_ftbf							*ftbf_check_special_float(float f);
t_ftbf							*ftbf_check_special_double(double f);
t_ftbf							*ftbf_check_special_ldouble(long double f);
t_ftbf							*ftbf_shiftdiv10(const t_ftbf *f, int pow);
t_ftbf							*ftbf_shiftmul10(const t_ftbf *f, int pow);

#endif
