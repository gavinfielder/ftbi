/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:45:04 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/15 18:51:46 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** Add unit tests to this file. Return 1 if fail, 0 if pass.
**
** All functions of the prototype:
**
**     int    foo(void)
**
** will be considered a unit test.
*/


/*
** -----------------------------------------------------------------------------
**                                 Basic Tests
** -----------------------------------------------------------------------------
*/

int make_zero(void) {
	t_ftbi *bi = ftbi_new_llong(0);
	int ret = assert_str(bi->a, "0");
	ftbi_del(&bi); return (ret);}

int make_zero_check_len(void) {
	t_ftbi *bi = ftbi_new_llong(0);
	int ret = assert_size_t(bi->len, 1);
	ftbi_del(&bi); return (ret);}

int make_123(void) {
	t_ftbi *bi = ftbi_new_llong(123);
	int ret = assert_str(bi->a, "321");
	ftbi_del(&bi); return (ret);}

int make_123_check_len(void) {
	t_ftbi *bi = ftbi_new_llong(123);
	int ret = assert_size_t(bi->len, 3);
	ftbi_del(&bi); return (ret);}

int make_neg(void) {
	t_ftbi *bi = ftbi_new_llong(-123);
	int ret = (assert_str(bi->a, "321") | assert_int(bi->neg, 1));
	ftbi_del(&bi); return (ret);}

int make_big(void) {
	t_ftbi *bi = ftbi_new_llong(123456789012);
	int ret = assert_str(bi->a, "210987654321");
	ftbi_del(&bi); return (ret);}

int make_big_check_len(void) {
	t_ftbi *bi = ftbi_new_llong(123456789012);
	int ret = assert_size_t(bi->len, 12);
	ftbi_del(&bi); return (ret);}

int make_big_neg(void) {
	t_ftbi *bi = ftbi_new_llong(-123456789012);
	int ret = (assert_str(bi->a, "210987654321") | assert_int(bi->neg, 1));
	ftbi_del(&bi); return (ret);}

int	make_fromstr_pos(void) {
	t_ftbi *bi = ftbi_new_str("3456");
	int ret = (assert_long_long(ftbi_to_ll(bi), 3456));
	ftbi_del(&bi); return (ret);}

int	make_fromstr_neg(void) {
	t_ftbi *bi = ftbi_new_str("-3456");
	int ret = (assert_long_long(ftbi_to_ll(bi), -3456) | assert_int(bi->neg, 1));
	ftbi_del(&bi); return (ret);}

/*
** -----------------------------------------------------------------------------
**                          Binary Conditional Tests
** -----------------------------------------------------------------------------
*/


//Greater Than involving zero

