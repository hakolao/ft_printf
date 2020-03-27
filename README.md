# Printf
Printf from scratch with pure c.

Only following library functions allowed, the rest is from scratch.
- `malloc`
- `free`
- `exit`
- The functions of man 3 `stdarg`

## Usage
See e.g: [printf reference](http://www.cplusplus.com/reference/cstdio/printf/)
```
ft_printf("%[sub_specs][spec]", [variable_per_spec],+);
```

## Handles

### Specs:
```
diuUoxX
fFeE
csp%
b for binary where first bit = sign
```

### Sub specs:
```
-+ #0
hhhllljztL
*0-9+.*0-9+
```

This library includes:
- `ft_printf`
- `ft_sprintf`
- `ft_dprintf`

Since others have written such extensive tests, I've just ensured this passes all
[42FileChecker](https://github.com/jgigault/42FileChecker) checks, and then some.
