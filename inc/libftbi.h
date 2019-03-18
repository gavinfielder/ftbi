/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftbi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:20:10 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/17 20:22:38 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTBI_H
# define LIBFTBI_H

# include <stddef.h>

# define FTBI_ALLOCATION_UNIT 32

# define FTBI_LLMIN 0x8000000000000000ll

# define FTBI_ERR_MLCFAIL -1
# define FTBI_ERR_NULLARG -2
# define FTBI_ERR_GENERAL -3
# define FTBI_OK 1
# define FTBI_EARLY_RETURN 8

# define FTBI_MALGRD(x) if ((x) == NULL) return NULL
# define FTBI_MALGRD2(x,y) if ((x) == NULL || (y) == NULL) return NULL

typedef struct		s_ftbi
{
	char			*a;
	size_t			alloc_size;
	size_t			len;
	int				neg;
}					t_ftbi;

/*
** -----------------------------------------------------------------------------
**                                Basic Utility
** -----------------------------------------------------------------------------
*/

size_t				ftbi_strlen(const char *str);
t_ftbi				*ftbi_copy(const t_ftbi *tocopy);
void				ftbi_trim_leading_zeros(t_ftbi *bi);
int					ftbi_is_zero(const t_ftbi *bi);
int					ftbi_is_unity(const t_ftbi *bi);

t_ftbi				*ftbi_repl(t_ftbi **into, t_ftbi *value);
t_ftbi				*ftbi_del_and_ret_null(int num_args, ...);
void				ftbi_swap(t_ftbi **a, t_ftbi **b);

char				*ftbi_tostr(t_ftbi *bi);

/*
** -----------------------------------------------------------------------------
**                Constructors, destructors, and memory management
** -----------------------------------------------------------------------------
*/

int					ftbi_realloc(t_ftbi *bi, size_t i);
t_ftbi				*ftbi_new_alloc(size_t size);
t_ftbi				*ftbi_new_pow10(size_t pow);
int					ftbi_set_digit(t_ftbi *bi, size_t i, char to);
t_ftbi				*ftbi_new_llong(long long val);
t_ftbi				*ftbi_new_ullong(unsigned long long val);
t_ftbi				*ftbi_new_str(char *str);
void				ftbi_del(t_ftbi **bi);
t_ftbi				*ftbi_new_pow(int base, int exp);

/*
** -----------------------------------------------------------------------------
**                               Logical Operators
** -----------------------------------------------------------------------------
*/

int					ftbi_eq(const t_ftbi *a, const t_ftbi *b);
int					ftbi_gt(const t_ftbi *a, const t_ftbi *b);
int					ftbi_lt(const t_ftbi *a, const t_ftbi *b);
int					ftbi_gteq(const t_ftbi *a, const t_ftbi *b);
int					ftbi_lteq(const t_ftbi *a, const t_ftbi *b);

/*
** -----------------------------------------------------------------------------
**                              Arithmetic Operators
** -----------------------------------------------------------------------------
*/

t_ftbi				*ftbi_neg(const t_ftbi *a);
t_ftbi				*ftbi_add(const t_ftbi *a, const t_ftbi *b);
t_ftbi				*ftbi_sub(const t_ftbi *a, const t_ftbi *b);
t_ftbi				*ftbi_mul(const t_ftbi *a, const t_ftbi *b);
t_ftbi				*ftbi_mulpow10(const t_ftbi *a, size_t pow);
t_ftbi				*ftbi_div(const t_ftbi *a, const t_ftbi *b);
t_ftbi				*ftbi_divmod(const t_ftbi *a, const t_ftbi *b,
						t_ftbi **mod);
t_ftbi				*ftbi_div2(const t_ftbi *a);
t_ftbi				*ftbi_divpow10(const t_ftbi *a, size_t pow);
t_ftbi				*ftbi_mod(const t_ftbi *a, const t_ftbi *b);
t_ftbi				*ftbi_pow(const t_ftbi *a, int exp);

/*
** -----------------------------------------------------------------------------
**        Helper Functions (do not use outside of their specific purpose)
** -----------------------------------------------------------------------------
*/

t_ftbi				*ftbi_div_work(t_ftbi *num, t_ftbi *den, t_ftbi **mod);

#endif