int gt_0_true(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(0);
	int ret = assert_int(ftbi_gt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_0_false(void) {
	t_ftbi *a = ftbi_new_llong(-123);
	t_ftbi *b = ftbi_new_llong(0);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_0_0_false(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *b = ftbi_new_llong(0);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Greater Than with both positive

int gt_pp_len_true(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(56);
	int ret = assert_int(ftbi_gt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_pp_len_false(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(2756);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_pp_compare_true(void) {
	t_ftbi *a = ftbi_new_llong(623);
	t_ftbi *b = ftbi_new_llong(562);
	int ret = assert_int(ftbi_gt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_pp_compare_false(void) {
	t_ftbi *a = ftbi_new_llong(423);
	t_ftbi *b = ftbi_new_llong(562);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_pp_compare3_true(void) {
	t_ftbi *a = ftbi_new_llong(6278);
	t_ftbi *b = ftbi_new_llong(6258);
	int ret = assert_int(ftbi_gt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_pp_compare3_false(void) {
	t_ftbi *a = ftbi_new_llong(6258);
	t_ftbi *b = ftbi_new_llong(6278);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Greater Than with positive, negative

int gt_pn_len_true(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(-56);
	int ret = assert_int(ftbi_gt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_pn_compare_true(void) {
	t_ftbi *a = ftbi_new_llong(623);
	t_ftbi *b = ftbi_new_llong(-562);
	int ret = assert_int(ftbi_gt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_pn_opposite_true(void) {
	t_ftbi *a = ftbi_new_llong(623);
	t_ftbi *b = ftbi_new_llong(-623);
	int ret = assert_int(ftbi_gt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Greater Than with negative, positive

int gt_np_len_false(void) {
	t_ftbi *a = ftbi_new_llong(-123);
	t_ftbi *b = ftbi_new_llong(56);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_np_compare_false(void) {
	t_ftbi *a = ftbi_new_llong(-623);
	t_ftbi *b = ftbi_new_llong(562);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_np_compare_opposite_false(void) {
	t_ftbi *a = ftbi_new_llong(-623);
	t_ftbi *b = ftbi_new_llong(623);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Greater Than with both negative

int gt_nn_len_true(void) {
	t_ftbi *a = ftbi_new_llong(-12);
	t_ftbi *b = ftbi_new_llong(-563);
	int ret = assert_int(ftbi_gt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_nn_len_false(void) {
	t_ftbi *a = ftbi_new_llong(-1253);
	t_ftbi *b = ftbi_new_llong(-256);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_nn_compare_true(void) {
	t_ftbi *a = ftbi_new_llong(-423);
	t_ftbi *b = ftbi_new_llong(-562);
	int ret = assert_int(ftbi_gt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_nn_compare3_true(void) {
	t_ftbi *a = ftbi_new_llong(-6238);
	t_ftbi *b = ftbi_new_llong(-6258);
	int ret = assert_int(ftbi_gt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_nn_compare3_false(void) {
	t_ftbi *a = ftbi_new_llong(-6258);
	t_ftbi *b = ftbi_new_llong(-6238);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_nn_compare_eq_false(void) {
	t_ftbi *a = ftbi_new_llong(-123);
	t_ftbi *b = ftbi_new_llong(-123);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Less Than involving zero

int lt_0_false(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(0);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_0_true(void) {
	t_ftbi *a = ftbi_new_llong(-123);
	t_ftbi *b = ftbi_new_llong(0);
	int ret = assert_int(ftbi_lt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_0_0(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *b = ftbi_new_llong(0);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Less Than with both positive

int lt_pp_len_false(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(56);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_pp_len_true(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(2756);
	int ret = assert_int(ftbi_lt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_pp_compare_false(void) {
	t_ftbi *a = ftbi_new_llong(623);
	t_ftbi *b = ftbi_new_llong(562);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_pp_compare_true(void) {
	t_ftbi *a = ftbi_new_llong(423);
	t_ftbi *b = ftbi_new_llong(562);
	int ret = assert_int(ftbi_lt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_pp_compare3_false(void) {
	t_ftbi *a = ftbi_new_llong(6278);
	t_ftbi *b = ftbi_new_llong(6258);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_pp_compare3_true(void) {
	t_ftbi *a = ftbi_new_llong(6258);
	t_ftbi *b = ftbi_new_llong(6278);
	int ret = assert_int(ftbi_lt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Less Than with positive, negative

int lt_pn_len_false(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(-56);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_pn_compare_false(void) {
	t_ftbi *a = ftbi_new_llong(623);
	t_ftbi *b = ftbi_new_llong(-562);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_pn_opposite_false(void) {
	t_ftbi *a = ftbi_new_llong(623);
	t_ftbi *b = ftbi_new_llong(-623);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Less Than with negative, positive

int lt_np_len_true(void) {
	t_ftbi *a = ftbi_new_llong(-123);
	t_ftbi *b = ftbi_new_llong(56);
	int ret = assert_int(ftbi_lt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_np_compare_true(void) {
	t_ftbi *a = ftbi_new_llong(-623);
	t_ftbi *b = ftbi_new_llong(562);
	int ret = assert_int(ftbi_lt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_np_compare_opposite_true(void) {
	t_ftbi *a = ftbi_new_llong(-623);
	t_ftbi *b = ftbi_new_llong(623);
	int ret = assert_int(ftbi_lt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Less Than with both negative

int lt_nn_len_false(void) {
	t_ftbi *a = ftbi_new_llong(-12);
	t_ftbi *b = ftbi_new_llong(-563);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_nn_len_true(void) {
	t_ftbi *a = ftbi_new_llong(-1253);
	t_ftbi *b = ftbi_new_llong(-256);
	int ret = assert_int(ftbi_lt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_nn_compare_true(void) {
	t_ftbi *a = ftbi_new_llong(-623);
	t_ftbi *b = ftbi_new_llong(-562);
	int ret = assert_int(ftbi_lt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_nn_compare_false(void) {
	t_ftbi *a = ftbi_new_llong(-423);
	t_ftbi *b = ftbi_new_llong(-562);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_nn_compare3_false(void) {
	t_ftbi *a = ftbi_new_llong(-6238);
	t_ftbi *b = ftbi_new_llong(-6258);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_nn_compare3_true(void) {
	t_ftbi *a = ftbi_new_llong(-6258);
	t_ftbi *b = ftbi_new_llong(-6238);
	int ret = assert_int(ftbi_lt(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Tests of equal values -- gt, lt, gteq, lteq

int lt_nn_compare_eq(void) {
	t_ftbi *a = ftbi_new_llong(-123);
	t_ftbi *b = ftbi_new_llong(-123);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lt_pp_compare_eq(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(123);
	int ret = assert_int(ftbi_lt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_pp_compare_eq(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(123);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gt_nn_compare_eq(void) {
	t_ftbi *a = ftbi_new_llong(-123);
	t_ftbi *b = ftbi_new_llong(-123);
	int ret = assert_int(ftbi_gt(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int lteq_nn_compare_eq(void) {
	t_ftbi *a = ftbi_new_llong(-123);
	t_ftbi *b = ftbi_new_llong(-123);
	int ret = assert_int(ftbi_lteq(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int gteq_pp_compare_eq(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(123);
	int ret = assert_int(ftbi_gteq(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Equal To

int eq_nn_compare_eq(void) {
	t_ftbi *a = ftbi_new_llong(-123);
	t_ftbi *b = ftbi_new_llong(-123);
	int ret = assert_int(ftbi_eq(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int eq_pp_compare_eq(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(123);
	int ret = assert_int(ftbi_eq(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int eq_00_compare_eq(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *b = ftbi_new_llong(0);
	int ret = assert_int(ftbi_eq(a, b), 1);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Equal To involving zero

int eq_0(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(0);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Equal To with both positive

int eq_pp_len(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(56);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int eq_pp_compare(void) {
	t_ftbi *a = ftbi_new_llong(623);
	t_ftbi *b = ftbi_new_llong(562);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int eq_pp_compare3(void) {
	t_ftbi *a = ftbi_new_llong(6278);
	t_ftbi *b = ftbi_new_llong(6258);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Equal To with positive, negative

int eq_pn_len(void) {
	t_ftbi *a = ftbi_new_llong(123);
	t_ftbi *b = ftbi_new_llong(-56);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int eq_pn_compare(void) {
	t_ftbi *a = ftbi_new_llong(623);
	t_ftbi *b = ftbi_new_llong(-562);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int eq_pn_opposite(void) {
	t_ftbi *a = ftbi_new_llong(623);
	t_ftbi *b = ftbi_new_llong(-623);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Equal To with negative, positive

int eq_np_len(void) {
	t_ftbi *a = ftbi_new_llong(-123);
	t_ftbi *b = ftbi_new_llong(56);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int eq_np_compare(void) {
	t_ftbi *a = ftbi_new_llong(-623);
	t_ftbi *b = ftbi_new_llong(562);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int eq_np_compare_opposite(void) {
	t_ftbi *a = ftbi_new_llong(-623);
	t_ftbi *b = ftbi_new_llong(623);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

//Equal To with both negative

int eq_nn_len(void) {
	t_ftbi *a = ftbi_new_llong(-12);
	t_ftbi *b = ftbi_new_llong(-563);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int eq_nn_compare(void) {
	t_ftbi *a = ftbi_new_llong(-423);
	t_ftbi *b = ftbi_new_llong(-562);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

int eq_nn_compare3(void) {
	t_ftbi *a = ftbi_new_llong(-6238);
	t_ftbi *b = ftbi_new_llong(-6258);
	int ret = assert_int(ftbi_eq(a, b), 0);
	ftbi_del(&a); ftbi_del(&b); return (ret);}

/*
** -----------------------------------------------------------------------------
**                                   ftbi_add
** -----------------------------------------------------------------------------
*/

int add_5_3(void) {
	t_ftbi *a = ftbi_new_llong(5);
	t_ftbi *b = ftbi_new_llong(3);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 8);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_8_7(void) {
	t_ftbi *a = ftbi_new_llong(8);
	t_ftbi *b = ftbi_new_llong(7);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 15);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_23_31(void) {
	t_ftbi *a = ftbi_new_llong(23);
	t_ftbi *b = ftbi_new_llong(31);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 54);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_423_31(void) {
	t_ftbi *a = ftbi_new_llong(423);
	t_ftbi *b = ftbi_new_llong(31);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 454);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_23_431(void) {
	t_ftbi *a = ftbi_new_llong(23);
	t_ftbi *b = ftbi_new_llong(431);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 454);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_48_25(void) {
	t_ftbi *a = ftbi_new_llong(48);
	t_ftbi *b = ftbi_new_llong(25);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 73);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_48_125(void) {
	t_ftbi *a = ftbi_new_llong(48);
	t_ftbi *b = ftbi_new_llong(125);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 173);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_248_25(void) {
	t_ftbi *a = ftbi_new_llong(248);
	t_ftbi *b = ftbi_new_llong(25);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 273);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_68_74(void) {
	t_ftbi *a = ftbi_new_llong(68);
	t_ftbi *b = ftbi_new_llong(74);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 142);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_n68_n74(void) {
	t_ftbi *a = ftbi_new_llong(-68);
	t_ftbi *b = ftbi_new_llong(-74);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -142);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_898_174(void) {
	t_ftbi *a = ftbi_new_llong(898);
	t_ftbi *b = ftbi_new_llong(174);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 1072);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int add_big_big_test1(void) {
	t_ftbi *a = ftbi_new_str("4820648054840603360645462604589480947");
	t_ftbi *b = ftbi_new_str("58815046865005656171305050651350301");
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_str(r->a, "8421380425567676186109065071013649784");
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int add_big_big_test2(void) {
	t_ftbi *a = ftbi_new_str("-10248943022489245975026840012558525452026820258");
	t_ftbi *b = ftbi_new_str("-30248997202556750585026840268425145901587320369540");
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_str(r->a, "89798174393072440773480176810013893297554164295203")
		| assert_int(r->neg, 1);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_103_n18(void) {
	t_ftbi *a = ftbi_new_llong(103);
	t_ftbi *b = ftbi_new_llong(-18);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 85);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_18_n103(void) {
	t_ftbi *a = ftbi_new_llong(18);
	t_ftbi *b = ftbi_new_llong(-103);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -85);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_n103_18(void) {
	t_ftbi *a = ftbi_new_llong(-103);
	t_ftbi *b = ftbi_new_llong(18);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -85);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	add_n18_103(void) {
	t_ftbi *a = ftbi_new_llong(-18);
	t_ftbi *b = ftbi_new_llong(103);
	t_ftbi *r = ftbi_add(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 85);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

/*
** -----------------------------------------------------------------------------
**                                   ftbi_sub
** -----------------------------------------------------------------------------
*/

int sub_5_3(void) {
	t_ftbi *a = ftbi_new_llong(5);
	t_ftbi *b = ftbi_new_llong(3);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 2);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int sub_3_5(void) {
	t_ftbi *a = ftbi_new_llong(3);
	t_ftbi *b = ftbi_new_llong(5);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -2);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int sub_n5_n3(void) {
	t_ftbi *a = ftbi_new_llong(-5);
	t_ftbi *b = ftbi_new_llong(-3);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -2);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int sub_n3_n5(void) {
	t_ftbi *a = ftbi_new_llong(-3);
	t_ftbi *b = ftbi_new_llong(-5);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 2);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int sub_456_321(void) {
	t_ftbi *a = ftbi_new_llong(456);
	t_ftbi *b = ftbi_new_llong(321);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 135);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int sub_n456_n321(void) {
	t_ftbi *a = ftbi_new_llong(-456);
	t_ftbi *b = ftbi_new_llong(-321);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -135);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int sub_321_456(void) {
	t_ftbi *a = ftbi_new_llong(321);
	t_ftbi *b = ftbi_new_llong(456);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -135);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int sub_n321_n456(void) {
	t_ftbi *a = ftbi_new_llong(-321);
	t_ftbi *b = ftbi_new_llong(-456);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 135);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	sub_73_25(void) {
	t_ftbi *a = ftbi_new_llong(73);
	t_ftbi *b = ftbi_new_llong(25);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 48);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	sub_25_73(void) {
	t_ftbi *a = ftbi_new_llong(25);
	t_ftbi *b = ftbi_new_llong(73);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -48);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	sub_103_18(void) {
	t_ftbi *a = ftbi_new_llong(103);
	t_ftbi *b = ftbi_new_llong(18);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_str(r->a, "58");
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	sub_18_103(void) {
	t_ftbi *a = ftbi_new_llong(18);
	t_ftbi *b = ftbi_new_llong(103);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -85);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	sub_big_to_0(void) {
	t_ftbi *a = ftbi_new_str("4492890651715161981674670616540681680658068416510651");
	t_ftbi *b = ftbi_new_str("4492890651715161981674670616540681680658068416510651");
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	sub_ultimate_1(void) {
	t_ftbi *a = ftbi_new_str("4492890651715161981674670616540681680658068416510651");
	t_ftbi *b = ftbi_new_str("4492890651715161981674670616540681680658498720165894");
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_str(r->a, "342556303034") | assert_int(r->neg, 1);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	sub_ultimate_2(void) {
	t_ftbi *a = ftbi_new_str("-8463740001000123");
	t_ftbi *b = ftbi_new_str("-8463740002000456");
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_str(r->a, "3330001") | assert_int(r->neg, 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	sub_898_n174(void) {
	t_ftbi *a = ftbi_new_llong(898);
	t_ftbi *b = ftbi_new_llong(-174);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 1072);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	sub_n898_174(void) {
	t_ftbi *a = ftbi_new_llong(-898);
	t_ftbi *b = ftbi_new_llong(174);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -1072);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	sub_174_n898(void) {
	t_ftbi *a = ftbi_new_llong(174);
	t_ftbi *b = ftbi_new_llong(-898);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 1072);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	sub_n174_898(void) {
	t_ftbi *a = ftbi_new_llong(-174);
	t_ftbi *b = ftbi_new_llong(898);
	t_ftbi *r = ftbi_sub(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -1072);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

/*
** -----------------------------------------------------------------------------
**                                   ftbi_mul
** -----------------------------------------------------------------------------
*/

int	mul_3_2(void) {
	t_ftbi *a = ftbi_new_llong(3);
	t_ftbi *b = ftbi_new_llong(2);
	t_ftbi *r = ftbi_mul(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 6);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	mul_3_n4(void) {
	t_ftbi *a = ftbi_new_llong(3);
	t_ftbi *b = ftbi_new_llong(-4);
	t_ftbi *r = ftbi_mul(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -12);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	mul_n13_4(void) {
	t_ftbi *a = ftbi_new_llong(-13);
	t_ftbi *b = ftbi_new_llong(4);
	t_ftbi *r = ftbi_mul(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -52);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	mul_n13_n17(void) {
	t_ftbi *a = ftbi_new_llong(-13);
	t_ftbi *b = ftbi_new_llong(-17);
	t_ftbi *r = ftbi_mul(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 221);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	mul_0_any(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *b = ftbi_new_llong(-17);
	t_ftbi *r = ftbi_mul(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0) | assert_int(r->neg, 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	mul_any_0(void) {
	t_ftbi *a = ftbi_new_llong(9472);
	t_ftbi *b = ftbi_new_llong(0);
	t_ftbi *r = ftbi_mul(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0) | assert_int(r->neg, 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	mul_some_intermediate_zeros(void) {
	t_ftbi *a = ftbi_new_llong(400004);
	t_ftbi *b = ftbi_new_llong(1000012);
	t_ftbi *r = ftbi_mul(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 400008800048);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int	mul_buncha_nines(void) {
	t_ftbi *a = ftbi_new_llong(-9999);
	t_ftbi *b = ftbi_new_llong(99999);
	t_ftbi *r = ftbi_mul(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -999890001);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mul_ultimate_1(void) {
	t_ftbi *a = ftbi_new_str("24816506859897851650658468765620");
	t_ftbi *b = ftbi_new_str("218065816898651650654654354");
	t_ftbi *r = ftbi_mul(a, b);
	int ret = assert_str(r->a, "0849058316837189257696611987092143457799457164790481361145");
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mul_custom_1(void) {
	t_ftbi *a = ftbi_new_str("11920928955078125");
	t_ftbi *b = ftbi_new_llong(838861);
	t_ftbi *r = ftbi_mul(a, b);
	int ret = assert_str(r->a, "52651019758148320000001");
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

/*
** -----------------------------------------------------------------------------
**                                   ftbi_div2
** -----------------------------------------------------------------------------
*/

int div2_4(void) {
	t_ftbi *a = ftbi_new_llong(4);
	t_ftbi *r = ftbi_div2(a);
	int ret = assert_long_long(ftbi_to_ll(r), 2);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div2_1(void) {
	t_ftbi *a = ftbi_new_llong(1);
	t_ftbi *r = ftbi_div2(a);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div2_5(void) {
	t_ftbi *a = ftbi_new_llong(5);
	t_ftbi *r = ftbi_div2(a);
	int ret = assert_long_long(ftbi_to_ll(r), 2);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div2_0(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *r = ftbi_div2(a);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div2_n62(void) {
	t_ftbi *a = ftbi_new_llong(-62);
	t_ftbi *r = ftbi_div2(a);
	int ret = assert_long_long(ftbi_to_ll(r), -31);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div2_8573(void) {
	t_ftbi *a = ftbi_new_llong(8573);
	t_ftbi *r = ftbi_div2(a);
	int ret = assert_long_long(ftbi_to_ll(r), 4286);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div2_ultimate_1(void) {
	t_ftbi *a = ftbi_new_str("1865065067868465065681065065816503506581435065651653506506546506506");
	t_ftbi *r = ftbi_div2(a);
	int ret = assert_str(r->a, "352352372352357628528235717092357152809235235048235232439335235239");
	ftbi_del(&a); ftbi_del(&r); return (ret);}

/*
** -----------------------------------------------------------------------------
**                       ftbi_mulpow10  and  ftbi_divpow10
** -----------------------------------------------------------------------------
*/

int mul_5e4(void) {
	t_ftbi *a = ftbi_new_llong(5);
	t_ftbi *r = ftbi_mulpow10(a, 4);
	int ret = assert_long_long(ftbi_to_ll(r), 50000);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int mul_486e2(void) {
	t_ftbi *a = ftbi_new_llong(486);
	t_ftbi *r = ftbi_mulpow10(a, 2);
	int ret = assert_long_long(ftbi_to_ll(r), 48600);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int mul_n486e7(void) {
	t_ftbi *a = ftbi_new_llong(-486);
	t_ftbi *r = ftbi_mulpow10(a, 7);
	int ret = assert_long_long(ftbi_to_ll(r), -4860000000);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int mul_n486e0(void) {
	t_ftbi *a = ftbi_new_llong(-486);
	t_ftbi *r = ftbi_mulpow10(a, 0);
	int ret = assert_long_long(ftbi_to_ll(r), -486);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int mul_0e5(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *r = ftbi_mulpow10(a, 5);
	int ret = assert_str(a->a, "0");
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int mul_0e0(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *r = ftbi_mulpow10(a, 0);
	int ret = assert_str(r->a, "0");
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div_5e4_e2(void) {
	t_ftbi *a = ftbi_new_llong(50000);
	t_ftbi *r = ftbi_divpow10(a, 2);
	int ret = assert_long_long(ftbi_to_ll(r), 500);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div_6835_e2(void) {
	t_ftbi *a = ftbi_new_llong(6835);
	t_ftbi *r = ftbi_divpow10(a, 2);
	int ret = assert_long_long(ftbi_to_ll(r), 68);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div_6899_e2(void) {
	t_ftbi *a = ftbi_new_llong(6899);
	t_ftbi *r = ftbi_divpow10(a, 2);
	int ret = assert_long_long(ftbi_to_ll(r), 68);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div_n6899_e3(void) {
	t_ftbi *a = ftbi_new_llong(-6899);
	t_ftbi *r = ftbi_divpow10(a, 3);
	int ret = assert_str(r->a, "6") | assert_int(r->neg, 1);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div_n6899_e0(void) {
	t_ftbi *a = ftbi_new_llong(-6899);
	t_ftbi *r = ftbi_divpow10(a, 0);
	int ret = assert_long_long(ftbi_to_ll(r), -6899);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div_451_e5(void) {
	t_ftbi *a = ftbi_new_llong(451);
	t_ftbi *r = ftbi_divpow10(a, 5);
	int ret = assert_str(r->a, "0") | assert_int(r->neg, 0);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int div_0_e0(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *r = ftbi_divpow10(a, 0);
	int ret = assert_str(r->a, "0") | assert_int(r->neg, 0);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

/*
** -----------------------------------------------------------------------------
**                                   ftbi_div
** -----------------------------------------------------------------------------
*/

int div_8_2(void) {
	t_ftbi *a = ftbi_new_llong(8);
	t_ftbi *b = ftbi_new_llong(2);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 4);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_17_3(void) {
	t_ftbi *a = ftbi_new_llong(17);
	t_ftbi *b = ftbi_new_llong(3);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 5);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_17_17(void) {
	t_ftbi *a = ftbi_new_llong(17);
	t_ftbi *b = ftbi_new_llong(17);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 1);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_15_17(void) {
	t_ftbi *a = ftbi_new_llong(15);
	t_ftbi *b = ftbi_new_llong(17);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_5_17(void) {
	t_ftbi *a = ftbi_new_llong(5);
	t_ftbi *b = ftbi_new_llong(17);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_0_17(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *b = ftbi_new_llong(17);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_0_1(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *b = ftbi_new_llong(1);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_exact_multiple(void) {
	t_ftbi *a = ftbi_new_llong(10591);
	t_ftbi *b = ftbi_new_llong(623);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 17);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_34352_23(void) {
	t_ftbi *a = ftbi_new_llong(34352);
	t_ftbi *b = ftbi_new_llong(23);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 1493);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_n8984_947(void) {
	t_ftbi *a = ftbi_new_llong(-8984);
	t_ftbi *b = ftbi_new_llong(947);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -9);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_9461_n3(void) {
	t_ftbi *a = ftbi_new_llong(9461);
	t_ftbi *b = ftbi_new_llong(-3);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -3153);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_n8457174_n57171(void) {
	t_ftbi *a = ftbi_new_llong(-8457174);
	t_ftbi *b = ftbi_new_llong(-57171);
	t_ftbi *r = ftbi_div(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 147);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int div_by_zero(void) {
	t_ftbi *a = ftbi_new_llong(45);
	t_ftbi *b = ftbi_new_llong(0);
	t_ftbi *r = ftbi_div(a, b);
	int ret = (r != NULL ? 1 : 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}


/*
** -----------------------------------------------------------------------------
**                                   ftbi_mod
** -----------------------------------------------------------------------------
*/

int mod_8_2(void) {
	t_ftbi *a = ftbi_new_llong(8);
	t_ftbi *b = ftbi_new_llong(2);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_17_3(void) {
	t_ftbi *a = ftbi_new_llong(17);
	t_ftbi *b = ftbi_new_llong(3);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 2);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_17_17(void) {
	t_ftbi *a = ftbi_new_llong(17);
	t_ftbi *b = ftbi_new_llong(17);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_15_17(void) {
	t_ftbi *a = ftbi_new_llong(15);
	t_ftbi *b = ftbi_new_llong(17);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 15);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_5_17(void) {
	t_ftbi *a = ftbi_new_llong(5);
	t_ftbi *b = ftbi_new_llong(17);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 5);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_0_17(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *b = ftbi_new_llong(17);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_0_1(void) {
	t_ftbi *a = ftbi_new_llong(0);
	t_ftbi *b = ftbi_new_llong(1);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_exact_multiple(void) {
	t_ftbi *a = ftbi_new_llong(10591);
	t_ftbi *b = ftbi_new_llong(623);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_34352_23(void) {
	t_ftbi *a = ftbi_new_llong(34352);
	t_ftbi *b = ftbi_new_llong(23);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 13);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_n8984_947(void) {
	t_ftbi *a = ftbi_new_llong(-8984);
	t_ftbi *b = ftbi_new_llong(947);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -461);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_9461_n3(void) {
	t_ftbi *a = ftbi_new_llong(9461);
	t_ftbi *b = ftbi_new_llong(-3);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), 2);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_n8457174_n57171(void) {
	t_ftbi *a = ftbi_new_llong(-8457174);
	t_ftbi *b = ftbi_new_llong(-57171);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = assert_long_long(ftbi_to_ll(r), -53037);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

int mod_by_zero(void) {
	t_ftbi *a = ftbi_new_llong(45);
	t_ftbi *b = ftbi_new_llong(0);
	t_ftbi *r = ftbi_mod(a, b);
	int ret = (r != NULL ? 1 : 0);
	ftbi_del(&a); ftbi_del(&b); ftbi_del(&r); return (ret);}

/*
** -----------------------------------------------------------------------------
**                                   ftbi_pow
** -----------------------------------------------------------------------------
*/

int pow_2_3(void) {
	t_ftbi *a = ftbi_new_llong(2);
	t_ftbi *r = ftbi_pow(a, 3);
	int ret = assert_long_long(ftbi_to_ll(r), 8);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int pow_n4_3(void) {
	t_ftbi *a = ftbi_new_llong(-4);
	t_ftbi *r = ftbi_pow(a, 3);
	int ret = assert_long_long(ftbi_to_ll(r), -64);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int pow_3_0(void) {
	t_ftbi *a = ftbi_new_llong(3);
	t_ftbi *r = ftbi_pow(a, 0);
	int ret = assert_long_long(ftbi_to_ll(r), 1);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int pow_3_1(void) {
	t_ftbi *a = ftbi_new_llong(3);
	t_ftbi *r = ftbi_pow(a, 1);
	int ret = assert_long_long(ftbi_to_ll(r), 3);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int pow_3_n1(void) {
	t_ftbi *a = ftbi_new_llong(3);
	t_ftbi *r = ftbi_pow(a, -1);
	int ret = assert_long_long(ftbi_to_ll(r), 0);
	ftbi_del(&a); ftbi_del(&r); return (ret);}

int pow_ultimate_1(void) {
	t_ftbi *a = ftbi_new_llong(7872);
	t_ftbi *r = ftbi_pow(a, 17);
	int ret = assert_str(r->a, "2173884627137906291575416418312492102349954748765514914274014771171");
	ftbi_del(&a); ftbi_del(&r); return (ret);}
















