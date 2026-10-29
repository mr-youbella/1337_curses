# ft_printf

Formatted output in C, built around variadic arguments and small conversion functions.

[Repository](../README.md) · **C** · **Score: 110**

## Supported formatting

`ft_printf` writes to standard output and returns a character count. The mandatory parser handles `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`. The conversion helpers in [LBF/](LBF/) handle strings, signed and unsigned decimal values, hexadecimal values, and pointer addresses.

The bonus parser in [BNS/](BNS/) adds `+` and space prefixes for signed decimal conversions, and `#` prefixes for hexadecimal conversions. Width, precision, zero padding, and left alignment are not implemented.

## Build and use

Make and a C compiler are sufficient. Both variants produce `libftprintf.a` with `-Wall -Wextra -Werror`.

```bash
make
```

To select the bonus implementation from a clean archive:

```bash
make fclean
make bonus
```

A caller can include `ft_printf.h` and use the function directly:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("answer: %d\n", 42);
    return (0);
}
```

Save this as `example.c` in this directory, then compile and run it:

```bash
cc -Wall -Wextra -Werror -I. example.c libftprintf.a -o example
./example
```

The formatted line is `answer: 42`.

## Inside the implementation

The parser advances through the format string, dispatches each conversion using `va_arg`, and adds the helpers' output lengths to the return value. Before parsing, it checks standard output with a zero-byte `write`. This is a deliberately limited formatter rather than a complete replacement for the C library's `printf`.

**Apple Silicon note:** conversion helpers receive `va_list` by value. On the arm64 macOS ABI, advancing that copy does not advance the caller's argument cursor: a check of `ft_printf("%d %d", 42, 7)` produced `42 42`. Multi-conversion calls need that implementation issue resolved on this platform; the example above uses one conversion.

## Checks

No test program is bundled. Compare supported formats with `printf`, including zero, negative integers, a null string, and hexadecimal case. Use the bonus archive when checking `%+d`, `% d`, and `%#x`. Avoid treating unsupported formats as part of the interface.

`make clean`, `make fclean`, and `make re` manage objects, the archive, and rebuilding.

[Project subject](../Subjects/ft_printf.subject.pdf) · [Back to 1337 Curses](../README.md)
