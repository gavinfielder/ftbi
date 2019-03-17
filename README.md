# 42 Big Integers (ftbi)
### (and 42 Big Floats (ftbf))

`t_ftbi` is a structure that can hold any size integer within (-inf, inf). It stores decimal digits in a string, with the lower power digits at lower indices and the higher power digits at higher indices (the 'number' is stored in reverse).   

`t_ftbf` is a structure that holds a floating point number at arbitrary precision. It does this by using a `t_ftbi` and a power 10 exponent. It can also hold special values of binary floating point--both positive and negative zero, positive and negative infinity, and NaN. Conversions are provided from float, double, and long double.   

## FTBI Functions

### Constructors

- `t_ftbi* ftbi_new_llong(long long val)`
- `t_ftbi* ftbi_new_ullong(unsigned long long val)`
- `t_ftbi* ftbi_new_str(char *str)`
- `t_ftbi* ftbi_new_pow10(size_t pow)`
- `t_ftbi* ftbi_new_pow(int base, int exp)`

### Conditional "Operators"

All the functions here take two `const t_ftbi *` as arguments and return 1 for true, 0 for false.  

- `ftbi_eq`
- `ftbi_gt`
- `ftbi_lt`
- `ftbi_gteq`
- `ftbi_lteq`

### Arithmetic Operators

All the functions here take two `const t_ftbi *` as arguments and return the result of the requested arithmetic operation as a **newly malloc'd** `t_ftbi *`.  

- `ftbi_add`
- `ftbi_sub`
- `ftbi_mul`
- `ftbi_div`
- `ftbi_mod`

### Other Math Functions

All the functions here return a **newly malloc'd** `t_fbi *`.

- `ftbi_neg(const t_ftbi *a)` returns the negative of `a`.
- `ftbi_mulpow10(const t_ftbi *a, size_t pow)` returns `a` * 10^pow.
- `ftbi_divmod(const t_ftbi *a, const t_ftbi *b, t_ftbi **mod)` returns both the quotient and the modulus from the division operation.
- `ftbi_div2(const t_ftbi *a)` returns `a`/2.
- `ftbi_divpow10(const t_ftbi *a, size_t pow)` returns `a` * 10^(-pow).
- `ftbi_pow(const t_ftbi *a, int exp)` returns `a`^exp.

### Destructors

- `ftbi_del(t_ftbi **bi)`

### Utility

- `ftbi_copy(const t_ftbi *tocopy)` returns a copy of `tocopy`.
- `ftbi_is_zero(const t_ftbi *bi)` returns 1 if `bi` is 0 and 0 otherwise.
- `ftbi_is_unity(const t_ftbi *bi)` returns 1 if `bi` is 1 and 0 otherwise.
- `ftbi_repl(t_ftbi **into, t_ftbi *value)` deletes the ftbi currently in the first argument's memory space and replaces it with the new ftbi supplied. This also enables emulating x += y in code.   
- `ftbi_swap(t_ftbi **a, t_ftbi **b)` swaps two large integers.  

## FTBF Functions

## Functions
### Constructors (Binary FP to ftbf conversions)

- `ftbf_new_float(float f)` converts to ftbf from float.
- `ftbf_new_double(double f)` converts to ftbf from double.
- `ftbf_new_ldouble(long double f)` converts to ftbf from long double.

### Destructors

- `ftbf_del(t_ftbf **f)`

### Utility

- `t_ftbf *ftbf_round(const t_ftbf *f, int prec)` returns a rounded version of f, to `prec` dplaces after the decimal. You can also use negative numbers in `prec` to round to the corresponding positive powers of 10. This function will force trailing zeros if `prec` is less than (precision is higher) than the existing exponent.  
- `t_ftbf *ftbf_copy(const t_ftbf *f)` returns a copy of f.  
- `t_ftbf *ftbf_repl(t_ftbf **f, t_ftbf *value)` deletes the ftbf currently in the first argument's memory space and replaces it with the new ftbf supplied.  
- `char *ftbf_tostr(const t_ftbf *f)` returns a newly malloc'd string containing the ascii representation of the ftbf.  

## Credits

All code is written by me.
