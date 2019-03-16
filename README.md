# 42 Big Integers (ftbi)

I created this library in order to do exact-precision floating point to ascii, but the underlying capabilities (and the capability I've already thoroughly tested) is doing math with arbitrary size integers, "big integers".

`t_ftbi` is a structure that can hold any size integer within (-inf, inf). It stores decimal digits in a string, with the lower power digits at lower indices and the higher power digits at higher indices (the 'number' is stored in reverse).   

## Functions

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

## 42 Big Floats (ftbf)

I added a representation of arbitrary precision floating point built on top of ftbi. No floating point math is supported, and I'm still in the process of testing this module, but so far it seems like it can convert binary floating point to decimal with exact precision.   

### Functions

- `ftbf_new_float(float f)`
- `ftbf_new_double(double f)`
- `ftbf_new_ldouble(long double f)`
- `ftbf_printf(t_ftbf *f)`
- `ftbf_del(t_ftbf **f)`

## Credits

All code is written by me.
